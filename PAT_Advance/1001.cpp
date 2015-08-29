#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int c = a+b;
		if(c<0)
		{
			c=-c;
			printf("-");
		}
		if(c>=1000000)
			printf("%d,%03d,%03d\n",c/1000000,(c/1000)%1000,c%1000);
		else if(c>=1000)
			printf("%d,%03d\n",c/1000,c%1000);
		else
			printf("%d\n",c);
	}
	return 0;
}