#include <iostream>
#include <vector>
using namespace std;
//result[0]��ʾAӮB�Ĵ�����result[1]��ʾA��Bսƽ�Ĵ�����result[2]��ʾA�ܸ�B�Ĵ���
//winA[0]��ʾA�ԡ�C��սʤB�Ĵ�����winA[1]��ʾA�ԡ�J��սʤB�Ĵ�����winA[2]��ʾA�ԡ�B��սʤB�Ĵ�������Bͬ��
int result[3],winA[3],winB[3];
void f(char player_A,char player_B)
{
    if(player_A == player_B)//սƽ
    {
        result[1]++;
    }
    else
    {
        switch(player_A)
        {
            case 'C':
                if(player_B=='B')//B�ԡ�B��սʤA
                {
                    result[2]++;
                    winB[2]++;
                }
                else//A�ԡ�C��ʤB
                {
                    result[0]++;
                    winA[0]++;
                }
                break;
            case 'J':
                if(player_B=='C')//B�ԡ�C��ʤA
                {
                    result[2]++;
                    winB[0]++;
                }
                else//A�ԡ�J��ʤB
                {
                    result[0]++;
                    winA[1]++;
                }
                break;
            case 'B':
                if(player_B=='J')//B�ԡ�J��ʤA
                {
                    result[2]++;
                    winB[1]++;
                }
                else//A�ԡ�B��ʤB
                {
                    result[0]++;
                    winA[2]++;
                }
        }
    }
}
int max(int win[3])//��������д洢����������
{
    if((win[2]>=win[1]) && (win[2]>=win[0])) return 2;
    if((win[0]>=win[1]) && (win[0]>=win[2])) return 0;
    if((win[1]>=win[0]) && (win[1]>=win[1])) return 1;
}
int main()
{
    int N;
    cin>>N;
    char player_A,player_B;
    while(N--)
    {
        cin>>player_A>>player_B;
        f(player_A,player_B);
    }
    cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<endl;
    cout<<result[2]<<" "<<result[1]<<" "<<result[0]<<endl;
    char index2char[3] = {'C','J','B'};//0����C������������1����J������������2����B����������
    cout<<index2char[max(winA)]<<" "<<index2char[max(winB)];
    return 0;
}