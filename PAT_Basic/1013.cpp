#include <iostream>
#include <cmath>
using namespace std;
int prime(int n)
{
	for(int i=2;i<=(int)sqrt(double(n));i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	int m,n,count=0;
	int i=2;
	int flag=1;
	cin>>m>>n;
	while(flag)
	{
		if(prime(i)) 
		{	
			count++;
			if(count==n)
			{
				cout<<i<<endl;
				flag=0;
			}
			else if((count<n)&&(count>=m))
			{
				if((count-m+1)%10!=0)
					cout<<i<<' ';
				else cout<<i<<endl;
			}
		}
		i++;
	}
	return 0;
}