#include <iostream>
using namespace std;

void printN(int n,int m)
{
	switch(n)
	{
	case 0:for(int i=1;i<=m;i++) cout<<i;break;
	case 1:while(m--) cout<<'S';break;
	case 2:while(m--) cout<<'B';break;
	}
}
int main()
{
	int n,i=0;
	cin>>n;
	int a[4];
	while(n)
	{
		a[i]=n%10;
		n/=10;
		i++;
	}
	while(i--)
		printN(i,a[i]);
	cout<<endl;
	system("PAUSE");
	return 0;
}