#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#define MAX 104

using namespace std;
struct Time
{
	int hour;
	int min;
	int sec;
};
struct sign
{
	string id;
	Time in;
	Time out;
};
int cal_time(Time t)
{
	return (t.hour*60+t.min)*60+t.sec;
}
bool compare1(sign s1,sign s2)
{
	return cal_time(s2.in)>cal_time(s1.in);
}
bool compare2(sign s1,sign s2)
{
	return cal_time(s1.out)>cal_time(s2.out);
}
int main()
{
	vector<sign> s;
	int n;
	/*ifstream f;
	f.open("test.txt");*/

	cin>>n;
	/*f>>n;*/
	for(int i=0;i<n;i++)
	{
		sign *p=new sign();
		cin>>p->id;
		scanf("%d:%d:%d%d:%d:%d",&p->in.hour,&p->in.min,&p->in.sec,&p->out.hour,&p->out.min,&p->out.sec);
		//f>>p->id>>p->in.hour>>p->in.min>>p->in.sec>>p->out.hour>>p->out.min>>p->out.sec;
		s.push_back(*p);
		delete(p);
	}
	/*f.close();*/
	sort(s.begin(),s.end(),compare1);
	cout<<s[0].id<<' ';
	sort(s.begin(),s.end(),compare2);
	cout<<s[0].id<<endl;
	system("PAUSE");
	return 0;
}