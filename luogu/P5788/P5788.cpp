#include <bits/stdc++.h>
using namespace std;
#include <stack>
long long int a[3000001] = {0};
int main()
{
    long long int n;
    scanf("%lld", &n);
    stack<pair<long long int, long long int> > myStack;
    for(long long int i = 1; i <= n; i++)
    {
        long long int tmp;
        scanf("%lld", &tmp);
        if(myStack.empty())
            myStack.push(pair<long long int, long long int>(i, tmp));
        else
        {
            while(!myStack.empty() && myStack.top().second < tmp)
            {
                a[myStack.top().first] = i;
                myStack.pop();
            }
            myStack.push(pair<long long int, long long int>(i, tmp));
        }
    }
    for(long long int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
}