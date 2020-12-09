#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
int n, m;
double r;
using namespace std;
void Readblackhole(double O[])
{
    double tmp;
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &tmp);
        O[i] = tmp;
    }
}
double length(double point1[], double point2[])
{
    double tmp = 0.0;
    for(int i = 0; i < n; i++)
        tmp += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    tmp = sqrt(tmp);
    return tmp;
}
double minlen(double point1[], double point2[], double O[])
{
    double l1, l2, l3;
    l1 = length(point1, O);
    l2 = length(point2, O);
    l3 = length(point1, point2);
    double p = (l1 + l2 + l3)/2;
    double S = p * (p-l1) * (p-l2)*(p-l3);
    double S_ = sqrt(S);
    double h = S_ * 2.0 / l3;
    if(h >= r)
        return l3;
    double cosalpha = (l2*l2+l3*l3-l1*l1)/2/l3/l2;
    double cosbeta = (l1*l1+l3*l3-l2*l2)/2/l1/l3;
    if(cosalpha<0 || cosbeta < 0)
        return l3;
    double theta = acos((l1*l1+l2*l2-l3*l3)/2/l1/l2);
    double thetaA = acos(r/l1);
    double thetaB = acos(r/l2);
    double w = r * (theta-thetaA-thetaB);
    double _l1 = sqrt(l1 * l1 - r * r);
    double _l2 = sqrt(l2 * l2 - r * r);
    double L = w + _l1 + _l2;
    return L;
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%lf", &r);
    double mymap[m][n]={0};
    double O[n];
    Readblackhole(O);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
    {
        double tmp;
        scanf("%lf", &tmp);
        mymap[i][j] = tmp;
    }
    double sum[m];
    for(int i = 0; i < m; i++)
    {
        double tmpsum = 0.0;
        for(int j = 0; j < m ;j++)
        {
            if(j != i)
                tmpsum += minlen(mymap[i], mymap[j], O);

        }
        sum[i] = tmpsum;
    }
    for(int i = 0; i < m; i++)
        printf("%.14lf\n", sum[i]);
    return 0;
}
