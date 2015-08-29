#include<iostream>
using namespace std;

#define MaxNum 10000

typedef int ElemType;

int main()
{
	int N,M;
	ElemType S,D;
	cin>>N>>M>>S>>D;
	//���ڽӾ���洢ͼ 
	int **len = new int*[N];					//���湫·����
	int **cost = new int*[N];					//�������
    for(int i=0; i<N; i++)
	{
        len[i] = new int[N];
        cost[i] = new int[N];
    }			  
	//��ʼ��
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			len[i][j] = MaxNum;
			cost[i][j] = MaxNum;
		}
	} 
	//�����ڽӾ��󣬴�����������
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
	  
	//Dijastra�㷨��ʼ
	int *dist = new int[N];           			//��¼��ǰ·������
	int *acost = new int[N]; 					//��¼��ǰ����
	//��ʼ��
	for(int i=0;i<N;i++)
	{
		dist[i] = MaxNum;
	  	acost[i] = MaxNum;
	} 
	dist[S] = 0;
	acost[S] = 0;
	   
	//�����㷨
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
