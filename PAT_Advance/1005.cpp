#include <iostream>
#include <string>
#include <cstring>
#define MAX 104

using namespace std;
string spell[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
	char a[MAX];
	int b[MAX];
	int sum=0,tmp,i;
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		sum+=a[i]-'0';
	}
	if(sum==0) {cout<<"zero"<<endl;return 0;}
	i=0;
	while(sum)
	{
		b[i]=sum%10;
		sum/=10;
		++i;
	}
	if(i==1){cout<<spell[b[0]]<<endl;return 0;}
	for(int j=i-1;j>0;j--) cout<<spell[b[j]]<<' ';
	cout<<spell[b[0]]<<endl;
	system("PAUSE");
	return 0;
}