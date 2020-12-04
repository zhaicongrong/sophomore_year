#include <stdio.h>
#include <stdlib.h>
int Find(int S[], int element)
{
    element--;
    for(;S[element] >= 0; element = S[element]);
    return element;
}
void Union(int S[], int Root1, int Root2)
{
    if(S[Root1] < S[Root2])
    {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    return;
}
void Input_connection(int S[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    //a--;b--;
    int Root1, Root2;
    Root1 = Find(S, a);
    Root2 = Find(S, b);
    Union(S, Root1, Root2);
    getchar();
    return;
}
void Check_connection(int S[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    int Root1 = Find(S, a);
    int Root2 = Find(S, b);
    if(Root1 == Root2 && Root1 != -1)
        printf("yes\n");
    else
        printf("no\n");
}
void Check_network(int S[], int n)
{
    int a[n];
    for(int i = 0; i < n;i ++)
        a[i] = 0;
    int num = 0;
    for(int i = 1; i <= n; i++)
    {
        int root = Find(S, i);
        a[root]++;
    }
    for(int i = 0; i < n; i++)
        if(a[i]) num++;
    if(num == 1)
        printf("The network is connected.");
    else
        printf("There are %d components.", num);
    return;
}
int main()
{
    int n;
    char in;
    scanf("%d\n", &n);
    int S[n];
    for(int i = 0; i < n; i++)
        S[i] = -1;
    do {
        scanf("%c", &in);
        switch (in){
            case 'I': Input_connection( S); break;
            case 'C': Check_connection(S);break;
            case 'S': Check_network(S, n);break;
        }

    }while(in != 'S');
    return 0;
}
