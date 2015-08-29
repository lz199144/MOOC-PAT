#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXNUM 100000000
using namespace std;

struct node
{
	int i;  //������Ǵ���
	int s;
	int e;
	int l;
	node(int ii, int a, int b, int c) :i(ii), s(a), e(b), l(c) {}
};

int cmp(const node &a, const node &b)
{
	return a.e < b.e;
}

int cmpForRoute(const node &a, const node &b)
{
	if (a.s != b.s)
		return a.s < b.s;
	else
		return a.i > b.i;
}

int main()
{
	int n, m;
	cin >> n >> m;
	n++;
	// earlist �������ʱ��
	int *earlist = new int[n];
	// latest �������ʱ��
	int *latest = new int[n];
	// Indegree ���
	int *Indegree = new int[n];
	// Outdegree ����
	int *Outdegree = new int[n];
	// ��ʼ��
	for (int i = 0; i<n; i++)
	{
		Indegree[i] = 0;
		Outdegree[i] = 0;
		earlist[i] = 0;
		latest[i] = MAXNUM;
	}

	vector<node> vec;

	for (int i = 0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Outdegree[a] ++;
		Indegree[b] ++;
		vec.push_back(node(i, a, b, c));
	}

	sort(vec.begin(), vec.end(), cmp);

	queue<int> Q;
	// ���������Ϊ0�ĵ���������
	for (int V = 1; V<n; V++)
		if (Indegree[V] == 0)
			Q.push(V);
	// ��¼�ж��ٸ��㣬�����ж��Ƿ��л�·
	int cnt = 0;
	// �������������ʱ��
	while (Q.size() != 0)
	{
		int V = Q.front();
		Q.pop();
		cnt++;
		for (int i = 0; i<m; i++)
		{
			if (vec[i].s == V)
			{
				int W = vec[i].e;
				earlist[W] = max(earlist[W], earlist[V] + vec[i].l);
				if (--Indegree[W] == 0)
					Q.push(W);
			}
		}
	}
	// �ж��Ƿ��л�
	if (++cnt != n)
	{
		cout << "0" << endl;
		return 0;
	}
	// �������������ʱ�䣬����Ϊ0�Ľ������յ���
	for (int V = 1; V<n; V++)
		if (Outdegree[V] == 0)
			Q.push(V);
	// �����һ������earlist��ֵ��latest
	int maxNumber = *max_element(earlist + 1, earlist + n);
	cout << maxNumber << endl;
	fill(latest + 1, latest + n, maxNumber);
	while (Q.size() != 0)
	{
		int W = Q.front();
		Q.pop();
		cnt++;
		for (int i = 0; i<m; i++)
		{
			if (vec[i].e == W)
			{
				int V = vec[i].s;
				latest[V] = min(latest[V], latest[W] - vec[i].l);
				if (--Outdegree[V] == 0)
					Q.push(V);
			}
		}
	}
	// ��ÿ�����e[i]��l[i]
	int *e = new int[m];
	int *l = new int[m];
	fill(e, e + m, 0);
	fill(l, l + m, 0);
	// ��·���洢��vector������
	typedef pair<int, int> PAIR;
	vector<PAIR> route;
	for (int i = 0; i<m; i++)
	{
		int j = vec[i].s;
		int k = vec[i].e;
		e[i] = earlist[j];
		l[i] = latest[k] - vec[i].l;
		if (e[i] == l[i])
		{
			route.push_back(PAIR(j, k));
		}
	}
	// Ϊ��Ӧ���Ǹ���ֵ��������Ҫ����������
	sort(route.begin(), route.end());
	// ��ʱ�洢·���������������
	vector<node> routeTemp;
	int lastNum;
	int flag = true;
	for (int i = 0; i<route.size(); i++)
	{
		int j = route[i].first;
		int k = route[i].second;
		if (flag == true)
		{
			flag = false;
			lastNum = j;

			for (int icount = 0; icount<m; icount++)
			{
				if (vec[icount].s == j && vec[icount].e == k)
				{
					routeTemp.push_back(vec[icount]);
					break;
				}
			}
		}
		else if (flag == false && j != lastNum)
		{
			sort(routeTemp.begin(), routeTemp.end(), cmpForRoute);
			for (int i = 0; i<routeTemp.size(); i++)
			{
				cout << routeTemp[i].s << "->" << routeTemp[i].e << endl;
			}
			routeTemp.clear();
			for (int icount = 0; icount<m; icount++)
			{
				if (vec[icount].s == j && vec[icount].e == k)
				{
					routeTemp.push_back(vec[icount]);
					break;
				}
			}
			lastNum = j;
		}
		else if (flag == false && j == lastNum)
		{
			for (int icount = 0; icount<m; icount++)
			{
				if (vec[icount].s == j && vec[icount].e == k)
				{
					routeTemp.push_back(vec[icount]);
					break;
				}
			}
		}
	}
	// ��ʣ��Ԫ���������
	for (int i = 0; i<routeTemp.size(); i++)
	{
		cout << routeTemp[i].s << "->" << routeTemp[i].e << endl;
	}
	return 0;
}