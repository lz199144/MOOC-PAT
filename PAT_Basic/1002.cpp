#include <iostream>
using namespace std;
void PrintAns(int i)
{
	switch(i)
	{
		case 0: cout<<"ling"; break;
		case 1: cout<<"yi" ; break;
		case 2: cout<<"er" ; break;
		case 3: cout<<"san" ; break;
		case 4: cout<<"si" ; break;
		case 5: cout<<"wu" ; break;
		case 6: cout<<"liu" ; break;
		case 7: cout<<"qi" ; break;
		case 8: cout<<"ba" ; break;
		case 9: cout<<"jiu" ; break;
	}
}
int main()
{
	int i=0,ans=0;
	char a[100];
	cin>>a;
	while(a[i]!='\0')
	{
		ans+=(a[i]-'0');
		i++;
	}
	if(ans>=100)
	{
		PrintAns(ans/100);
		cout<<" ";
		PrintAns((ans/10)%10);
		cout<<" ";
		PrintAns(ans%10);
	}
	else if(ans>=10)
	{
		PrintAns(ans/10);
		cout<<" ";
		PrintAns(ans%10);
	}
	else PrintAns(ans);
	cout<<endl;
	return 0;
}