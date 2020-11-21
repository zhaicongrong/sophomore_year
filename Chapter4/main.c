#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode {
    int v;
    Tree Left, Right;
    int flag;
};

Tree NewNode(int V)
{
    Tree t = (Tree)malloc(sizeof(struct TreeNode));
    t->v = V;
    t->flag = 0;
    t->Left = t->Right = NULL;
    return t;
}

Tree insert(Tree T, int V)
{
    if(!T) {return NewNode(V);}
    else
    {
        if(V > T->v)
            T->Right = insert(T->Right, V);
        else
            T->Left = insert(T->Left, V);
    }
    return T;
}
Tree MakeTree(int N)
{
    Tree T;
    int i, V;
    scanf("%d", &V);
    T = NewNode(V);
    for(i = 1; i < N; i++)
    {
        scanf("%d", &V);
        T = insert(T, V);
    }
    return T;
}

int check(Tree T, int V)
{
    //printf("check:%d\n",V);
    if(T->flag){
        if(V < T->v) return check(T->Left, V);
        else if(V > T->v) return check(T->Right, V);
        else return 0;
    }
    else
    {
        if(V == T->v)
        {
            T->flag = 1;
            return 1;
        }
        else return 0;
    }
}
int Judge(Tree T, int N)
{
    int i, j, f = 1;
    scanf("%d", &i);
    if(T->v != i) f = 0;
    else T->flag = 1;
    for(j = 1; j < N; j++)
    {
        scanf("%d", &i);
        if(check(T, i) == 0)
            f = 0;
    }
    return f;
}
void ResetT(Tree T)
{
    if(!T) return;
    T->flag = 0;
    if(T->Right) ResetT(T->Right);
    if(T->Left) ResetT(T->Left);
    return;
}
void FreeTree(Tree T)
{
    if(!T) {free(T);return;}
    if(T->Right) {FreeTree(T->Right);free(T->Right);}
    if(T->Left) {FreeTree(T->Left);free(T->Left);}
    return;

}
int main()
{
    int N, L, i;
    scanf("%d", &N);
    Tree T;
    while(N)
    {
        scanf("%d", &L);
        T = MakeTree(N);
        for(i = 0; i < L;i++)
        {
            if(Judge(T, N)) printf("Yes\n");
            else printf("No\n");
            ResetT(T);
        }
        FreeTree(T);
        scanf("%d", &N);
    }
    return 0;
}
