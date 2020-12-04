#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    //printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
        printf("finished!");
    }
    //printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST)
    {
        BinTree T = (BinTree)malloc(sizeof(struct TNode));
        T->Left = T->Right = NULL;
        T->Data = X;
        return T;
    }
    if(X > BST->Data)
    {
        BST->Right = Insert(BST->Right, X);
    }
    else
    {
        BST->Left = Insert(BST->Left, X);
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    if(Find(BST, X) == NULL)
        return BST;
    if(BST->Data == X)
    {
        if((BST->Left == NULL) && (BST->Right == NULL))
            BST = NULL;
        else
        {
            if(BST->Left == NULL)
                BST = BST->Right;
            else if(BST->Right == NULL)
                BST = BST->Left;
            else
            {
                BinTree tmp = FindMin(BST->Right);
                BST->Data = tmp->Data;
                BST->Right = Delete(BST->Right, tmp->Data);
                free(tmp);
            }
        }
    }
    else
    {
        if(BST->Data > X)
            BST->Left = Delete(BST->Left, X);
        else
            BST->Right = Delete(BST->Right, X);
    }
    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    if(!BST) return NULL;
    if(BST->Data == X)
        return BST;
    else
    {
        if(BST->Data > X)
            return Find(BST->Left, X);
        else
            return Find(BST->Right, X);
    }
}
Position FindMin( BinTree BST )
{
    if(!BST) return NULL;
    if((BST->Left == NULL) && (BST->Right == NULL))
        return BST;
    if(BST->Left == NULL)
    {
        return BST;
    }
    return FindMin(BST->Left);
}
Position FindMax( BinTree BST )
{
    if((BST->Left == NULL) && (BST->Right == NULL))
        return BST;
    if(BST->Right == NULL)
    {
        return BST;
    }
        return FindMax(BST->Right);
}

