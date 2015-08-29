#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct point
{
    int date;
    char add[10];
    char cnext[10];
    int idx;
} num[100010];
map<string,int> mapx;
int len=0;
bool cmp(const struct point &a,const struct point &b)
{
    return a.idx<b.idx;
}
int main()
{
    char a[10],b[10],st[10];
    int n,k,i;
    scanf("%s%d%d",st,&n,&k);
    for(i=0; i<n; ++i)
    {
        scanf("%s%d%s",num[i].add,&num[i].date,num[i].cnext);
        mapx.insert(make_pair(string(num[i].add),i));
        num[i].idx=999999;
    }
    int x=mapx.find(string(st))->second;
    for(i=0; i<n;)//整理串
    {
        num[x].idx=i;
        ++i;
        if(strcmp(num[x].cnext,"-1")==0)//处理不止一个串的情况
            break;
        x=mapx.find(string(num[x].cnext))->second;
    }
    sort(num,num+n,cmp);
    n=i;
    int high=n/k*k;
    for(i=0; i+k<=high; i+=k)
    {
        for(int j=k-1; j>0; --j)
        {
            printf("%s %d %s\n",num[i+j].add,num[i+j].date,num[i+j-1].add);
        }
        printf("%s %d ",num[i].add,num[i].date);
        if(i+k==n)//字符串刚好是k的倍数
        {
            printf("-1\n");
        }
        else if(i+2*k>high)//字符串不是k的倍数且多出小于k的长度
            printf("%s\n",num[i+k].add);
        else if(i+2*k-1<n)
            printf("%s\n",num[i+2*k-1].add);
        else
            printf("-1\n");
    }
    for(; i<n; ++i)
        printf("%s %d %s\n",num[i].add,num[i].date,num[i].cnext);
    return 0;
}
