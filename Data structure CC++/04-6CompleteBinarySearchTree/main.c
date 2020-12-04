#include <stdio.h>
#include <stdlib.h>
int compare(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}
int GetLeftLength(int n)
{
    int tmp = 1;
    //printf("!");
    if(n == 1) return 0;
    if(n == 2) return 1;
    for(;!(tmp - 1 <= n && n - tmp + 1 <= tmp); tmp *= 2)
       printf("##n:%d tmp:%d\n", n, tmp);
        ;
    int X = n - tmp + 1;
    int LeftNum = 0;
    if(X <= tmp / 2)
    {
        LeftNum = (tmp - 2) / 2 + X;
    }
    else
        LeftNum = tmp - 1;

    //printf("leftNum: %d", LeftNum);
    return LeftNum;
}
void solve(int Aleft, int ARight, int TRoot, int T[], int A[])
{
    int n;
    n = ARight - Aleft + 1;//按大小排序的总个数
    if (n == 0)  return;
    printf("!update left: %d right: %d troot: %d\n", Aleft, ARight, TRoot);
    if (n == 1)
    {
        T[TRoot] = A[Aleft];
        return;
    }
    if (n == 2)
    {
        T[TRoot] = A[Aleft + 1];
        T[TRoot*2+1]  = A[Aleft];
        return;
    }
    int L = GetLeftLength(n);
    T[TRoot] = A[Aleft + L];
    int LeftTRoot = TRoot * 2 + 1;
    int RightTRoot = LeftTRoot + 1;
    solve(Aleft, Aleft + L - 1, LeftTRoot, T, A);
    solve(Aleft + L + 1, ARight, RightTRoot, T, A);
}
/*qsort(A, N, sizeof(int), compare);*/
int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    int T[N];
    for(int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        A[i] = tmp;
        T[i] = 0;
    }
    qsort(A, N, sizeof(int), compare);
    solve(0, N-1, 0, T, A);
    for(int i = 0; i < N; i++)
        printf("%d ", T[i]);
    return 0;
}
