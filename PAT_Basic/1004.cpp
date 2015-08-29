#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,*a,*p,i,j=0;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++)
		if(OK_(a[i],a))
			p[j++]=a[i];
	sort(p);
	while(j--) cout<<p[j];
	return 0;
}