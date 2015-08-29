#include<iostream>
using namespace std;

#define MaxNum 10000

typedef int ElemType;

int main()
{
	int N,M;
	ElemType S,D;
	cin>>N>>M>>S>>D;
	//用邻接矩阵存储图 
	int **len = new int*[N];					//储存公路长度
	int **cost = new int*[N];					//储存费用
    for(int i=0; i<N; i++)
	{
        len[i] = new int[N];
        cost[i] = new int[N];
    }			  
	//初始化
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			len[i][j] = MaxNum;
			cost[i][j] = MaxNum;
		}
	} 
	//构建邻接矩阵，处理输入数据
	for(int i=0;i<M;i++)
	{
		ElemType c1,c2;
	 	int l,c;
	 	cin>>c1>>c2>>l>>c;
	 	len[c1][c2] = l;
	 	len[c2][c1] = l;
	 	cost[c1][c2] = c;
	 	cost[c2][c1] = c;
	} 
	  
	//Dijastra算法开始
	int *dist = new int[N];           			//记录当前路径长度
	int *acost = new int[N]; 					//记录当前花费
	//初始化
	for(int i=0;i<N;i++)
	{
		dist[i] = MaxNum;
	  	acost[i] = MaxNum;
	} 
	dist[S] = 0;
	acost[S] = 0;
	   
	//进行算法
 	for(int k=0;k<2;k++)
	{
	   	for(int v=0;v<N;v++)
		{
			for(int w=0;w<N;w++)
			{
	   			if(dist[v] != MaxNum)
				{
	   				if(dist[v]+len[v][w] < dist[w])
		   				dist[w] = dist[v] + len[v][w];						
					else if(dist[v] + len[v][w] == dist[w] && acost[v] != MaxNum && acost[v]+cost[v][w] <acost[w])
						acost[w] = acost[v] + cost[v][w];							
				}
			} 	   								
		}	   		 	   						
	} 		
	cout<<dist[D] << " " <<acost[D] <<endl;
	return 0;
}
