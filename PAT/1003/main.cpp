#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int N, M, C1, C2;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    vector<int> List;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        List.push_back(tmp);
    }
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

    }
    return 0;
}
