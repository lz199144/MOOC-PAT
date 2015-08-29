#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mark[101]={0};
int a[101];
void OK_(int number,int n)
{
	int b[101];
	int i=0;
	while(n!=1)
	{
		if(n%2==0)
			n=n/2;
		else
			n=(n*3+1)/2;
		b[i]=n;
		i++;
	}
	for(int m=0;m<number;m++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[m]==b[j])
			{
				mark[m]=1;
				break;
			}
		}
	}
}
int main()
{
	int n,i,j=0;
	int b[101];
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++)
		if(mark[i]==0)
			OK_(n,a[i]);
	j=0;
	for(i=0;i<n;i++)
		if(mark[i]==0)
			b[j++]=a[i];
	sort(b,b+j);
	j--;
	cout<<b[j--];
	while(j>=0) cout<<' '<<b[j--];
	cout<<endl;
	system("PAUSE");
	return 0;
}