#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#define MAX 10004
using namespace std;
int M[MAX][MAX];
int vis[MAX];
int n,m;
queue<int> q;
int BFS(int v)
{
	int tail=v,level=0,count=0,last=v;
	if(vis[v]==0)
	{
		vis[v]=1;
		q.push(v);
	}
	while(!q.empty())
	{
		v=q.front();
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&M[v][i])
			{
				vis[i]=1;
				q.push(i);
				tail=i;
			}
		}
          	q.pop();
		count++;
          	if(v==last) {level++;last=tail;}
		if(level==7) break;
	}
	return count;
}

void Init()
{
	for(int i=1;i<=n;i++) vis[i]=0;
	int len=q.size();
	for(int i=0;i<len;i++) q.pop();
}

int main()
{
	double result;
	int x1,x2;
	ifstream s;
	s.open("test.txt");
	//cin>>n>>m;
	s>>n>>m;
	for(int i=1;i<=n,vis[i]=0;i++)
		for(int j=1;j<=n;j++)
			M[i][j]=0;
	for(int i=1;i<=m;i++)
	{
		//cin>>x1>>x2;
		s>>x1>>x2;
		M[x1][x2]=1;
		M[x2][x1]=1;
	}
	for(int i=1;i<=n;i++)
	{
		Init();
		result=BFS(i)*1.0/n*100;
		printf("%d: %.2f",i,result);
		cout<<'%'<<endl;
	}
	system("PAUSE");
	return 0;
}