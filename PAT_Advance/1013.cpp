#include <iostream>
#include <cstring>
#define MAX 1004
using namespace std;
int a[MAX][MAX];
int tmp[MAX][MAX];
int vis[MAX];
int n;
void DFS(int t)
{
	if(vis[t]) return;
	vis[t]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&tmp[t][i]) DFS(i);
}
void check(int t)
{
	int part_num=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==t||i==t) tmp[i][j]=0;
			else tmp[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			DFS(i);
			part_num++;
		}
	}
	cout<<part_num-2<<endl;
}

int main()
{
	int n,m,k;
	int c1,c2,c;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++,a[i][i] = 1)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
	for(int i=0;i<m;i++)
	{
		cin>>c1>>c2;
		a[c1][c2]=a[c2][c1]=1;
	}
	for(int i=0;i<k;i++)
	{
		cin>>c;
		check(c);
	}
	return 0;
}