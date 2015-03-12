#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int s;
	int e;
	int l;
	node(int a, int b, int c) :s(a), e(b), l(c) {}
};

int cmp(const node &a, const node &b)
{
	return a.e < b.e;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int *earlist = new int[n];
	int *Indegree = new int[n];

	for (int i = 0; i<n; i++)
	{
		Indegree[i] = 0;
		earlist[i] = 0;
	}

	vector<node> vec;

	for (int i = 0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Indegree[b] ++;
		vec.push_back(node(a, b, c));
	}

	sort(vec.begin(), vec.end(), cmp);

	queue<int> Q;

	for (int V = 0; V<n; V++)
		if (Indegree[V] == 0)
			Q.push(V);

	int cnt = 0;

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

	if (cnt != n)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << *max_element(earlist, earlist + n) << endl;
	}
	return 0;
}