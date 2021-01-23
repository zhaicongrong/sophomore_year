#include <iostream>
#include <cstdio>
long long int tree[1000001][2] = {0};
using namespace std;
long long int Height(long long int n, int ptr)
{
    if(tree[ptr][0]==0 && tree[ptr][1]==0)
        return 0;
    long long int leftheight = Height(n, tree[ptr][0]);
    long long int rightheight = Height(n, tree[ptr][1]);
    return max(leftheight, rightheight)+1;
}
int main()
{
    long long int n;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        tree[i][0] = a;
        tree[i][1] = b;
    }
    printf("%lld", Height(n, 1) + 1);
    return 0;
}
