#include <iostream>
#include <string>
using namespace std;

int RightAns(string a)
{
	int i=0,flag1=0,flag2=0,a1=0,a2=0,a3=0;
	while(flag1<=1&&flag2<=1&&(a[i]!='\0')&&(flag2<=flag1))
	{
		if((a[i]!=' ')&&(a[i]!='A')&&(a[i]!='P')&&(a[i]!='T')) return 0;
		else if(a[i]=='P') ++flag1;
		else if(a[i]=='T') ++flag2;
		else if((a[i]=='A')&&(flag1==0)&&(flag2==0)) ++a1;
		else if((a[i]=='A')&&(flag1==1)&&(flag2==0)) ++a2;
		else if((a[i]=='A')&&(flag1==1)&&(flag2==1)) ++a3;
		++i;
	}
	if((a1*a2==a3)&&(a2!=0)&&(flag2==1))
		return 1;
	return 0;
}
int main()
{
	int n;	
	cin>>n;
	string s;
	while(n--)
	{
		cin>>s;
		if(RightAns(s)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}