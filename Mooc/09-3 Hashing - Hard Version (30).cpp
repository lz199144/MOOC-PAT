#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;


int main()
{
	ifstream f;
	f.open("test.txt");
	int n;
	//cin>>n;
	f>>n;
	vector<vector<int>> map(n);
	vector<int> result;
	int *degree=new int[n];
	int *hash=new int[n];
	for(int i=0;i<n;i++)
	{
		//cin>>hash[i];
		f>>hash[i];
		if(hash[i]>=0) degree[i]=0;
		else degree[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(hash[i]<0) continue;
		int cur=i;
		int pos=hash[i]%n;
		degree[i]=(cur-pos+n)%n;
		for(int j=0;j<degree[i];j++)
			map[(j+pos+n)%n].push_back(i);
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=0;i<n;i++)
	{
		if(degree[i]==0) q.push(make_pair(hash[i],i));
	}
	while(!q.empty())
	{
		pair<int,int> tmp=q.top();
		result.push_back(tmp.first);
		int v=tmp.second;
		q.pop();
		for(int i=0;i<map[v].size();i++)
		{
			if(--degree[map[v][i]]==0)
				q.push(make_pair(hash[map[v][i]],map[v][i]));
		}
	}
	cout<<result[0];
	for(size_t i=1;i<result.size();i++) cout<<' '<<result[i];
	cout<<endl;
	system("PAUSE");
	return 0;
}