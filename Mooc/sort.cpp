----
平衡快速排序--不稳定
 #include < cstdio >

int *A;

void Quick_sort(int A[], int n);                //快排接口函数
void Quicksort(int A[], int L, int R);          //快排实施函数
int Media3(int A[], int L, int R);              //找出头、中、尾的中位数
void Swap(int &a, int &b);

int main()
{
   int N;
   scanf("%d",&N);
   A = new int[N];
   for(int i = 0; i < N; i++)
     scanf("%d", &A[i]);
   Quick_sort(A, N);
   printf("%d", A[0]);
   for(int i = 1; i < N; i++)
    printf(" %d", A[i]);
  return 0;
}

void Swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int Media3(int A[], int L, int R)
{
    int Center = (L + R) / 2;
    if (A[L] > A[Center]) Swap(A[L], A[Center]);
    if (A[L] > A[R]) Swap(A[L], A[R]);
    if (A[Center] > A[R]) Swap(A[Center], A[R]);
    Swap(A[Center], A[R - 1]);                      //方便统一处理，待排元素放倒数第2个位置
    return A[R - 1];
}

void Quicksort(int A[], int L, int R)
{
    if(L < R){                          //如果还没处理完
    int Pivot = Media3(A, L, R);        //找出头、中、尾的中位数
    int i = L;
    int j = R - 1;
    while(i < j){                       //这里跟姥姥的不同，防止开始进去的时候i>=j
        while(A[++i] < Pivot);
        while(A[--j] > Pivot);
        if(i < j)Swap(A[i], A[j]);      //扫描后还要判断下再交换
           else break;
    }
    Swap(A[i], A[R - 1]);               //待排元素放到i位置
    Quicksort(A, L, i - 1);             //左边递归
    Quicksort(A, i + 1, R);             //右边递归
    }else return;

}

void Quick_sort(int A[], int n)         //接口函数，绣花枕头，方便用户使用
{
    Quicksort(A, 0, n - 1);
}
------------------------------------------------------------------------------------------------------------------------------
分割线
------------------------------------------------------------------------------------------------------------
归并排序非递归版-稳定
#include < cstdio >

int *A;

void Merge_sort(int A[], int n);                          //接口函数
void Merge_pass(int A[], int T[], int n, int length);     //归并控制
void Merge(int A[], int T[], int L, int R, int RightEnd); //归并函数

int main()
{
    int N;
    scanf("%d", &N);
    A = new int[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    Merge_sort(A, N);
    printf("%d", A[0]);
    for(int i = 1; i < N; i++)
        printf(" %d", A[i]);
    return 0;
}

void Merge(int A[], int T[], int L, int R, int RightEnd)
{
    int LeftEnd = R - 1;
    int Tp = L;
    while((L <= LeftEnd) && (R <= RightEnd))            //合并数组
        if (A[L] <= A[R]) T[Tp++] = A[L++];
                else T[Tp++] = A[R++];

    while(L <= LeftEnd)
        T[Tp++] = A[L++];
    while(R <= RightEnd)
        T[Tp++] = A[R++];
}


void Merge_pass(int A[], int T[], int n, int length)
{
    int i;
    for( i = 0; i <= n - 2 * length; i += 2 * length)        //成对合并
        Merge(A, T, i, i + length, i + 2 * length - 1);
    if (i + length < n)                                      //多余的尾巴含有2个子列
        Merge(A, T, i, i+length, n - 1);
      else
        for(int j = i; j < n ;j++)                           //就1个子列
           T[j] = A[j];
}

void Merge_sort(int A[], int n)
{
    int *T;
    int length = 1;
    T = new int[n];
    while(length < n){
        Merge_pass(A, T, n, length);   //按length长度合并数组，结果存到T
        length *= 2;
        Merge_pass(T, A, n, length);   //按length长度合并数组，结果存到A，如果上一步已排好序，只是倒回给A
        length *= 2;
    }
    delete T;
}
----------------------------------------------------------------------------------------------------------------------
分割线
----------------------------------------------------------------------------------------------------------------------
 归并排序递归版-稳定     递归写法就是简单易懂07-1. <wbr>排序(25 
#include < cstdio >

int *A;

void Merge_sort(int A[], int n);                            //归并函数接口
void Msort(int A[], int T[], int L, int RightEnd);          //递归分解
void Merge(int A[], int T[], int L, int R, int RightEnd);   //归并

int main()
{
    int N;
    scanf("%d", &N);
    A = new int[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    Merge_sort(A, N);
    printf("%d", A[0]);
    for(int i = 1; i < N; i++)
        printf(" %d", A[i]);
    return 0;
}

void Merge(int A[], int T[], int L, int R, int RightEnd)
{
    int LeftEnd = R - 1;                            //左边数组最后位置
    int Tp = L;                                     //临时数组下标
    int NumSum = RightEnd - L + 1;                  //合并元素总数
    while((L <= LeftEnd) && (R <= RightEnd)){
        if (A[L] <= A[R]) T[Tp++] = A[L++];
                else      T[Tp++] = A[R++];
    }
    while(L <= LeftEnd)
        T[Tp++] = A[L++];
    while(R <= RightEnd)
        T[Tp++] = A[R++];
    for(int i = 0; i < NumSum; i++, RightEnd--)
        A[RightEnd] = T[RightEnd];
}

void Merge_sort(int A[], int n)
{
    int *T;
    T = new int[n];                                 //创建临时数组
    Msort(A, T, 0, n - 1);
    delete T;
}

void Msort(int A[],int T[], int L, int RightEnd)
{
    int Center;
    if(L < RightEnd){
        Center = (L + RightEnd) / 2;                //取中点
        Msort(A, T, L, Center);                     //递归分解左半部分
        Msort(A, T, Center + 1, RightEnd);          //递归分解右半部分
        Merge(A, T, L, Center + 1, RightEnd);       //归并
    }
}
--------------------------------------------------------------------------------------------------------------------------
分割线
-------------------------------------------------------------------------------------------------------------------------- 
 堆排序-不稳定      虽然号称O（NlogN),实际效果是输给快排了
#include < cstdio >


int *A;

void Heap_sort(int A[], int n);                 //堆排序
void PercDown(int A[], int i, int n);           //堆调整
void Swap(int &a, int &b);

int main()
{
    int N;
    scanf("%d", &N);
    A = new int[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    Heap_sort(A, N);
    printf("%d", A[0]);
    for(int i = 1; i < N; i++)
        printf(" %d",A[i]);
    return 0;
}

void PercDown(int A[], int i, int n)   //调整堆 从第i个结点向下过滤 最后一个元素下标为n-1
{
    int temp = A[i];
    int Parent = i;                    //以i为父节点
    int Child;
    for(;Parent * 2 + 1 < n; Parent = Child){   // 2*i+1左孩子 2*i+2 右孩子
        Child = Parent * 2 + 1;
        if ((Child != n - 1) && (A[Child] < A[Child + 1]) ) Child++; //当前孩子不是最后一个结点并且小于右孩子 则下标移到右孩子
        if (temp > A[Child]) break;     //父节点比两个孩子都大，则不需要调整
                else A[Parent] = A[Child];  //反之调整
    }
    A[Parent] = temp;   //第i个节点最终存放的位置
}

void Swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Heap_sort(int A[], int n)
{
    int i = n / 2 - 1;                //计算最后一个非叶子节点
    for(;i >= 0; i--){              //建堆，叶节点不需要调整，因为没孩子
        PercDown(A, i, n);          //所以从最后一个非叶节点开始 即 n/2-1 为最后一个非叶子节点
    }
    for(i = n - 1; i > 0; i--){     //堆排序
        Swap(A[0], A[i]);
        PercDown(A, 0, i);
    }
}