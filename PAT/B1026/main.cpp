#include <iostream>
using namespace std;
void myPrint(long long int x)
{
    if(x < 10)
        printf("0%lld", x);
    else
        printf("%lld", x);
}
int main() {
    long long int C1, C2;
    scanf("%lld %lld", &C1, &C2);
    long long int CLK_TCK = 100;
    long long int Result = (C2 - C1) / CLK_TCK;
    if((C2 - C1) / 10 % 10 >= 5)
        Result++;
    long long int hh=0, mm=0, ss=0;
    ss = Result % 60;
    Result /= 60;
    mm = Result % 60;
    Result /= 60;
    hh = Result % 60;
    myPrint(hh);
    printf(":");
    myPrint(mm);
    printf(":");
    myPrint(ss);
    return 0;
}
