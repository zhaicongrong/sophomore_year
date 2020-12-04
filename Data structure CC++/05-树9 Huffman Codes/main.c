#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *HuffmanTree;
struct TreeNode
{
    int weight;
    char c;
    HuffmanTree Left;
    HuffmanTree Right;
};
typedef struct HeapNode *MinHeap;
struct HeapNode
{
    int *Data;
    char *c;
    int Size;
};
MinHeap CreateHeap(int n);
HuffmanTree CreateHuffmanTree(MinHeap H);
int min(HuffmanTree T);
int check(void);
int main()
{
    int N, M;
    scanf("%d\n", &N);
    MinHeap H = CreateHeap(N);
    HuffmanTree T = CreateHuffmanTree(H);
    int WSL = min(T);
    scanf("%d\n", &M);
    while(M--)
    {
        if(check())
            printf("Yes");
        else
            printf("No");
        if(M != 1)
            printf("\n");
    }
    return 0;
}
MinHeap CreateHeap(int n)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapNode));
    H->Size = 0;
    H->c = (char *)malloc(sizeof(char) * (n+1));
    H->Data = (int *)malloc(sizeof(int) * (n+1));
    H->Data[0] = -1;
    H->c[0] = '0';
    for(int i = 1; i <= n; i++)
    {
        char c;
        int f, j;
        scanf("%c %d", &c, &f);
        j = ++H->Size;
        for(;H->Data[j/2] > f; j/=2)
        {
            H->Data[j] = H->Data[j/2];
            H->c[j] = H->c[j/2];
        }
        H->Data[j] = f;
        H->c[j] = c;


    }
}
