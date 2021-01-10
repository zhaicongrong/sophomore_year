#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int N, t;
    scanf("%d %d", &N, &t);
    int a[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int index = (N - t) % N;
    for(int i  = 0; i < N; i++)
    {
        if(index == N)
            index = 0;
        if(N)
            printf("%d ", a[index]);
        else
            printf("%d", a[index]);
        index++;
    }
    return 0;
}
