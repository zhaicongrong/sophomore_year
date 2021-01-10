#include <bits/stdc++.h>
using namespace std;
int Result(long long int a, long long int b, long long int x)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b % 2 == 0)
    {
        return Result((a * a) % x, b / 2, x);
    }
    else
    {
        return (a * Result((a * a) % x, b / 2, x)) % x;
    }

}
int main()
{
    long long int a, b;
    a = 3;
    b = 50001;
    long long int x = 100003;
    cout << Result(a, b, x) << endl;
}
