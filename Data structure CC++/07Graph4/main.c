#include <stdio.h>
#define INF 99999
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int Graph[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            Graph[i][j] = INF;
   for(int i = 0; i < M; i++)
   {
       int a, b, c;
       scanf("%d %d %d", &a, &b, &c);
       a--;b--;
       Graph[a][b]=Graph[b][a] = c;
   }

   for(int k = 0; k < N; k++)
       for(int i = 0; i < N; i++)
           for(int j = 0; j < N; j++)
               if(Graph[i][k]+Graph[k][j]<Graph[i][j])
                   Graph[i][j] = Graph[i][k]+Graph[k][j];
    for(int i = 0; i < N; i++)
        Graph[i][i] = 0;
//   for(int i = 0; i < N; i++)
//   {
//       for(int j = 0; j < N; j++)
//           printf("%d ", Graph[i][j]);
//       printf("\n");
//   }
   int position = -1;
   int MAX = 0;
   int totalMIN = INF;
   for(int i = 0; i < N; i++)
   {
       MAX = 0;
       for(int j = 0; j < N; j++)
           if(Graph[i][j]>MAX)
           {
               MAX = Graph[i][j];
           }
       if(totalMIN > MAX)
       {
           position = i;
           totalMIN = MAX;
       }
   }
   if(totalMIN != INF)
        printf("%d %d", position+1, totalMIN);
   else
       printf("0");
   return 0;
}
