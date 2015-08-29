#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    char a[82],b[82],c[82],d;
    int n=0,i,j=0,k=0,flag;
    scanf("%s %s",a,b);
    for(i=0;i<strlen(a);i++)
    {
        if((a[i]==b[j])&&(j<strlen(b)))
            j++;
        else
        {
            flag = 0;
            if(islower(a[i]))
                a[i]=a[i]-32;
            for(k=0;k<n;k++)
                if(a[i]==c[k])
                    flag=1;
            if(flag==0)
                c[n++]=a[i];
        }
    }
    for(i=0;i<n;i++)
        printf("%c",c[i]);
    system("pause");
    return 0;
}