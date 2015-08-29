#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#define MAX 1004

using namespace std;
struct poly
{
	int ex;
	double co;
};
vector<poly> a,b;
map<int,double> c;
int main()
{
	int k1,k2,ex;
	double co;
	cin>>k1;
	for(int i=0;i<k1;i++)
	{
		poly *p=new poly();
		cin>>p->ex>>p->co;
		a.push_back(*p);
		delete(p);
	}
	cin>>k2;
	for(int i=0;i<k2;i++)
	{
		poly *p=new poly();
		cin>>p->ex>>p->co;
		b.push_back(*p);
		delete(p);
	}
	for(int i=0;i<k1;i++)
	{
		for(int j=0;j<k2;j++)
		{
			ex=a[i].ex+b[j].ex;
			co=a[i].co*b[j].co;
			if(c.count(ex))
			{
				co+=c[ex];
				if(co==0) c.erase(ex);
				else c[ex]=co;
			}
			else c[ex]=co;
		}
	}
	cout<<c.size();
	map<int,double>::reverse_iterator it; 
    for (it=c.rbegin();it!=c.rend();++it)
		printf(" %d %.1f",it->first,it->second);
	cout<<endl;
	system("PAUSE");
	return 0;
}