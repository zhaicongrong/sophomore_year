#include <cstdio>
#include <iostream>
using namespace std;
long long int F[19][19] = {0};
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
        F[i][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        F[0][i] = F[1][i-1];
        for(int j = 1; j < n; j++)
        {
            F[j][i] = F[j-1][i] + F[j+1][i-1];
        }
    }
    printf("%lld", F[0][n]);
}