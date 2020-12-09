#include <bits/stdc++.h>
#include <map>
#include <list>
using namespace std;
class Point
{
public:
    Point(int x, int y)
    {
        this->X = x;
        this->Y = y;
    }
    int X;
    int Y;
};
bool myCompare(Point& x, Point& y)
{
    if(x.X == y.X)
        return x.Y < y.Y;
    else
        return x.X < y.X;
}
bool judge(int x, int y, list<Point>& P)
{
    int flag = 0;
    for(list<Point>::iterator it = P.begin(); it != P.end(); it++)
    {
        if((it->X == x - 1) && (it->Y == y))
            flag++;
        if((it->X == x + 1) && (it->Y == y))
            flag++;
        if((it->X == x) && (it->Y == y - 1))
            flag++;
        if((it->X == x) && (it->Y == y + 1))
            flag++;
    }
    if(flag == 4)
        return true;
    else
        return false;
}
int calculate(int x, int y, list<Point>& P)
{
    int flag = 0;
    for(list<Point>::iterator it = P.begin(); it != P.end(); it++)
    {
        if((it->X == x - 1) && (it->Y == y + 1))
            flag++;
        if((it->X == x + 1) && (it->Y == y + 1))
            flag++;
        if((it->X == x - 1) && (it->Y == y - 1))
            flag++;
        if((it->X == x + 1) && (it->Y == y - 1))
            flag++;
    }
    return flag;
}

int main()
{
    int n;
    int num[5]={0};
    scanf("%d", &n);
    list<Point> P;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        Point tmp(a, b);
        P.push_back(tmp);
    }
    P.sort(myCompare);
    for(list<Point>::iterator it = P.begin(); it != P.end(); it++)
    {
        if(judge(it->X, it->Y, P))
        {
            int points = calculate(it->X, it->Y, P);
            num[points]++;
        }
    }
    for(int i = 0; i < 5; i++)
        printf("%d\n", num[i]);


    return 0;
}
