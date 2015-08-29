#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	vector<int> v(10,0);
	int m,i=0,j=1,flag=0;
	while(i<10)
	{
		cin>>m;
		v[i]+=m;
		++i;
	}
	while(j<10)
	{
		for(int n=0;n<v[j];n++)
		{
			while(v[0]&&flag)
			{
				cout<<'0';
				v[0]--;
			}
			cout<<j;
			flag=1;
		}
		j++;
	}
	while(v[0])
	{
		cout<<'0';
		v[0]--;
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}


