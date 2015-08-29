#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
struct Account{                     //账号结构
    int QQ;                         //QQ号码
    char PW[17];                    //密码
};

struct Hash{
    Account *Element;               //结构数组
    int TableSize;                  //表的长度
};

bool Prime(int m);                  //生成素数
int Hash_Func(int Key);             //散列函数
Hash* CreateHash(int Size);         //创建散列表
void Login(Account A, Hash *H);     //登陆账号
void NewAccount(Account A, Hash *H);//新建账号
int Find(Account A, Hash *H);       //查找账号


int main()
{
    int N;
    Account Temp;
    char OP[2];                     //操作指令
    Hash *H = CreateHash(200000);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s%d%s", OP, &Temp.QQ, Temp.PW);
        if(OP[0]=='L') Login(Temp, H);      //登陆账号
            else NewAccount(Temp, H);       //新建账号
    }
    return 0;
}

bool Prime(int m)
{
    if(m < 2) return true;
    for(int i = 2; i < ceil(sqrt(m)); i++)
        if (m % i == 0) return true;
    return false;
}

Hash* CreateHash(int Size)
{
    Hash *T = new Hash;
    while((Prime(Size) && ((Size - 3) % 4 != 0))) Size++; //寻找4K+3形式的素数
    T->Element = new Account[Size];
    T->TableSize = Size;
    Account Init;                                         //初始化数组的结构
    Init.QQ = 0;
    fill(T->Element, T->Element + T->TableSize, Init);    //fill填充数组
    return T;
}


int Hash_Func(int Key)
{
    int Sum = 0;
    while( Key != 0){                               //折叠法，从右边起每4位作为1个数叠加
        int t = Key % 10000;
        Sum += t;
        Key = Key / 10000;
    }
    return Sum;
}

int Find(Account A, Hash *H)
{
    int CurrentPos, NewPos;                         //当前位置和实际位置
    int cNum = 0;                                   //记录冲突次数
    NewPos = CurrentPos = Hash_Func(A.QQ);
    while((H->Element[NewPos].QQ != 0) && (H->Element[NewPos].QQ != A.QQ)){
        if(++cNum % 2 == 1){                        //奇数往右->平方探索
            NewPos = CurrentPos + (cNum + 1) / 2 * (cNum + 1) / 2;
            while(NewPos >= H->TableSize)           //求余
                NewPos -= H->TableSize;
            }else{                                  //偶数往左->平方探索
            NewPos = CurrentPos - cNum / 2 * cNum / 2;
            while(NewPos < 0)                       //求余
                NewPos += H->TableSize;
            }
    }
    return NewPos;
}

void Login(Account A, Hash *H)
{
    int Pos;
    Pos = Find(A, H);
    if (H->Element[Pos].QQ == 0) printf("ERROR: Not Exist\n");
            else if(strcmp(H->Element[Pos].PW, A.PW) == 0) printf("Login: OK\n");
                        else printf("ERROR: Wrong PW\n");
}

void NewAccount(Account A, Hash *H)
{
    int Pos;
    Pos = Find(A, H);
    if (H->Element[Pos].QQ == 0){
        printf("New: OK\n");
        H->Element[Pos].QQ = A.QQ;
        strcpy(H->Element[Pos].PW, A.PW);
     }else printf("ERROR: Exist\n");
}