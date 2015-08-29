#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
	if(n<=1) return false;
	int limit = floor(sqrt(double(n))+0.5);

	for(int i=2;i<=limit;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int reverse(int n,int d)
{
	int a[10];
	int i=0,sum=0;
	while(n)
	{
		a[i]=n%d;
		n/=d;
		i++;
	}
	for(int j=0;j<i;j++)
	{
		sum*=d;
		sum+=a[j];
	}
	return sum;
}

int main()
{
	int n,d;
	while(cin>>n&&n>0)
	{
		cin>>d;
		if(is_prime(n)&&is_prime(reverse(n,d)))
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}