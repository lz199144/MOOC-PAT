#include <iostream>
#include <cstring>
#include <cstdlib>
 using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k;
    double exp[1001];
    memset(exp,0,sizeof(exp));
    int flag=0;
    while(scanf("%d",&k)!=EOF)
	{
        int i;
        int j;
        for(j=0;j<k;j++)
		{
            scanf("%d",&i);
            double coff;
            scanf("%lf",&coff);                 
            exp[i]+=coff;
        }
        scanf("%d",&k);
        for (j=0;j<k;j++)
		{
            scanf("%d",&i);
            double coff;
            scanf("%lf",&coff);                 
            exp[i]+=coff;
        }
        int count=0;
        for(i=1000;i>=0;i--)
            if(exp[i]!=0) 
				count++;
        printf("%d",count);
        for(i=1000;i>=0;i--)
            if(exp[i]!=0) 
				printf(" %d %.1lf",i,exp[i]); 
        printf("\n");
        memset(exp,0,sizeof(exp));
    }
    return 0;
}