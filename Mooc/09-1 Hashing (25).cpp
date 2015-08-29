#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

struct Hash{            //哈希表结构
    bool *Storage;      //哈希表数组
    int MSize;          //数组长度
};

Hash* CreateHash(int MSize);             //创建哈希表
bool Prime(int m);                       //找出大于MSize的最小素数
int Hash_Func(int Key, int MSize);       //散列函数

int main()
{
   int MSize,N;
   Hash *H;
   scanf("%d%d",&MSize,&N);
   H = CreateHash(MSize);
   for(int i=0;i<N;i++)
   {
	   int x;
	   bool Flag = false;                 //用来判断元素有没有插入到哈希表中
	   scanf("%d",&x);
	   for(int j=0;j<N;j++)
	   {                                  //扫描一遍
		   int Pos=Hash_Func(Hash_Func(x,H->MSize)+j*j,H->MSize); //计算位置
		   if (!H->Storage[Pos])
		   {                                       //该位置可放
			   if(i==N-1)  printf("%d",Pos);       //结尾处理
			   else printf("%d ",Pos);
			   H->Storage[Pos]=true;
			   Flag=true;
			   break;
           }
       }
	   if (Flag) continue;                //正常插入
       else if(i==N-1)  printf("-");      //没有地方可插入，同时结尾处理
       else printf("- ");
   }
   return 0;
}

Hash* CreateHash(int MSize)
{
    Hash *T = new Hash;
    while(Prime(MSize)) MSize++;              //寻找大于MSize最小素数
    T->Storage = new bool[MSize];
    T->MSize = MSize;
    fill(T->Storage, T->Storage + T->MSize, false);
    return T;
}

bool Prime(int m)
{
    if(m<2) return true;                      //找不到要返回True，以前判断素数写False错了一次囧
    for(int i=2;i<=int(sqrt(double(m)));i++)  //Pascal截尾用惯了,把ceil当截尾用,结果悲剧了,这里要用<,不能用<=
       if (m%i==0) return true;
    return false;
}

int Hash_Func(int Key,int MSize)
{
    return Key%MSize;                         //按题意设计的散列函数
}
