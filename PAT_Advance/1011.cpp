#include <iostream>

using namespace std;
int main()
{
	double a,m1=0,m2=0,m3=0;
	int f1=0,f2=0,f3=0;
	char d[3]={'W','T','L'};
	for(int i=0;i<3;i++) {cin>>a;if(a>m1) {m1=a;f1=i;}}
	for(int i=0;i<3;i++) {cin>>a;if(a>m2) {m2=a;f2=i;}}
	for(int i=0;i<3;i++) {cin>>a;if(a>m3) {m3=a;f3=i;}}
	cout<<d[f1]<<' '<<d[f2]<<' '<<d[f3]<<' ';
	printf("%.2f\n",(m1*m2*m3*0.65-1)*2);
	system("PAUSE");
	return 0;
}