#include <bits/stdc++.h>
using namespace std;
int n, k, t, xl, yd, xr, yu;
void add(int&num1, int&num2)
{
    int staytime = 0;
    int flag1 = 0, flag2 = 0;
    for(int i = 0; i < t; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if( x >= xl && x <= xr && y >= yd && y <= yu)
        {
            flag1 = 1;
            staytime++;
        }
        else
            staytime = 0;
        if(staytime >= k)
            flag2 = 1;
    }
    if(flag1 == 1) num1++;
    if(flag2 == 1) num2++;
}
int main() {
    scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);
    int num1 = 0, num2 = 0;
    for(int i = 0; i < n; i++)
        add(num1, num2);
    printf("%d\n%d", num1, num2);
    return 0;
}
