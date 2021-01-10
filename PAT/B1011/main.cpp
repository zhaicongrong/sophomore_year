#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        long long int A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);
        printf("Case #%d:", i);
        if(A + B <= C)
        {
            printf("false");
        }
        else
            printf("true");
        if(i != T)
            printf("\n");
    }
    return 0;
}
