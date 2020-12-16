#include <bits/stdc++.h>
#include <list>
using namespace std;
class Tree
{
public:
    int Sum;
    int Deletesum;
    int Node;
    int Result;
};
bool Mycompare( Tree& T1, Tree& T2)
{
    if(T1.Deletesum == T2.Deletesum)
        return T1.Node < T2.Node;
    else
        return T1.Deletesum > T2.Deletesum;
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    list<Tree> L;
    for(int i = 0; i < N; i++)
    {
        Tree tmp;
        int a, b;
        scanf("%d", &a);
        tmp.Sum = a;
        tmp.Node = i;
        int deletenum = 0;
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &b);
            if(b > 0)
                deletenum += b;
            else
                deletenum -= b;
        }
        tmp.Deletesum = deletenum;
        tmp.Result = tmp.Sum - tmp.Deletesum;
        L.push_back(tmp);
    }
    L.sort(Mycompare);
    int total = 0;
    for(list<Tree>::iterator it = L.begin(); it != L.end(); it++)
    {
        total += it->Result;
    }
    printf("%d ", total);

    printf("%d %d", L.front().Node+1, L.front().Deletesum);
    return 0;
}
