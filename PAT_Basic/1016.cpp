#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a,b;
	int da,db,m=0,n=0,ansa=0,ansb=0;
	cin>>a>>da>>b>>db;
	for(int i=0;i<a.size();i++) 
	{
		if((a[i]-'0')==da)
		{
			m++;
			ansa=ansa*10+da;
		}
	}
	for(int i=0;i<b.size();i++)
	{
		if((b[i]-'0')==db)
		{
			n++;
			ansb=ansb*10+db;
		}
	}
	cout<<ansa+ansb<<endl;
	system("PAUSE");
	return 0;
}