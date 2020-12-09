#include <stdio.h>
#include <stdlib.h>
int N, M, S, D;
typedef struct RoadInfo *ptr;
struct RoadInfo{
    int length;
    int cost;
};
int main() {
    scanf("%d %d %d %d", &N, &M, &S, &D);
    ptr Graph[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            ptr tmp = (ptr)malloc(sizeof(struct RoadInfo));
            tmp->length = 99999;
            tmp->cost = -1;
            Graph[i][j] = tmp;
        }
    for(int i = 0; i < M; i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        Graph[a][b]->length = Graph[b][a]->length = c;
        Graph[a][b]->cost = Graph[b][a]->cost = d;
    }
    int Q[N];
    for(int i = 0; i < N; i++)
        Q[i] = 0;
    Q[S] = 1;
    for(int i = 1; i < N; i++)
    {
        int min = 99999;
        int point = -1;
        for(int j = 0; j < N; j++)
        {
            if(Graph[S][j]->length < min && Q[j] == 0)
            {
                point = j;
                min = Graph[S][j]->length;
            }
        }
        Q[point] = 1;
        for(int j = 0; j < N; j++)
        {
            if(Graph[S][point]->length+Graph[point][j]->length<Graph[S][j]->length && Q[j] == 0)
            {
                Graph[S][j]->length = Graph[S][point]->length + Graph[point][j]->length;
                Graph[S][j]->cost = Graph[S][point]->cost + Graph[point][j]->cost;
            }
            else
                if(Graph[S][point]->length+Graph[point][j]->length == Graph[S][j]->length && Graph[S][point]->cost+Graph[point][j]->cost<Graph[S][j]->cost)
                {
                    Graph[S][j]->cost = Graph[S][point]->cost + Graph[point][j]->cost;
                }
        }
    }
    printf("%d %d", Graph[S][D]->length, Graph[S][D]->cost);
    return 0;
}
