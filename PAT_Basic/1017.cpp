#include <iostream>
#include <string>
using namespace std;
int main()
{
	int j=0,n,m;
	string a;
	int b[1000];
	cin>>a>>n;
	m=a[0]-'0';
	if(a.size()==1) 
	{
		cout<<m/n<<' '<<m%n<<endl;
		return 0;
	}
	if((a[0]-'0')>=n)
	{
		b[0]=(a[0]-'0')/n;
		m=m%n;
		m=m*10;
		j++;
	}
	else m=m*10;
	for(int i=1;i<a.size();i++,j++)
	{
		m=a[i]-'0'+m;
		if(m>=n)
		{
			b[j]=m/n;
			m=m%n;
		}
		else
		{
			b[j]=0;
		}
		if(i!=(a.size()-1))
			m=m*10;
	}
	for(int i=0;i<j;i++) cout<<b[i];
	cout<<' '<<m<<endl;
	system("PAUSE");
	return 0;
}