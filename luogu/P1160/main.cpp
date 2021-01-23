#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    scanf("%d", &N);
    int L, R;
    vector<int> left(N, -1);
    vector<int> right(N, -1);
    L = R = 0;
    for(int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        if(b == 0)
        {
            if(left[a] == -1)
            {
                L = i;
                left[i] = -1;
                left[a] = i;
                right[i] = a;
            }
            else
            {
                left[i] = left[a];
                right[i] = a;
                right[left[a]] = i;
                left[a] = i;
            }
        }
        else
        {
            if(right[a] == -1)
            {
                R = i;
                right[i] = right[a];
                right[a] = i;
                left[i] = a;
            }
            else
            {
                left[i] = a;
                right[i] = right[a];
                left[right[a]] = i;
                right[a] = i;
            }
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int a;
        scanf("%d", &a);
        a--;
        if(left[a]== -1 && right[a] == -1)
            continue;
        if(left[a] == -1)
        {
            L = right[a];
            left[right[a]] = -1;
            right[a] = -1;
            continue;
        }
        if(right[a] == -1)
        {
            R = left[a];
            right[left[a]] = -1;
            left[a] = -1;
            continue;
        }
        right[left[a]] = right[a];
        left[right[a]] = left[a];
        left[a] = right[a] = -1;
    }/*
    printf("L:%d R:%d\n", L+1, R+1);
    printf("\nleft:\t");
    for(int i = 0; i < N; i++)
        printf("%d ", left[i]);
    printf("\nright:\t");
    for(int i = 0; i < N; i++)
        printf("%d ", right[i]);*/
    while(L != R)
    {
        printf("%d ", L+1);
        L = right[L];
    }
    printf("%d", R+1);


    return 0;
}
