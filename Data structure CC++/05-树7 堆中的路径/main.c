#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int H[MAX] = {0};
int h = 0;
void addToHeap(int t)
{
    int i;
    i = ++h;
    for(;H[i/2]>t;i/=2)
        H[i] = H[i/2];
    H[i] = t;
    return;
}
void printHeap(int num)
{
    int first = 1;
    while(num)
    {
        if(first)
        {
            printf("%d", H[num]);
            first--;
        }
        else
            printf(" %d",H[num]);
        num/=2;
    }
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int i;
    for(i = 0; i < MAX; i++)
        H[i] = -10001;
    for(i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        addToHeap(tmp);
    }
    for(i = 0; i < M; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        printHeap(tmp);
        if(i != M-1)
            printf("\n");
    }
    return 0;
}
