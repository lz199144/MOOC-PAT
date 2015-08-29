#include<iostream>  
#include<vector>  
#include<set>  
#include<map>  
#include<queue>  
#include<algorithm>  
#include<string>  
#include<cstring>  
using namespace std;  
int n;//student  
int m;//query  
typedef struct Node  
{  
    string name;  
    int grade[4];  
    int bestRank;  
    int bestGrade;  
}Node;  
typedef struct SortNode  
{  
    int g, idx, rank;  
    bool operator>(const SortNode& orh)const 
    {  
        return g>orh.g;  
    }  
}SortNode;  
char CharTable[4]={'A','C','M','E'};  
#define INF 0x6FFFFFFF  
int main()  
{  
    //input  
    scanf("%d%d",&n,&m);  
    vector<Node> stu(n);//student  
    map<string, int> stuMap;//for query  
    for(int i = 0; i < n; ++i)  
    {  
        cin>>stu[i].name;  
        scanf("%d%d%d", &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);  
        stu[i].grade[0] = stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3];  
        stu[i].bestRank = INF;  
        stuMap[stu[i].name] = i;  
    }  
    //  
    for(int i=0;i<4;++i)//for every record  
    {  
        vector<SortNode> sortNode(n);  
        for(int j=0;j<n;++j)  
        {  
            sortNode[j].g = stu[j].grade[i];  
            sortNode[j].idx = j;  
        }  
        sort(sortNode.begin(), sortNode.end(), greater<SortNode>());  
        //process the same grade case  
        int nowGrade = INF;  
        int nowRank = 0;  
        for(int j=0;j<n;++j)  
        {  
            if(sortNode[j].g == nowGrade)  
                sortNode[j].rank=nowRank;  
            else 
            {  
                sortNode[j].rank=j;  
                nowRank=j;  
                nowGrade=sortNode[j].g;  
            }  
        }  
        //then compare to select the best rank  
        for(int j=0;j<n;++j)  
        {  
            int idx=sortNode[j].idx;  
            int rank=sortNode[j].rank;  
            if(stu[idx].bestRank>rank)  
                stu[idx].bestRank=rank,stu[idx].bestGrade=i;  
        }  
    }  
   
    //query  
    for(int i=0;i<m;++i)  
    {  
        string name;  
        cin>>name;  
        map<string,int>::iterator it = stuMap.find(name);  
        if(it!=stuMap.end())  
        {  
            int idx=it->second;  
            printf("%d %c\n",stu[idx].bestRank+1,CharTable[stu[idx].bestGrade]);  
        }  
        else printf("N/A\n");  
    }  
    return 0;  
}  