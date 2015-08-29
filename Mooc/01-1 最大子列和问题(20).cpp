#include <iostream>
//#include <stdio.h>
#define MAX 100000
using namespace std;

int MaxSum_(int a[],int k)
{
    int i,MaxSum,ThisSum;
    MaxSum=ThisSum=0;
    for(i=0;i<k;i++)
    {
        ThisSum+=a[i];
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;
        else if(ThisSum<0)
            ThisSum=0;
    }
    return MaxSum;
}
int main()
{
    int i,k,a[MAX];
    cin>>k;
    for(i=0;i<k;i++)
        cin>>a[i];
    cout<<MaxSum_(a,k)<<endl;
}
