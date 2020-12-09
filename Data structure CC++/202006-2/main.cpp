#include <bits/stdc++.h>
#include <map>
long long int n, a, b;
using namespace std;
void readvector(map<long long int, long long int>&m, int n)
{
    long long int x, y;
    for(long long int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &x, &y);
        m.insert(pair<long long int, long long int>(x, y));
    }
}
long long int result(map<long long int, long long int>& m1, map<long long int, long long int>& m2)
{
    long long int result = 0;
    for(map<long long int, long long int>::iterator it = m1.begin(); it != m1.end(); it++)
    {
        if(m2.find((*it).first) != m2.end())
        {
            result += it->second * (m2.find((*it).first))->second;
        }
    }
    return result;
}
int main()
{
    map<long long int, long long int> m1, m2;
    scanf("%lld %lld %lld", &n, &a, &b);
    readvector(m1, a);
    readvector(m2, b);
    printf("%lld", result(m1, m2));
    return 0;
}
