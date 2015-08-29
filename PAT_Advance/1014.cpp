#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;
map<int,int> T;
queue<pair<int,int>> out_queue;
queue<pair<int,int>> in_queue[25];
pair<int,int> win[25];
int n,m,k,q;
int t=480;

bool has_Windows(int &win_num)
{
    for(int i=1;i<=n;i++)
    {
        if(win[i].second==0&&in_queue[i].size()>0)
        {
            win_num=i;
            return true;
        }
    }
    return false;
}

//补充排队人数
bool has_Queue()
{
    for(int i=1;i<=n;i++)
    {
        if(in_queue[i].size()<m)
        {
            return true;
        }
    }
    return false;
}

int main()
{
	int tmp,i;
	cin>>n>>m>>k>>q;
	for(i=1;i<=n;i++)
	{
		win[i].second=0;
	}
	for(i=1;i<=k;i++)
	{
		cin>>tmp;
		out_queue.push(make_pair(i,tmp));
	}
	while(in_queue[n].size()!=m&&!out_queue.empty())
	{
		for(int i=1;i<=n;i++)
		{
			if(in_queue[i].size()<m&&!out_queue.empty())
            {
                in_queue[i].push(out_queue.front());
                out_queue.pop();
            }
			win[i]=make_pair(0,0);
		}
	}
	while(t<1020)
	{
		//窗口工作
        for(i=1;i<=n;i++)
        {
            if(win[i].second!=0)
            {
                win[i].second--;
                if(win[i].second==0)
                {
                    in_queue[i].pop();
                }
            }
        }

        //窗口空闲，调入排队的人
        int win_num = -1;
        while(has_Windows(win_num))
        {
            win[win_num] = in_queue[win_num].front();
            T[in_queue[win_num].front().first] = in_queue[win_num].front().second+t;
        }
        //补充窗口前排队人数
        while(has_Queue())
        {
            int minSize=100000;
            int index=-1;
            for(i=1;i<= n;i++)
            {
                if(in_queue[i].size()<m&&in_queue[i].size()<minSize)
                {
                    minSize=in_queue[i].size();
                    index=i;
                }
            }

            if(!out_queue.empty()&&index!=-1)
            {
                in_queue[index].push(out_queue.front());
                out_queue.pop();
            }
            else break;
        }
		t++;
	}
	int query;
	for(i=0;i<q;i++)
	{
		cin>>query;
		if(T.count(query)) printf("%02d:%02d\n",T[query]/60,T[query]%60);
		else cout<<"Sorry"<<endl;
	}
	system("PAUSE");
	return 0;
}