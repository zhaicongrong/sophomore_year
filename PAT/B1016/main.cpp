#include <iostream>
using namespace std;
int main() {
    long long int A, B;
    int DA, DB;
    scanf("%lld %d %lld %d", &A, &DA, &B, &DB);
    long long int result1 = 0, result2 = 0;
    while(A)
    {
        int tmp = A % 10;
        if(tmp == DA)
            result1 = (result1 ) * 10 + DA;
        A /= 10;
    }
    while(B)
    {
        int tmp = B % 10;
        if(tmp == DB)
            result2 = (result2 ) * 10 + DB;
        B /= 10;
    }
    printf("%lld", result1 + result2);
    return 0;
}
