#include <iostream>
#include <cmath>
using namespace std;
float m[4];
float f(float x)
{
	return m[3]*pow(x,3)+m[2]*x*x+m[1]*x+m[0];
}
int main()
{
	float a,b,mid;
	for(int i=0;i<4;i++)
		cin>>m[3-i];
	cin>>a>>b;
	if((f(a)>0&&f(b)<0)||(f(a)<0&&f(b)>0))
	{
		while(abs(a-b)>1e-6)
		{
			mid=(a+b)/2;
			if(f(mid)*f(a)>0)
				a=mid;
			else if(f(mid)*f(a)<0)
				b=mid;
			else break;
		}
		printf("%.2f\n",mid);

	}
	else if(f(a)==0)
		printf("%.2f\n",a);
	else if(f(b)==0)
		printf("%.2f\n",b);
	//system("PAUSE");
	return 0;	
}