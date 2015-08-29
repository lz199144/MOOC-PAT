#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
long long a,b,e;
vector<int> c,d;
//void Add()
//{
//	int aL=strlen(a),bL=strlen(b);
//	int tmp=0;
//	int i=aL,j=bL;
//	while(j&&i)
//	{
//		c.push_back((a[i-1]+b[j-1]-'0'-'0'+tmp)%10);
//		tmp=(a[i-1]+b[j-1]-'0'-'0'+tmp)/10;
//		--j;--i;
//	}
//	while(i) {c.push_back(a[i-1]-'0');--i;}
//	while(j) {c.push_back(b[j-1]-'0');--j;}
//}
void convert(int n)
{
	/*long long e=0;
	int cL=c.size(),tmp=0;
	for(int i=cL-1;i>=0;i--)
		e=10*e+c[i];*/
	int i=0;
	while(e)
	{
		d.push_back(e%n);
		e=e/n;
		i++;
	}
	while(i--) cout<<d[i];
	cout<<endl;
}
int main()
{
	int n;
	cin>>a>>b>>n;
	if(a==0&&b==0) cout<<"0"<<endl;
	else 
	{
		e=a+b;;
		convert(n);
	}
	system("PAUSE");
	return 0;
}