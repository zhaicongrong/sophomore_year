#include <iostream>
#include <cstdio>
using namespace std;
long long int diff[50000001] = {0};
int main()
{
    long long int n, p;
    long long int minnum = 9999999;
    scanf("%lld %lld", &n, &p);
    long long int x = 0;
    long long int first;
    if(n >= 1)
        scanf("%lld", &first);
    x = first;
    for(long long int i = 2; i <= n; i++)
    {
        long long int tmp;
        scanf("%lld", &tmp);
        diff[i] = tmp - x;
        x = tmp;
    }
    while(p--)
    {
        long long int x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        diff[x] += z;
        diff[y+1] -= z;
    }
    x = first;
    for(int i = 1; i <= n; i++)
    {
        x += diff[i];
        minnum = min(minnum, x);
    }

    printf("%d", minnum);

    return 0;
}
