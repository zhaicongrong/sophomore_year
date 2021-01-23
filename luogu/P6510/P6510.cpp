#include <cstdio>
#include <iostream>
#include <vector>
int a[100001] = {0};
using namespace std;
int exec(int left, int right);
int merge(int left1, int right1, int left2, int right2);
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", exec(0, n - 1));
}
int exec(int left, int right)
{
    if(left >= right)
        return 0;
    if(left + 1 == right)
    {
        if(a[left] < a[right])
            return 2;
        else
            return 1;
    }
    int mid = (left + right) / 2;
    exec(left, mid);
    exec(mid+1, right);
    


}
