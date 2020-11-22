#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Position;
struct TreeNode
{
    int value;
    Position left;
    Position right;
};
Position NewNode(int i);
Position MakeTree(int N);
Position insert(Position T, int n);
Position RRrotation(Position T);
int GetTreeHeight(Position T);
Position LLrotation(Position T);
Position LRrotation(Position T);
Position RLrotation(Position T);
Position RRrotation(Position T);
int main()
{
    int N;
    scanf("%d", &N);
    Position tree = MakeTree(N);
    printf("%d", tree->value);
    return 0;
}
Position NewNode(int i)
{
    Position t = (Position)malloc(sizeof(struct TreeNode));
    t->value = i;
    t->left = t->right = NULL;
    return t;
}
Position MakeTree(int N)
{
    if(N == 0) return NULL;
    int tmp;
    scanf("%d", &tmp);
    Position t = NewNode(tmp);
    for(int i = 1; i < N; i++)
    {
        scanf("%d", &tmp);
        t = insert(t, tmp);
    }
    return t;
}
int GetTreeHeight(Position T)
{
    int H, HL, HR;
    if(!T) return 0;
    else
    {
        HL = GetTreeHeight(T->left);
        HR = GetTreeHeight(T->right);
        H = HL > HR ? HL : HR;
        return H + 1;
    }

}
Position insert(Position T, int i)
{
    if(!T)
        return NewNode(i);
    if(i > T->value)
    {
        T->right = insert(T->right, i);
        if(GetTreeHeight(T->right) - GetTreeHeight(T->left) == 2)
        {
            if(i > T->right->value)
                T = RRrotation(T);
            else if(i < T->right->value)
                T = RLrotation(T);
        }
    }
    else if(i < T->value)
    {
        T->left = insert(T->left, i);
        if(GetTreeHeight(T->left) - GetTreeHeight(T->right) == 2)
        {
            if(i > T->left->value)
                T = LRrotation(T);
            else
                T = LLrotation(T);
        }
    }
    return T;
}

Position LLrotation(Position T)
{
    Position t;
    t = T->left;
    T->left = t->right;
    t->right = T;
    return t;
}

Position LRrotation(Position T)
{
    Position t = T->left->right;
    T->left->right = t->left;
    t->left = T->left;
    T->left = t->right;
    t->right = T;
    return t;
}
Position RRrotation(Position T)
{
    Position t;
    t = T->right;
    T->right = t->left;
    t->left = T;
    return t;
}
Position RLrotation(Position T)
{
    Position t = T->right->left;
    T->right->left = t->right;
    t->right = T->right;
    T->right = t->left;
    t->left = T;
    return t;
}
