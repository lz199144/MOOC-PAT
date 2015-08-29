#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,m;
	int a[100];
	cin>>n>>m;
	m=m%n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=n-m;i<n;i++)
		cout<<a[i]<<' ';
	for(int i=0;i<n-m-1;i++)
		cout<<a[i]<<' ';
	cout<<a[n-m-1]<<endl;
	return 0;
}