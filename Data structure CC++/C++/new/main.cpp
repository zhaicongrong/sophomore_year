#include <bits/stdc++.h>
using namespace std;
#include <list>
#include <algorithm>
int X, Y;
class Point{
public:
    Point(int num, int x, int y)
    {
        this->Num = num;
        this->X = x;
        this->Y = y;
    }
    int Num;
    int X;
    int Y;
};
void readPosition(int n, list<Point>&L)
{
    for(int i = 0; i < n; i++)
    {
        int tmpx, tmpy;
        scanf("%d %d", &tmpx, &tmpy);
        tmpx -= X;
        tmpy -= Y;
        Point tmppoint(i+1, tmpx, tmpy);
        L.push_back(tmppoint);
    }
}
bool mycompare(Point p1, Point p2)
{
    int l1 = (p1.X) * p1.X + p1.Y * p1.Y;
    int l2 = p2.X * p2.X + p2.Y * p2.Y;
    if(l1 == l2)
        return p1.Num < p2.Num;
    else
        return l1 < l2;
}
void myPrint(list<Point>&L) {
    list<Point>::iterator it = L.begin();
    int num = 0;
    while (it != L.end() && num < 3)
    {
        printf("%d\n", it->Num);
        num++;
        it++;
    }
}
int main() {
    int n;
    scanf("%d %d %d", &n, &X, &Y);
    list<Point> L;
    readPosition(n, L);
    L.sort(mycompare);
    myPrint(L);
    return 0;
}
