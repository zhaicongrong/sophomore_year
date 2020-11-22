### Root of AVL Tree

#### 知识储备

1. 树结构构建

   ```c
   typedef struct TreeNode *Position;
   struct TreeNode
   {
       int value;
       Position left;
       Position right;
   };
   ```

2. AVL树四种调整方式

   + LLrotation

   ```c
   Position LLrotation(Position T)
   {
       Position t;
       t = T->left;
       T->left = t->right;
       t->right = T;
       return t;
   }
   ```

   + LRrotation

   ```c
   Position LRrotation(Position T)
   {
       Position t = T->left->right;
       T->left->right = t->left;
       t->left = T->left;
       T->left = t->right;
       t->right = T;
       return t;
   }
   ```

   + RRrotation

   ```c
   Position RRrotation(Position T)
   {
       Position t;
       t = T->right;
       T->right = t->left;
       t->left = T;
       return t;
   }
   ```

   + RLrotaion

   ```c
   Position RLrotation(Position T)
   {
       Position t = T->right->left;
       T->right->left = t->right;
       t->right = T->right;
       T->right = t->left;
       t->left = T;
       return t;
   }
   ```

   

   这里挑选RLrotation进行讲解：

   ![1](C:\Users\ZHT\Desktop\1.png)

   由于节点$t$导致了$T$节点的不平衡，因此需要调整$T$,$A$,和$t$三个节点的位置。因此要将$t$作为新的根节点，t的左子树变为$T$，$t$的右子树变为$A$。必须还要注意重新链接$t$原来的左子树和右子树，对应放到$T$的右子树上和$A$的左子树上。

   这四种调整方式推荐通过画图去理解，参考浙大mooc中的讲解。



#### 程序理解

1. insert 函数

   ```c
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
   ```

   insert 函数实际上是一个按顺序插入节点，并递归从下往上扫描树检查是否有不平衡的节点的一个函数。因此在insert 函数内部再次调用insert函数，即插入节点时，就要对该节点用GetTreeHeight进行检查，是否存在不平衡的情况。如果有，直接进入该节点的左子树/右子树判断应该使用哪一种旋转方式。所以insert操作相当于递归到最深处插入节点，再逐次返回并调整的一个函数。

2. GetTreeHeight 函数

   ```c
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
   ```

   此处利用递归调用函数。本来作者想在树结构中加一个height来记录平衡状态。然而在insert返回时比较难操作，要考虑太多的情况，因此还是在每次判断的时候调用测试树高的函数。如果在正规的比赛中碰到应该还是要在结构体中增加height记录，因为在计算规模较大的树时可能会超时。



附上源代码

```c
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

```

