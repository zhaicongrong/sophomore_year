#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <math.h>
int visited[101] = {0};
int mapx[101] = {0};
int mapy[101] = {0};
int D, N;
int flag = 0;
int first = 0;
void store(int N)
{
    for(int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        mapx[i] = a + 50;
        mapy[i] = b + 50;
    }
    return;
}
int find(int x, int y)
{
    for(int i = 0; i < N; i++)
        if(mapx[i]==x && mapy[i]==y)
            return i;
    return -1;
}
void judge(int x, int y)
{
    if(first == 0)
    {
        for(int i = 0; i < N; i++)
        {
            if(visited[i] == 0 && ((mapx[i] - x)*(mapx[i] - x) + (mapy[i] - y)*(mapy[i] - y) <= (D + 15) * (D + 15)))
                judge(mapx[i], mapy[i]);
        }
        first++;
    }
    if((100 - x <= D) || (x <= D) || (100 - y <= D) || (y <= D))
    {
        flag = 1;
        return;
    }
    int k = find(x, y);
    visited[k] = 1;
    for(int i = 0; i < N; i++)
    {
        if(visited[i] == 0 && ((mapx[i] - x)*(mapx[i] - x) + (mapy[i] - y)*(mapy[i] - y) <= D * D))
            judge(mapx[i], mapy[i]);
    }
    return;
}
int main()
{
    scanf("%d %d", &N, &D);
    store(N);
    judge(50, 50);
    if(flag)
        printf("Yes");
    else
        printf("No");
    return 0;
}
