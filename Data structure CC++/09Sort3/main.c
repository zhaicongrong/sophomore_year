#include <stdio.h>
#include <stdlib.h>
void Read(int A[], int N);
void Judge(int A[], int B[], int N);
typedef int ElementType;
void Swap( int *a, int *b )
{
    int t = *a; *a = *b; *b = t;
}

void PercDown( int A[], int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
    /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}
int equal(int A[], int B[], int N)
{
    for(int i = 0; i < N; i++)
    {
        if(A[i] != B[i])
            return 0;
    }
    return 1;
}
int HeapSort( ElementType A[], ElementType B[], int N )
{ /* 堆排序 */
    int i;
    int flag = 0;
    for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
        PercDown( A, i, N );
    for ( i=N-1; i>0; i-- ) {
        /* 删除最大堆顶 */
        Swap( &A[0], &A[i] ); /* 见代码7.1 */
        PercDown( A, 0, i );
        if(equal(A, B, N))
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        Swap(&A[0], &A[i-1]);
        PercDown(A, 0, i-1);
        return flag;
    }
    return flag;
}
void Insertsort(int A[], int B[], int N);
int main() {
    int N;
    scanf("%d", &N);
    int A[N], B[N];
    Read(A, N);
    Read(B, N);
    Judge(A, B, N);
    return 0;
}
void Insertsort(int A[], int B[], int N)
{
    for(int i = 0; i < N; i++)
    {
        if(equal(A, B, N))
        {
            //i++;
            for(int j = i - 1; j >= 0; j--)
            {
                if(A[j+1] < A[j])
                    Swap(&A[j+1] ,&A[j]);
                else
                    break;
            }
            printf("Insert Sort\n");
            for(int i = 0; i < N; i++)
                if(i != N-1)
                    printf("%d ", A[i]);
                else
                    printf("%d", A[N-1]);
            break;
        }
        int j = i - 1;
        //int tmp = A[i];
        for(; j >= 0; j--)
        {
            if(A[j+1] < A[j])
                Swap(&A[j+1], &A[j]);
            else
                break;
        }
        //A[j] = tmp;
//        for(int i = 0; i < N; i++)
//            printf("%d ", A[i]);
//        printf("\n");

    }
}
void Judge(int A[], int B[], int N)
{
    int C[N];
    for(int i = 0; i < N; i++)
        C[i] = A[i];
    int flag = HeapSort(C, B, N);
    //printf("flag:%d\n", flag);
    if(flag == 1)
    {
        printf("Heap Sort\n");
        for(int i = 0; i < N; i++)
            if(i != N - 1)
                printf("%d ", C[i]);
            else
                printf("%d", C[N-1]);
        return;
    }
    for(int i = 0; i < N; i++)
        C[i] = A[i];
    Insertsort(C, B, N);

}
void Read(int A[], int N)
{
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
}
