#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    bool flag = true;
    vector<int> line(n, 0);
    for(int q = 0; q < m; q++)
    {

        int i, j;
        scanf("%d %d", &i, &j);
        for(int k = i; k <= j; k++)
            line[k-1]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(line[i] > 1 || line[i] == 0)
        {
            flag = false;
            printf("%d %d", i+1, line[i]);
            break;
        }
    }
    if(flag)
        printf("OK");
    return 0;
}
