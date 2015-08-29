#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> n;
	int a1=0,a2=0,a3=0,a4=0,a5=0;
	int flag=0,flag1=0,flag2=0,flag3=0,flag4=0,count=0;
	int num,N;
	cin>>N; 
	while(N--){
		cin>>num;
		if(num%5==0&&num%2==0)
		{
			flag1=1;
			a1+=num;
		}
		if(num%5==1)
		{
			flag2=1;
			if(flag==0)
			{
				a2+=num;
				flag=1;
			}
			else
			{
				a2-=num;
				flag=0;
			}
		}
		if(num%5==2) {a3++;flag3=1;}
		if(num%5==3) {a4+=num;count++;};
		if(num%5==4) {if(num>a5) a5=num;flag4=1;}
	}
	if(flag1) printf("%d ",a1); else printf("%c ",'N');
    if(flag2) printf("%d ",a2); else printf("%c ",'N');
    if(flag3) printf("%d ",a3); else printf("%c ",'N');
    if(count) printf("%.1f ",1.0*a4/count); else printf("%c ",'N');
    if(flag4) printf("%d",a5);else printf("%c",'N');
	system("PAUSE");
	return 0;
}