#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

struct Hash{            //��ϣ��ṹ
    bool *Storage;      //��ϣ������
    int MSize;          //���鳤��
};

Hash* CreateHash(int MSize);             //������ϣ��
bool Prime(int m);                       //�ҳ�����MSize����С����
int Hash_Func(int Key, int MSize);       //ɢ�к���

int main()
{
   int MSize,N;
   Hash *H;
   scanf("%d%d",&MSize,&N);
   H = CreateHash(MSize);
   for(int i=0;i<N;i++)
   {
	   int x;
	   bool Flag = false;                 //�����ж�Ԫ����û�в��뵽��ϣ����
	   scanf("%d",&x);
	   for(int j=0;j<N;j++)
	   {                                  //ɨ��һ��
		   int Pos=Hash_Func(Hash_Func(x,H->MSize)+j*j,H->MSize); //����λ��
		   if (!H->Storage[Pos])
		   {                                       //��λ�ÿɷ�
			   if(i==N-1)  printf("%d",Pos);       //��β����
			   else printf("%d ",Pos);
			   H->Storage[Pos]=true;
			   Flag=true;
			   break;
           }
       }
	   if (Flag) continue;                //��������
       else if(i==N-1)  printf("-");      //û�еط��ɲ��룬ͬʱ��β����
       else printf("- ");
   }
   return 0;
}

Hash* CreateHash(int MSize)
{
    Hash *T = new Hash;
    while(Prime(MSize)) MSize++;              //Ѱ�Ҵ���MSize��С����
    T->Storage = new bool[MSize];
    T->MSize = MSize;
    fill(T->Storage, T->Storage + T->MSize, false);
    return T;
}

bool Prime(int m)
{
    if(m<2) return true;                      //�Ҳ���Ҫ����True����ǰ�ж�����дFalse����һ�·�
    for(int i=2;i<=int(sqrt(double(m)));i++)  //Pascal��β�ù���,��ceil����β��,���������,����Ҫ��<,������<=
       if (m%i==0) return true;
    return false;
}

int Hash_Func(int Key,int MSize)
{
    return Key%MSize;                         //��������Ƶ�ɢ�к���
}
