#include <bits/stdc++.h>
using namespace std;
bool judge(long long int i)
{
    if(i % 7 == 0)
        return true;
    while(i)
    {
        if(i % 10 == 7)
            return true;
        i /= 10;
    }
    return false;
}
int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int a[4] = {0};
    long long int num = 0;
    for(long long int i = 1; num < n; i++)//Ì«ÈÝÒ×´íÁË°É£¡
    {
        if(judge(i))
        {
            if(i % 4 == 0)
                a[3]++;
            else
                a[i%4-1]++;
        }
        else
            num++;
    }
    for(int i = 0; i < 4; i++)
        if(i!=3)
            printf("%lld\n", a[i]);
        else
            printf("%lld",a[i]);
    return 0;
}
