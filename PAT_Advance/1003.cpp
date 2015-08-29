#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#define MAX 504
#define MAX_NUMBER 0x7fffffff
using namespace std;

int n,m,s,t;
int a[MAX][MAX];
int vis[MAX];
int man[MAX];
vector<int> path;
int maxTeam,minDis,numDis;

void DFS(int c)
{
	int min=0,num=0;
	if(c==t)
	{
		for(int i=0;i<path.size()-1;i++)
			min+=a[path[i]][path[i+1]];
		for(int i=0;i<path.size();i++)
			num+=man[path[i]];
		if(min<minDis)
		{
			numDis=1;
			maxTeam=num;
			minDis=min;
		}
		else if(min==minDis)
		{
			numDis++;
			if(maxTeam<num) maxTeam=num;
		}
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(a[c][i]>0)
		{
			if(!vis[i])
			{
				vis[i]=1;
				path.push_back(i);
				DFS(i);
				path.pop_back();
				vis[i]=0;
			}
		}
	}
}
void Init()
{
	for(int i=0;i<n;i++,a[i][i]=0,vis[i]=0)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j] = -1;
        }
    }
}
int main()
{
	path.clear();
	cin>>n>>m>>s>>t;
	Init();
	for(int i=0;i<n;i++)
		cin>>man[i];
	int c1,c2,dis;
	for(int i=0;i<m;i++)
	{
		cin>>c1>>c2>>dis;
		a[c1][c2]=dis;
		a[c2][c1]=dis;
	}
	numDis = 0;
    minDis = MAX_NUMBER;
    maxTeam = -1;

	vis[s] = 1;
    path.push_back(s);
    DFS(s);
    path.pop_back();
    vis[s] = 0;
	cout<<numDis<<' '<<maxTeam<<endl;
	return 0;
}