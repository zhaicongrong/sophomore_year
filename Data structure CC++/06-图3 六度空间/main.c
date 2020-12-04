#include <stdio.h>
#include <stdlib.h>
typedef struct Node * pNode;
int count = 0;
int num = 0;
struct Node
{
    int x;
    pNode Next;
};
void Initialization(pNode S[], int N)
{
    for(int i = 0; i < N; i++)
    {
        pNode k = (pNode)malloc(sizeof(struct Node));
        k->x = i;
        k->Next = NULL;
        S[i] = k;
    }
    return;

}
void readgraph(int M, pNode *S)
{
    int i = 0;
    for(; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        pNode k1, k2;
        a--;//1
        b--;//2
        k1 = (pNode)malloc(sizeof(struct Node));
        k2 = (pNode)malloc(sizeof(struct Node));
        k1->x = b;
        k2->x = a;
        k1->Next = k2->Next = NULL;
        pNode tmp;
        if(S[a]->Next == NULL)
        {
            S[a]->Next = k1;
        }
        else
        {
            tmp = S[a]->Next;
            while(tmp->Next)
                tmp = tmp->Next;
            tmp->Next = k1;
        }
        if(S[b]->Next == NULL)
        {
            S[b]->Next = k2;
        }
        else
        {

            tmp = S[b]->Next;
            while(tmp->Next)
                tmp = tmp->Next;
            tmp->Next = k2;
        }
    }
    return;
}
void printgraph(int N, pNode *S)
{
    for(int i = 0; i < N; i++)
    {
        printf("%d:", i);
        pNode t = S[i]->Next;
        while(t)
        {
                printf("->%d", t->x);
            t = t->Next;
        }
        printf("\n");
    }
}
void reset(int visited[], int queue[], int N)
{
    for(int i = 0; i < N; i++)
    {
        visited[i] = 0;
        queue[i] = 0;
    }
    count = 0;
    num = 0;
}
int check(int i, pNode *S, int visited[], int queue[])
{
    int present = -1, rear = -1;
    int last = -1, now = -1;
    visited[i]++;
    queue[++present] = i;
    last = i;
    while(present > rear && count < 6)
    {
        pNode t = S[queue[++rear]]->Next;
        while(t)
        {
            if(visited[t->x] == 0)
            {
                queue[++present] = t->x;
                visited[t->x]++;
            }
            t = t->Next;
        }
        now = queue[rear];//出栈的那个元素
        if(last == now)
        {
            count++;
            last = queue[present];
        }
    }
    //printf("present: %d rear: %d count: %d\n", present, rear, count);
    return present+1;
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    pNode S[N];
    Initialization(S, N);
    int queue[N];
    int visited[N];
    for(int i = 0; i < N; i++)
    {
        visited[i] = 0;
        queue[i] = 0;
    }
    readgraph(M, S);
    printgraph(N, S);
    for(int i = 0; i < N; i++)
    {
        int num = check(i, S, visited, queue);
        printf("%d: %.2f%c\n", i + 1, num*100.0/N,'%');
        reset(visited, queue, N);
    }
    return 0;
}
