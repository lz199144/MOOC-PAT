#include <iostream>
#include <cstring> 
using namespace std;

int bigger(char a[20], char b[20])
{
    int i=0;
    for(i=0;i<10;i++)
    {
        if(a[i]-b[i]>0)
            return 1;
        if(a[i]-b[i]<0)
            return 0;
    }
    return 0;
}

int main()
{
    int n,i,count=0;
    char a[10],old[10],young[10];
    char b[20],big[20]="1814/09/05",small[20]="2014/09/07";
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s",a,b);
        if((bigger(b,"1814/09/05"))&&(bigger("2014/09/07",b)))
        {
            count++;
            if(bigger(b,big))
            {
                strcpy(big,b);
                strcpy(old,a);
            }
            if(bigger(small,b))
            {
                strcpy(small,b);
                strcpy(young,a);
            }
        }
    }
    if(count>0) 
        printf("%d %s %s\n",count,young,old);
    else 
        printf("0");
    system("pause");
    return 0; 
}
