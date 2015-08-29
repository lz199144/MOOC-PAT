#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXNUM 100000000
using namespace std;

struct node
{
	int i;  //用来标记次序
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
	// earlist 最早完成时间
	int *earlist = new int[n];
	// latest 最晚完成时间
	int *latest = new int[n];
	// Indegree 入度
	int *Indegree = new int[n];
	// Outdegree 出度
	int *Outdegree = new int[n];
	// 初始化
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
	// 将所有入度为0的点放入队列中
	for (int V = 1; V<n; V++)
		if (Indegree[V] == 0)
			Q.push(V);
	// 记录有多少个点，用来判断是否有回路
	int cnt = 0;
	// 正向求最早完成时间
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
	// 判断是否有环
	if (++cnt != n)
	{
		cout << "0" << endl;
		return 0;
	}
	// 反向求最晚完成时间，出度为0的结点就是终点了
	for (int V = 1; V<n; V++)
		if (Outdegree[V] == 0)
			Q.push(V);
	// 将最后一个结点的earlist赋值给latest
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
	// 求每个活动的e[i]和l[i]
	int *e = new int[m];
	int *l = new int[m];
	fill(e, e + m, 0);
	fill(l, l + m, 0);
	// 将路径存储在vector容器里
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
	// 为了应付那个奇怪的输出，需要对容器排序
	sort(route.begin(), route.end());
	// 临时存储路径，用来反序输出
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
	// 将剩余元素依次输出
	for (int i = 0; i<routeTemp.size(); i++)
	{
		cout << routeTemp[i].s << "->" << routeTemp[i].e << endl;
	}
	return 0;
}