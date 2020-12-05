# 构造哈夫曼树

为了实现哈夫曼算法，可以利用最小堆来储存最优解点。因此可以通过删除最小堆的根，并插入两个和来实现哈夫曼算法。因此在最小堆结构中的DATA应是指向哈夫曼树的指针数组。删除最小堆的根时也应当保留删除两个节点指向的哈夫曼树，并且做到在返回时左子树和右子树也都不为NULL。直到堆中只有一个有效元素时就说明一棵哈夫曼树生成完成了。:happy: 

## 最小堆与哈夫曼的结构

```c
typedef struct HuffmanTree * TNode;
typedef struct Heap * MinHeap;
struct HuffmanTree{
    int weight;
    TNode Left;
    TNode Right;
};
struct Heap{
    TNode * Data;
    int Size;
    int MaxSize;
};
```

这里是最基本的最小堆和哈夫曼结构的构建。:smiley:

注意:warning:：在后面对heap中的Data创建空间时应该首先对Data进行创建`Data = (TNode *)malloc(sizeof(TNode) * (N + 1))`再对Data中的每一项进行创建空间的操作`Data[i] = (TNode)malloc(sizeof(struct HuffmanTree))`。这应该是初学C语言才会出错的点，但是当时写程序的时候真的没看出来，还是看了其他博客上的标准代码才发现了错误。

## 最小堆的插入与删除操作

### 插入操作

```c
int InsertHeap(MinHeap H, int a)
{
    int i = ++H->Size;
    for(; H->Data[i/2]->weight > a; i /= 2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = (TNode)malloc(sizeof(struct HuffmanTree));
    H->Data[i]->weight = a;
    H->Data[i]->Left = H->Data[i]->Right = NULL;
    return i;
}
```

唯一不同的地方就是Data的类型改变了， 并且再插入操作中要设置哈夫曼根节点指向的左子树和右子树均为空。在后续实现哈夫曼算法时会在其他函数中更新指向的左子树和右子树的值，因此需要将本来返回的null函数值要改成堆数组的index。看到哈夫曼树的构建就会清楚啦！

### 删除操作

```c
TNode DeleteHeapMin( MinHeap H )
{
    int Parent, Child;
    TNode MinItem = H->Data[1];
    TNode tmp = H->Data[H->Size--];
    for(Parent = 1; Parent * 2  <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if((Child != H->Size) && (H->Data[Child]->weight > H->Data[Child + 1]->weight))
            Child++;
        if(tmp->weight <= H->Data[Child]->weight)
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = tmp;
    return MinItem;
}
```

习惯上还是将根节点保存在第一个元素。这样比较好记忆和操作。

~~之前写的版本竟然还是只传了哈夫曼树中的weight，我怕不是个傻子。~~

## 哈夫曼树的构建

```c
TNode Huffman(MinHeap H)
{
    while(H->Size > 1)
    {
        TNode A, B;
        A = DeleteHeapMin(H);
        B = DeleteHeapMin(H);
        int f = InsertHeap(H, A->weight + B->weight);
        H->Data[f]->Left = A;
        H->Data[f]->Right = B;
    }
    return H->Data[1];
}
```

当堆只有一个有效节点的时候就说明所有哈夫曼树的节点都整合到了一起，说明哈夫曼树就构建好啦！

## 计算WSL

```c
int WPL( TNode T, int Depth)
{
    if(T->Left == NULL && T->Right == NULL)
        return Depth * T->weight;
    else
    {
        int leftWPL = 0, rightWPL = 0;
        if(T->Left) leftWPL = WPL(T->Left, Depth + 1);
        if(T->Right) rightWPL = WPL(T->Right, Depth + 1);
        return rightWPL + leftWPL;
    }
}
```

利用递归的思想计算WSL。这学期一直在看Standard ML，感觉写C的递归已经有点不适应了。

## 另：判断某组编码是否为最优编码

某组编码为最优编码的条件有三个：

1. 有最小权值
2. 具有唯一性：只是路径的节点不能表示为某一元素，即每一个代表编码的节点不能有左子树和右子树
3. 不能有度为1的点。

为什么需要通过构造哈夫曼树来判断某组编码是否为最优编码呢？这是我在看浙大mooc时的一个疑问。后来我直到，这是为了得到该组编码的WSL。WSL是首先判断某组编码是否为最优编码的第一个条件。

还有另一个重要的条件就是每一个代表编码的节点应该没有左子树或者右子树，并且在找到该编码的路径中不能经过已经有值的节点（两个条件实际上是等价的，然而为了解决这个问题需要在程序中考虑到这两个问题）。第一个方面是先考虑的，先走的步长长的编码，后一个方面是后给出的，走的步长短的编码。所以在编写程序的时候一定要多方谜案考虑，比如我就因为判断的是“某节点没有左子树并且没有右子树”而出现答案错误。

```c
int judge(int N, int f[], int CodeLen)
{
    int flag = 1, w = 0;
    TNode T = (TNode)malloc(sizeof(struct HuffmanTree));
    T->Left = T->Right = NULL;
    T->weight = -1;
    for(int i = 0; i < N; i++)
    {
        char c, s[N + 1];
        getchar();
        scanf("%c %s", &c, s);
        int length = strlen(s);
        if(length > N) flag = 0;
        w += length * f[i];
        int j = 0;
        TNode tmp = T;
        while(s[j] != '\0')
        {
            if(s[j] == '0')
            {
                if(!tmp->Left)
                {
                    tmp->Left = (TNode)malloc(sizeof(struct HuffmanTree));
                    tmp->Left->weight = -1;
                    tmp->Left->Left = tmp->Left->Right = NULL;
                    tmp = tmp->Left;
                }
                else
                {
                    if(tmp->Left->weight != -1) {
                        flag = 0;
                        tmp = tmp->Left;
                    }
                    else
                        tmp = tmp->Left;
                }
            }
            else
            {
                if(!tmp->Right)
                {
                    tmp->Right = (TNode)malloc(sizeof(struct HuffmanTree));
                    tmp->Right->weight = -1;
                    tmp->Right->Right = tmp->Right->Left = NULL;
                    tmp = tmp->Right;
                }
                else
                {
                    if(tmp->Right->weight != -1) {
                        //printf("**warning**\n");
                        flag = 0;
                        tmp = tmp->Right;
                    }
                    else
                        tmp = tmp->Right;
                }
            }
            j++;
        }
        tmp->weight = i;
        if(tmp->Left != NULL || tmp->Right != NULL)
            flag = 0;

    }
    if(w > CodeLen)
        flag = 0;
    free(T);
    return flag;
}
```

