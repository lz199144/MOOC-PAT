#include <iostream>

#define MAX 104

using namespace std;
int main()
{
	int n;
	int cur=0,sum=0,next;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>next;
		if(next>cur) sum+=6*(next-cur);
		else sum+=4*(cur-next);
		cur=next;
	}
	sum+=5*n;
	cout<<sum<<endl;
	system("PAUSE");
	return 0;
}