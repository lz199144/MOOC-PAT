#include <iostream>
#include <string>
#include <iterator>
using namespace std;
void PrintDay(char cc)
{
	switch(cc)
	{
		case 'A': printf("MON ");return;
		case 'B': printf("TUE ");return;
		case 'C': printf("WED ");return;
		case 'D': printf("THU ");return;
		case 'E': printf("FRI ");return;
		case 'F': printf("SAT ");return;
		case 'G': printf("SUN ");return;
	}
}
void PrintTime(char f)
{
	int i;
	if(f>='0'&&f<='9') i=f-'0';
	else i=10+f-'A';
	if(i>=10) printf("%d:",i);
	else printf("0%d:",i);
}
int main()
{
	int flag=1,i=0;
	string a,b,c,d;
	char Day,Time,Min;
	getline(cin,a);getline(cin,b);getline(cin,c);getline(cin,d);
	while(flag)
	{
		if(a[i]>='A'&&a[i]<='G'&&b[i]>='A'&&b[i]<='G')
		{
			if(a[i]==b[i]) {Day=a[i];flag=0;}
			else i++;
		}
		else i++;
	}
	i++;
	flag=1;
	while(flag)
	{
		if(((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9'))&&((b[i]>='A'&&b[i]<='N')||(b[i]>='0'&&b[i]<='9')))
		{
			if(a[i]==b[i]){Time=a[i];flag=0;}
			else i++;
		}
		else i++;
	}
	i=0;
	flag=1;
	while(flag)
	{
		if ((c[i]==d[i])&&(c[i]>='A'&&c[i]<='Z'||c[i]>='a'&&c[i]<='z')&&(d[i]>='A'&&d[i]<='Z'||d[i]>='a'&&d[i]<='z'))
			flag=0;
		else i++;
	}
	PrintDay(Day);
	PrintTime(Time);
	if(i<10) printf("0%d\n",i);
	else printf("%d\n",i);
	system("PAUSE");
	return 0;
}