#include <iostream>

using namespace std;
int main()
{
	long long t1,t2,t;;
	cin>>t1>>t2;
	t=(int)((t2-t1+50)/100);
	int sec,min,hour;
	sec=t%60;
	min=(t/60)%60;
	hour=t/3600;
	printf("%02d:%02d:%02d",hour,min,sec);
	system("PAUSE");
	return 0;
}