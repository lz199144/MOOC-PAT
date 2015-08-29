#include<iostream>
using namespace std;
int main()
{
    int N;
    int *input;
    int i;
    int begin=0, end=0, sum=0;
    int tempSum=0, tempBegin=0, tempEnd=0;

    cin>>N;
    input = new int[N];
    for(i=0; i<N; i++)
        cin>>input[i];

    end = N-1;
    for(i=0; i<N; i++)
    {
        if(tempSum >= 0)
        {
            tempSum += input[i];
            tempEnd = i;
        }
        else {
            tempSum = 0;
            tempSum += input[i];
            tempBegin = i;
            tempEnd = i;
        }
        if(tempSum > sum || (tempSum == 0 && end == N-1))
        {
            sum = tempSum;
            begin = tempBegin;
            end = tempEnd;
        }
    }
    cout<<sum<<" "<<input[begin]<<" "<<input[end]<<endl;
    return 0;
}
