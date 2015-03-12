#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
struct Account{                     //�˺Žṹ
    int QQ;                         //QQ����
    char PW[17];                    //����
};

struct Hash{
    Account *Element;               //�ṹ����
    int TableSize;                  //��ĳ���
};

bool Prime(int m);                  //��������
int Hash_Func(int Key);             //ɢ�к���
Hash* CreateHash(int Size);         //����ɢ�б�
void Login(Account A, Hash *H);     //��½�˺�
void NewAccount(Account A, Hash *H);//�½��˺�
int Find(Account A, Hash *H);       //�����˺�


int main()
{
    int N;
    Account Temp;
    char OP[2];                     //����ָ��
    Hash *H = CreateHash(200000);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s%d%s", OP, &Temp.QQ, Temp.PW);
        if(OP[0]=='L') Login(Temp, H);      //��½�˺�
            else NewAccount(Temp, H);       //�½��˺�
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
    while((Prime(Size) && ((Size - 3) % 4 != 0))) Size++; //Ѱ��4K+3��ʽ������
    T->Element = new Account[Size];
    T->TableSize = Size;
    Account Init;                                         //��ʼ������Ľṹ
    Init.QQ = 0;
    fill(T->Element, T->Element + T->TableSize, Init);    //fill�������
    return T;
}


int Hash_Func(int Key)
{
    int Sum = 0;
    while( Key != 0){                               //�۵��������ұ���ÿ4λ��Ϊ1��������
        int t = Key % 10000;
        Sum += t;
        Key = Key / 10000;
    }
    return Sum;
}

int Find(Account A, Hash *H)
{
    int CurrentPos, NewPos;                         //��ǰλ�ú�ʵ��λ��
    int cNum = 0;                                   //��¼��ͻ����
    NewPos = CurrentPos = Hash_Func(A.QQ);
    while((H->Element[NewPos].QQ != 0) && (H->Element[NewPos].QQ != A.QQ)){
        if(++cNum % 2 == 1){                        //��������->ƽ��̽��
            NewPos = CurrentPos + (cNum + 1) / 2 * (cNum + 1) / 2;
            while(NewPos >= H->TableSize)           //����
                NewPos -= H->TableSize;
            }else{                                  //ż������->ƽ��̽��
            NewPos = CurrentPos - cNum / 2 * cNum / 2;
            while(NewPos < 0)                       //����
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