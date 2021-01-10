#include <iostream>
using namespace std;
int main() {
    int N;
    int adrink = 0;
    int bdrink = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if((a+c == b) && (a+c == d))
            continue;
        if((a+c == b))
        {
            bdrink++;
            continue;
        }
        if(a+c == d)
        {
            adrink++;
            continue;
        }
    }
    printf("%d %d", adrink, bdrink);
    return 0;
}
