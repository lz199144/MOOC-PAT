#include <cstdio>
#include <cstdlib>
#include <set>
 
int root(int i,int *id)
{
    while(i!=id[i]){
        id[i] = id[id[i]];
        i = id[i];    
    }   
 
    return i;
}
 
void connected(int p,int q,int *id)
{
     if(root(p,id)==root(q,id))
        printf("yes\n");
     else
        printf("no\n");
}
 
void myunion(int p,int q,int *id)
{
    int i = root(p,id);
    int j = root(q,id);
    id[i] = j;
}
 
int main()
{
    int size;
    scanf("%d",&size);
    int *id = (int*)malloc((size+1)*sizeof(int));
    int i;
    for(i=0;i<=size;i++)
        id[i] = i;
 
    char ch;
    int a,b;
    ch = getchar();
    while(ch != 'S'){
        scanf("%d %d",&a,&b);
        if(ch=='C')
            connected(a,b,id);
        else if(ch=='I')
            myunion(a,b,id);
        ch = getchar();       
    }
    std::set<int> iset;
    for(i=1;i<=size;i++){
        iset.insert(root(i,id));
    }
    if(iset.size()==1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n",iset.size());
    return 0;      
}