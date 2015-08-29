#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct cake
{
	double w;
	double p;
};
bool compare(cake a,cake b)
{
	return a.p>b.p;
}
int main()
{
	int n;
	double d;
	vector<cake> m;
	vector<double> v;
	double tmp,sum=0;
	cin>>n>>d;
	int j=n;
	while(j--) 
	{
		cin>>tmp;
		v.push_back(tmp);
	}
	for(int i=0;i<n;i++) 
	{
		cin>>tmp;
		cake *t=new cake;
		t->p=tmp/v[i];
		t->w=v[i];
		m.push_back(*t);
		delete(t);
	}
	sort(m.begin(),m.end(),compare);
	int i=0;
	while(d>1e-9&&i<n)
	{
		if(d<m[i].w)
		{
			sum+=d*m[i].p;
			d=0;
		}
		else
		{
			sum+=m[i].p*m[i].w;
			d-=m[i].w;
			i++;
		}
	}
	printf("%.2f\n",sum);
	system("PAUSE");
	return 0;
}