#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n=0,m=0,i=0;
	char a[81][81];
	char s[81];
	gets(s);
	for(int j=0;j<strlen(s);j++)
	{
		if(s[j]==' ') n++,m=0;
		else a[n][m++]=s[j];
	}
	while(n>0)
		printf("%s ",a[n--]);
	printf("%s\n",a[0]);
	return 0;
}