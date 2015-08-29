#include <iostream>
#include <string>
using namespace std;
struct child
{
	int id;
	struct child *next;
	child(){next=NULL;}
};
struct node
{
	int num;
	child *childlist;
	node(){num=0;childlist=NULL;}
}*tree;
int num[105]={0};
int level=1;
void countleaves(int l,int id)
{
	child *p=tree[id].childlist;
	l++;
	while(p)
	{
        if(level<l) level=l;  
        if(tree[p->id].num==0)num[l]++;  
        else countleaves(l,p->id);  
        p=p->next;  
    }  
}
int main()
{
	int n,m,i,j,k,id;
	child *c1;
	cin>>n>>m;
	tree=new node[n+1];
	for(i=0;i<m;i++)
	{
		node *p;
		cin>>id>>k;
		tree[id].num=k;
		for(j=0;j<k;j++)
		{
			c1=new child;
			cin>>c1->id;
			if(tree[id].childlist)
				c1->next=tree[id].childlist;
			tree[id].childlist=c1;
		}
	}
	if(tree[1].num==0){num[0]=1;level=0;}
	else
	{
		num[0]=0;
		countleaves(0,1);
	}
	for(i=0;i<level;i++) cout<<num[i]<<' ';
	cout<<num[level]<<endl;
	system("PAUSE");
	return 0;
}