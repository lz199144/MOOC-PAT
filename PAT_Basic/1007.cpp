#include <iostream>
#include <cmath>
using namespace std;

int prime(int n)
{
	for(int i=2;i<=(int)sqrt(double(n));i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	int N,count=0;
	cin>>N;
	for(int i=2;i<N;i++)
		if(prime(i)&&prime(i+2)&&((i+2)<N)&&(!prime(i+1))) count++;
	cout<<count<<endl;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define MAXN 100000
//int a[MAXN];
//int isPrime(int num);
//int main()
//{
//    int num;
//    scanf("%d",&num);
//    int i,cnt1 = 2,cnt2 = 0;
//    a[2] = 2;
//    for(i = 3;i <= num;i++){
//        if(isPrime(i)){
//            cnt1++;
//            a[cnt1] = i;
//            if((a[cnt1]-a[cnt1-1])== 2){
//                cnt2++;
//            }
//        }
//    }
//    printf("%d",cnt2);
//    return 0;
//}
//int isPrime(int num){
//    int flag = 1;
//    int temp = (int) sqrt(double(num));
//    int i;
//    for(i = 2; i <= temp; i++){
//        if(num % i == 0) flag = 0;
//    }
//    return flag;
//}