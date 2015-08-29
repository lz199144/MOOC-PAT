#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define lson rt<<1,l,MID
#define rson rt<<1|1,MID+1,r
//#define lson root<<1
//#define rson root<<1|1
#define MID ((l+r)>>1)
typedef long long ll;
typedef pair<int,int> P;
const int maxn=1005;
const int base=1000;
const int inf=999999;
const double eps=1e-5;
struct node//保存每个鳄鱼的位置  对应图的节点
{
    double x,y;
    int num;
    double dis;
    bool friend operator<(node a,node b)//定义优先级  后面优先队列 在多多条相同的最短路径里找第一步最小的
    {
        return a.dis<b.dis;
    }
} p[maxn];
double d;
int n;
double dis(double x,double y,double xx,double yy)//判断两点间的距离，用于判断是不是能跳上 即判断是不是邻接的
{
     return d-sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

bool pan(node s)//判断当前点是否能够跳到岸上
{

   if(fabs(s.x-50)<=d||fabs(s.x+50)<=d||fabs(s.y-50)<=d||(s.y+50)<=d)
        return true;
    return false;
}

double find_small_first(node s)//找开始在孤岛中心能跳到的点
{
     return sqrt(s.x*s.x+s.y*s.y)-7.5;
}

int di[maxn];
int pr[maxn];
int bfs(node s)
{//bfs搜索  不多说
    memset(di,-1,sizeof(di));
    memset(pr,-1,sizeof(pr));
    queue<node> q;
    q.push(s);
    di[s.num]=0;
    int i;
    while(!q.empty())
    {
        node tmp=q.front();
        q.pop();
        if(pan(tmp))
        {
            return tmp.num;
        }
        for( i=1;i<=n;i++)
        {
            if(dis(p[i].x,p[i].y,tmp.x,tmp.y)>=0&&di[p[i].num]==-1)
            {
                q.push(p[i]);
                di[p[i].num]=di[tmp.num]+1;
                pr[p[i].num]=tmp.num;
            }
        }
    }
    return 0;
}

vector<int> get_path(int t)//路径还原函数
{
    vector<int> path;
    for(;t!=-1;t=pr[t])path.push_back(t);
    reverse(path.begin(),path.end());
    return path;
}

int main()
{
    int m,i,j,k,t;
    cin>>n>>d;
    for(i=1; i<=n; i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].num=i;
    }
    if(d+7.5>=50)//特判  对应测试的最后一个测试点
    {
        printf("1\n");
        return 0;
    }
    priority_queue<node> q;//优先队列 在相同的最短路 里 找第一步最小的
    vector<int> path;
    for(i=1;i<=n;i++)
    {
        double kk=find_small_first(p[i]);

        if(kk>=0&&kk<=d)
        {
            p[i].dis=kk;
            q.push(p[i]);
        }
    }
    int dist;
    int flag=1;
    while(!q.empty())//尝试 从孤岛中心 所能到达的所有点
    {
        node
        tmp=q.top();
        q.pop();
        t=bfs(tmp);
        //cout<<di[t]<<' '<<t<<endl;
        if(flag&&t!=0)
        {
            dist=di[t];
            path=get_path(t);
            flag=0;
        }
        else if(t!=0&&di[t]<=dist)
        {
            path=get_path(t);
            dist=di[t];
        }

    }
    t=path.size();
    if(t==0)
        printf("0\n");
    else
    {
        printf("%d\n",t+1);
        for(i=0;i<t;i++)
            printf("%.0lf %.0lf\n",p[path[i]].x,p[path[i]].y);
    }
    return 0;
}