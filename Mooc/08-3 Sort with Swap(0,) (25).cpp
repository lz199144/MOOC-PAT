#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int* arr=new int[n];
	bool* flag=new bool[n];
	int count(0);
	int circlecount(0);
	for(int i=0;i<n;++i)
	{
		cin>>arr[i];
		flag[i]=false;
	}
	for(int i=0;i<n;++i)
	{
		if(flag[i]==true)
			continue;
		if(arr[i]==i)
		{
			flag[i]=true;
		}
		else
		{
			++circlecount;
			int idx=i;
			int value=arr[idx];
			while(value!=i)
			{
				idx=value;
				value=arr[idx];
				flag[idx]=true;
				++count;
			}
		}
	}
	if(arr[0]!=0)
		cout<<count+2*(circlecount-1);
	else
		cout<<count+2*circlecount;
	return 0;
}
