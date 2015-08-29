#include <iostream>

using namespace std;

int main()
{
	int n,i=0;
	long long a,b,c;
	cin>>n;
	while(n--)
	{
		i++;
		cin>>a>>b>>c;
		printf("Case #%d: ",i);
		if((a+b)>c) printf("true\n");
		else printf("false\n");
	}
	return 0;
}