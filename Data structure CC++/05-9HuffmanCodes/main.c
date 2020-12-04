#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct HuffmanTree * TNode;
typedef struct Heap * MinHeap;
struct HuffmanTree{
    int weight;
    TNode Left;
    TNode Right;
};
struct Heap{
    TNode * Data;
    int Size;
    int MaxSize;
};
MinHeap CreateHeap( int N )
{
    MinHeap H = (MinHeap)malloc(sizeof(struct Heap));
    H->Size = 0;
    H->MaxSize = N + 1;
    H->Data = (TNode *)malloc(sizeof(TNode) * (N + 1));
    for(int i = 0; i <= N; i++)
    {
        H->Data[i] = (TNode)malloc(sizeof(struct HuffmanTree));
        H->Data[i]->weight = 0;
        H->Data[i]->Left = NULL;
        H->Data[i]->Right = NULL;
    }
    H->Data[0]->weight = -1;
    return H;
}
int InsertHeap(MinHeap H, int a)
{
    int i = ++H->Size;
    for(; H->Data[i/2]->weight > a; i /= 2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = (TNode)malloc(sizeof(struct HuffmanTree));
    H->Data[i]->weight = a;
    H->Data[i]->Left = H->Data[i]->Right = NULL;
    return i;
}
MinHeap ReadData( MinHeap H, int N, int f[])
{
    for(int i = 0; i < N; i++)
    {
        int a;
        char c;
        getchar();
        scanf("%c %d", &c, &a);
        InsertHeap( H, a );
        f[i] = a;
    }
    return H;
}
TNode DeleteHeapMin( MinHeap H )
{
    int Parent, Child;
    TNode MinItem = H->Data[1];
    TNode tmp = H->Data[H->Size--];
    for(Parent = 1; Parent * 2  <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if((Child != H->Size) && (H->Data[Child]->weight > H->Data[Child + 1]->weight))
            Child++;
        if(tmp->weight <= H->Data[Child]->weight)
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = tmp;
    return MinItem;
}
TNode Huffman(MinHeap H)
{
    while(H->Size > 1)
    {
        TNode A, B;
        A = DeleteHeapMin(H);
        B = DeleteHeapMin(H);
        int f = InsertHeap(H, A->weight + B->weight);
        H->Data[f]->Left = A;
        H->Data[f]->Right = B;
    }
    return H->Data[1];
}

int WPL( TNode T, int Depth)
{
    if(T->Left == NULL && T->Right == NULL)
        return Depth * T->weight;
    else
    {
        int leftWPL = 0, rightWPL = 0;
        if(T->Left) leftWPL = WPL(T->Left, Depth + 1);
        if(T->Right) rightWPL = WPL(T->Right, Depth + 1);
        return rightWPL + leftWPL;
    }
}
int judge(int N, int f[], int CodeLen)
{
    int flag = 1, w = 0;
    TNode T = (TNode)malloc(sizeof(struct HuffmanTree));
    T->Left = T->Right = NULL;
    T->weight = -1;
    for(int i = 0; i < N; i++)
    {
        char c;
        char s[N + 1];
        getchar();
        scanf("%c %s", &c, s);
        int length = strlen(s);
        if(length == 1)
            flag = 0;
        w += length * f[i];
        int j = 0;
        TNode tmp = T;
        while(s[j] != '\0')
        {
            //printf("one!\n");
            if(s[j] == '0')
            {
                if(!tmp->Left)
                {
                    tmp->Left = (TNode)malloc(sizeof(struct HuffmanTree));
                    tmp->Left->weight = -1;
                    tmp->Left->Left = tmp->Left->Right = NULL;
                    tmp = tmp->Left;
                }
                else
                {
                    if(tmp->Left->weight != -1) {
                        flag = 0;
                        break;
                    }
                    else
                        tmp = tmp->Left;
                }
            }
            else
            {
                if(!tmp->Right)
                {
                    tmp->Right = (TNode)malloc(sizeof(struct HuffmanTree));
                    tmp->Right->weight = -1;
                    tmp->Right->Right = tmp->Right->Left = NULL;
                    tmp = tmp->Right;

                }
                else
                {
                    if(tmp->Right->weight != -1) {
                        flag = 0;
                        break;
                    }
                    else
                        tmp = tmp->Right;
                }
            }
            j++;
        }
        tmp->weight = i;
        if(tmp->Left != NULL && tmp->Right != NULL)
        {
            flag = 0;
        }

    }
    if( w > CodeLen)
        flag = 0;
    free(T);
    return flag;
}
int main()
{
    int N;
    scanf("%d", &N);
    int frequency[N];
    MinHeap H = CreateHeap( N );
    H = ReadData( H, N , frequency);
    TNode T = Huffman( H );
    int CodeLen = WPL( T, 0);
    int M;
    scanf("%d", &M);
    while(M--)
    {
        if(judge(N, frequency, CodeLen))
            if(M == 0)
                printf("Yes");
            else
                printf("Yes\n");
        else
            if(M == 0)
                printf("No");
            else
                printf("No\n");
    }
    return 0;
}
