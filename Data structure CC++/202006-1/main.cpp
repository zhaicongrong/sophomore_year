#include <bits/stdc++.h>

int N, M;
using namespace std;
bool judge(int x, int y)
{
    if((x>0 && y > 0) || (x < 0 && y < 0))
        return true;
    else
        return false;
}
int main()
{
    scanf("%d %d\n", &N, &M);
    int Ax[N], Ay[N], Bx[N], By[N];
    for(int i = 0; i < N; i++)
    {
        Ax[i] = Ay[i] = Bx[i] = By[i] = 0;
    }
    int topA = 0;
    int topB = 0;
    for(int i = 0; i < N; i++)
    {
        int tmpx, tmpy;
        char c;
        scanf("%d %d %c", &tmpx, &tmpy, &c);
        if(c == 'A')
        {
            Ax[topA] = tmpx;
            Ay[topA++] = tmpy;
        }
        else
        {
            Bx[topB] = tmpx;
            By[topB++] = tmpy;
        }
        getchar();
    }
    for(int i = 0 ; i < M; i++)
    {
        int x_state = 0, y_state = 0, flag = 1;
        int dA[topA];
        int dB[topB];
        int h1, h2, h3;
        scanf("%d %d %d", &h1, &h2, &h3);
        for(int j = 0; j < topA; j++)
        {
            dA[j] = h1 + h2 * Ax[j] + h3 * Ay[j];
        }
        for(int j = 0; j < topB; j++)
            dB[j] = h1 + h2 * Bx[j] + h3 * By[j];
        if(dA[0] > 0)
            x_state = 1;
        else if(dA[0] < 0)
            x_state = -1;
        else
            x_state = 0;
        if(dB[0] > 0)
            y_state = 1;
        else if(dB[0] < 0)
            y_state = -1;
        else
            y_state = 0;
        for(int j = 1; j < topA; j++)
            if(!judge(dA[j], x_state))
                flag = 0;
        for(int j = 1; j < topB; j++)
            if(!judge(dB[j], y_state))
                flag = 0;
       if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
