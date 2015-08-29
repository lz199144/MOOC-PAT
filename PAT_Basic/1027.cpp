#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int n,t;
	char c;
	cin>>n>>c;
	if(n==1) {cout<<c<<'/n'<<'0'<<endl;return 0;}
	t=(int)sqrt(double(n/2));
	for(int i=t;i>0;i--)
	{
		for(int k=t-i;k>0;k--)
			cout<<' ';
		for(int j=2*i-1;j>0;j--)
			cout<<c;
		cout<<endl;
	}
	for(int i=2;i<=t;i++)
	{
		for(int k=t-i;k>0;k--)
			cout<<' ';
		for(int j=2*i-1;j>0;j--)
			cout<<c;
		cout<<endl;
	}
	cout<<n-2*t*t+1<<endl;
	//system("PAUSE");
	return 0;
}