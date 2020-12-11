#include <stdio.h>
#include <stdlib.h>
typedef struct Vertex *ptr;
struct Vertex
{
    int length;
    int node;
    ptr AdjNode;
};
void ReadGraph(ptr Node[], int inDegree[], int N, int M);
int max(int a, int b);
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int inDegree[N];
    for(int i = 0; i < N; i++)
        inDegree[i] = 0;
    ptr Node[N];
    for(int i = 0; i < N; i++)
    {
        ptr tmp = (ptr)malloc(sizeof(struct Vertex));
        tmp->length = 0;
        tmp->node = i;
        tmp->AdjNode = NULL;
        Node[i] = tmp;
    }
    ReadGraph(Node, inDegree, N, M);
    int Queue[N], TopOrder[N], time[N];
    for(int i = 0; i < N; i++)
    {
        Queue[i] = 0;
        TopOrder[i] = 0;
        time[i] = 0;
    }
    int left = 0, right = 0;
    for(int i = 0; i < N; i++)
    {
        if(inDegree[i] == 0)
            Queue[right++] = i;
    }
    int cnt = 0;
    while(left < right)
    {
        int V = Queue[left++];
        TopOrder[cnt++] = V;
        ptr tmp = Node[V];
        if(!tmp->AdjNode)
            continue;
        else
        {
            while(tmp->AdjNode)
            {
                time[tmp->AdjNode->node] = max(time[tmp->AdjNode->node], time[V]+tmp->AdjNode->length);
                if(--inDegree[tmp->AdjNode->node] == 0)
                    Queue[right++] = tmp->AdjNode->node;
                tmp = tmp->AdjNode;
            }
        }
    }
    if(cnt != N)
        printf("Impossible");
    else
        printf("%d", time[TopOrder[N-1]]);
    return 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
void ReadGraph(ptr Node[], int inDegree[], int N, int M)
{
    for(int i = 0; i < M; i++)
    {
        int a, b, length;
        scanf("%d %d %d", &a, &b, &length);
        //a--;
        //b--;
        inDegree[b]++;
        if(!Node[a]->AdjNode)
        {
            ptr tmp = (ptr)malloc(sizeof(struct Vertex));
            tmp->node = b;
            tmp->length = length;
            tmp->AdjNode = NULL;
            Node[a]->AdjNode = tmp;
        }
        else
        {
            ptr tmp = (ptr)malloc(sizeof(struct Vertex));
            tmp->node = b;
            tmp->length = length;
            tmp->AdjNode = NULL;
            ptr tmp1 = Node[a]->AdjNode;
            while(tmp1->AdjNode)
                tmp1 = tmp1->AdjNode;
            tmp1->AdjNode = tmp;
        }
    }
}