#include <iostream>
#include <algorithm>

#define ElementType int
#define MAXNUM 100000000

using namespace std;

// 在这里放你要执行排序函数的函数体
void Bubble_Sort(ElementType A[], int N)
{
    for(int P=N-1; P>=0; P--)
    {
        int flag = 0;
        for(int i=0; i<P; i++)/*一趟冒泡排序*/
        {
            if(A[i] > A[i+1])
            {
                ElementType temp = A[i+1];
                A[i+1] = A[i];
                A[i] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}
void Insertion_Sort(ElementType A[], int N)
{
    for (int P=1; P<N; P++)
    {
        ElementType Tmp = A[P];     /* 摸一张牌 */
        int i;
        for(i=P; i>0 && A[i-1]>Tmp; i--)
            A[i] = A[i-1];     /* 移出空位 */
        A[i] = Tmp;     /* 新牌落位 */
    }
}
void Shell_Sort(ElementType A[], int N)
{
    for(int D=N/2; D>0; D/=2)     /* 希尔增量序列 */
    {
        for(int P=D; P<N; P++)
        {
            ElementType Tmp = A[P];
            int i;
            for(i=P; i>=D && A[i-D]>Tmp; i-=D)
                A[i] = A[i-D];
            A[i] = Tmp;
        }
    }
}
void Selection_Sort(ElementType A[], int N)
{
    for(int i=0; i<N; i++)
    {
        int MinPosition = i;
        int minNum = A[i];
        for(int j=i; j<N; j++)
        {
            if(A[j] < minNum)
            {
                minNum = A[j];
                MinPosition = j;
            }
        }
        ElementType tmp = A[i];
        A[i] = A[MinPosition];
        A[MinPosition] = tmp;
    }
}
// 以下是归并排序
// 7.1 核心：有序子列的归并
/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置 */
void Merge( ElementType A[], ElementType TmpA[],
            int L, int R, int RightEnd )
{
    int LeftEnd = R - 1; /* 左边终点位置。假设左右两列挨着 */
    int Tmp = L; /* 存放结果的数组的初始位置 */
    int NumElements = RightEnd - L + 1;
    while( L <= LeftEnd && R <= RightEnd )
    {
        if ( A[L] <= A[R] ) TmpA[Tmp++] = A[L++];
        else TmpA[Tmp++] = A[R++];
    }
    while( L <= LeftEnd ) /* 直接复制左边剩下的 */
        TmpA[Tmp++] = A[L++];
    while( R <= RightEnd ) /*直接复制右边剩下的 */
        TmpA[Tmp++] = A[R++];
    // 左边的未知L数据一定丢失，从右向左倒
    for( int i = 0; i < NumElements; i++, RightEnd -- )
        A[RightEnd] = TmpA[RightEnd];
}

// 7.2 递归算法（分而治之）
bool MSort( ElementType A[], ElementType TmpA[], int L, int RightEnd, int N )
{
    int Center;
    if ( L < RightEnd )
    {
        Center = ( L + RightEnd ) / 2;
        MSort( A, TmpA, L, Center, N );
        MSort( A, TmpA, Center+1, RightEnd, N );
        Merge( A, TmpA, L, Center+1, RightEnd );
    }
}

// 7.3 统一函数接口
void Merge_sort( ElementType A[],int N )
{
    ElementType *TmpA = new ElementType[N];
    if ( TmpA != NULL )
    {
        MSort( A, TmpA, 0, N-1, N);
        delete[] TmpA;
    }
}
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    ElementType n;
    cin >> n;
    ElementType *a = new int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    // Bubble_Sort(a, n);
    // Insertion_Sort(a, n);
    // Shell_Sort(a, n);
    // Selection_Sort(a, n);
    // sort(a, a+n);
    // stable_sort(a, a+n);
    // qsort(a, n, sizeof(int),cmp);
    Merge_sort(a, n);
    for(int i=0; i<n; i++)
    {
        if(i != n-1)
            cout << a[i] << " ";
        else
            cout << a[i];
    }
    return 0;
}