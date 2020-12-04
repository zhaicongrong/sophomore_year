#include <stdio.h>
#include <stdlib.h>
typedef struct Node *Nodep;
int c = 0;
struct Node
{
    int V;
    Nodep Next;
};
void CreateTable(Nodep *G, int N)
{
    for(int i = 0; i < N; i++)
    {
        Nodep tmp = (Nodep)malloc(sizeof(struct Node));
        tmp->V = i;
        tmp->Next = NULL;
        G[i] = tmp;
    }
}
void addToGraph(Nodep *G, int a, int b)
{
    Nodep present, rear, k;
    k = (Nodep)malloc(sizeof(struct Node));
    k->Next = NULL;
    k->V = b;
    rear = G[a];
    present = rear->Next;
    if(present == NULL)
    {
        //printf("no present.\n");
        G[a]->Next = k;
        return;
    }
    while(present)
    {
        //printf("!!\n");
        if(b > present->V)
        {
            if(present->Next == NULL)
            {
                present->Next = k;
                break;
            }
            else
            {
                present = present->Next;
                rear = rear->Next;
            }

        }
        else
        {
            rear->Next = k;
            k->Next = present;
            break;
        }
    }
    return;
}
void dfs(Nodep *G, int N, int visited[], int j)
{
    if(visited[j] == 1)
        return;
    else
    {
        if(c ==0)
            printf("{ %d", j);
        else
            printf(" %d", j);
        visited[j]++;
    }
    Nodep t = G[j];
    c++;
    while(t->Next)
    {
        dfs(G, N, visited, t->Next->V);
        t = t->Next;
    }
    c--;
    if(c == 0)
        printf(" }\n");
    return;
}
void bfs(Nodep *G, int N, int visited[], int haveprinted[], int j)
{
    if(visited[j] == 1)
        return;
    visited[j]++;
    if(haveprinted[j] == 0)
    {
        printf("{ %d", j);
        haveprinted[j]++;
    }
    Nodep t = G[j];
    c++;
    while(t->Next)
    {
        if(haveprinted[t->Next->V] == 0)
        {
            printf(" %d", t->Next->V);
            haveprinted[t->Next->V]++;
        }
        t = t->Next;
    }
    t = G[j];
    //printf("!!\n");
    while(t->Next)
    {
        if(visited[t->Next->V] == 0)
        {
            //haveprinted[t->Next->V]++;
            bfs(G, N, visited, haveprinted, t->Next->V);
        }
        t = t->Next;
    }
    c--;
    //printf(" c:%d",c);
    if(c == 0)
        printf(" }\n");
    return;
}
int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);
    Nodep G[N];
    CreateTable(G, N);
    int visited[N];
    int haveprinted[N];
    for(int i = 0; i < N; i++)
        visited[i] = 0;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        addToGraph(G, a, b);
        addToGraph(G, b, a);
    }

    //dfs(G, N, visited, 0);
    //update(G, N, visited);
    for(int i = 0; i < N; i++)
        dfs(G, N, visited, i);
    c = 0;
    for(int i = 0; i < N; i++)
    {
        visited[i] = 0;
        haveprinted[i] = 0;
    }

    for(int i = 0; i < N; i++)
        bfs(G, N, visited, haveprinted, i);
    return 0;
}
