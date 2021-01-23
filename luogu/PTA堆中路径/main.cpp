#include <stdio.h>
#include <stdlib.h>
int a[1001] = {0};
int b[1001] = {0};
int bptr = 0;
int N, M;
int psize = 0;
void formheap(void);
void myswap(int* x, int* y);
void printpath(int ptr);
void heap_insert(int x);
int deleteMin();
void Heapsort(void);
int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        heap_insert(tmp);
    }
    for(int i = 0; i < M; i++)
    {
        int ptr;
        scanf("%d", &ptr);
        printpath(ptr);
        if(i != M - 1)
            printf("\n");
    }
    printf("\n");
    for(int i = 0; i < N; i++)
        printf("%d ", deleteMin());
    printf("Sorted...\n");
    for(int i = 1; i <= N; i++)
        printf("%d ", a[i]);

    return 0;
}
void heap_insert(int x)
{
    psize++;
    a[psize] = x;
    int i = psize;
    for(; i > 1; i /= 2)
    {
        if(x < a[i/2])
            a[i] = a[i/2];
        else
            break;
    }
    a[i] = x;
    return;
}
void printpath(int ptr)
{
    while(ptr != 1)
    {
        printf("%d ", a[ptr]);
        ptr /= 2;
    }
    printf("%d", a[1]);
}
void formheap(void)
{
    for(int i = N / 2; i >= 1; i--)
    {
        if(2 * i + 1 <= N && a[i] > a[2*i+1])
            myswap(&a[i], &a[2*i+1]);
        if(a[i] > a[2*i])
            myswap(&a[i], &a[2*i]);
    }
    return;
}
void myswap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}
int deleteMin()
{
    printf("deleteMin...\n");
    if(psize == 0)
    {
        printf("Error!\n");
        return -99999;
    }
    int pMin = a[1];
    int tmp = a[psize--];
    a[psize+1] = pMin;
    int Parent;
    int Child;
    for(Parent = 1;Parent <= psize / 2; Parent = Child)
    {
        Child = 2 * Parent;
        if(Child + 1 <= psize && a[Child] > a[Child + 1])
            Child++;
        if(tmp <= a[Child])
        {
            break;
        }
        else
            a[Parent] = a[Child];
    }
    a[Parent] = tmp;
    return pMin;
}

