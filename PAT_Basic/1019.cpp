#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b)
{
	return a>b;
}
int f(int n,int m)
{
	int i=4,a[4],sum=0;;
	while(i--)
	{
		a[i]=n%10;
		n=n/10;
	}
	if(m) sort(a,a+4,compare);
	else sort(a,a+4);
	i=0;
	while(i<4) 
	{
		sum=a[i]+sum*10;
		i++;
	}
	return sum;
}
void print(int n)
{
	int i=4,a[4];
	while(i--)
	{
		a[i]=n%10;
		n=n/10;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
}
int main()
{
	int n;
	cin>>n;
	if(n==6174) cout<<"7641 - 1467 = 6174";
	while(n!=6174&&n!=0)
	{
		print(f(n,1));
		cout<<" - ";
		print(f(n,0));
		cout<<" = ";
		print(f(n,1)-f(n,0));
		cout<<endl;
		n=f(n,1)-f(n,0);
	}
	system("PAUSE");
	return 0;
}