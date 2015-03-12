#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#define MAX 104
using namespace std;
vector<pair<int,int>> point;
int vis[MAX];
int n,result=0;
double d;
bool is_safe(int v)
{
	if(abs(point[v].first)+d>=50||abs(point[v].second)+d>=50)
		return true;
	else return false;
}
bool can_jump(int i,pair<int,int> v,double l)
{
	if(((point[i].first-v.first)*(point[i].first-v.first)+
		(point[i].second-v.second)*(point[i].second-v.second))<=l*l)
		return true;
	else return false;
}
void DFS(int v)
{
	vis[v]=1;
	//cout<<point[v].first<<','<<point[v].second<<"->";
	if(is_safe(v)) {result=1;return;}
	for(int i=0;i<n;i++)
	{
		if(!vis[i]&&can_jump(i,make_pair(point[v].first,point[v].second),d))
		{
			DFS(i);
		}
	}
}
int main()
{
	//ifstream s;
	//s.open("test.txt");
	int px,py,last_point;
	//s>>n>>d;
	cin>>n>>d;
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=0;i<n;i++)
	{
		//s>>px>>py;
		cin>>px>>py;
		point.push_back(make_pair(px,py));
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i]&&can_jump(i,make_pair(0,0),d+7.5))
			DFS(i);
		if(result) break;
	}
	if(result==1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	system("PAUSE");
	return 0;
}