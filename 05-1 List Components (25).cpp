#include <iostream>
#include <vector>
#include <queue>
#define MAX 12
using namespace std;

int vis[MAX];
int m[MAX][MAX];
int n,e;
vector<int> path;
queue<int> q;
void _print()
{
	cout<<"{ "<<path[0];
	for(int j=1;j<path.size();j++)
	{
		cout<<' '<<path[j];
	}
	cout<<" }"<<endl;
	path.clear();
}
void DFS(int v)
{
	vis[v]=1;
	path.push_back(v);
	for(int i=0;i<n;i++)
	{
		if(!vis[i]&&m[v][i])
		{
			DFS(i);
		}
	}
}
void BFS(int v)
{
	int tmp;
	vis[v]=1;
	path.push_back(v);
	q.push(v);
	while(!q.empty())
	{
		tmp=q.front();
		for(int i=0;i<n;i++)
		{
			if(!vis[i]&&m[tmp][i])
			{
				BFS(i);
			}
		}
		if(!q.empty()) q.pop();
	}
	if(path.size()) _print();
}
int main()
{
	cin>>n>>e;
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			m[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int tmp1,tmp2;
		cin>>tmp1>>tmp2;
		m[tmp1][tmp2]=1;
		m[tmp2][tmp1]=1;
	}
	for(int i=0;i<n;i++)
	{
		if(path.size()) _print();
		if(!vis[i]) DFS(i);
	}
	if(path.size()) _print();
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=0;i<n;i++) 
	{
		if(path.size()) _print();
		if(!vis[i]) BFS(i);
	}
	if(path.size()) _print();
	system("PAUSE");
	return 0;
}