#### 12-3 Minimum height

Prove that the minimum possible height of a binary search tree with $n$ keys is $log_2(n+1)$

假设有二叉搜索树的高度为$k$，则至多有$2^k-1$个元素。因此有$2^k-1\geq n$,即$k\geq log_2(n+1)$。

#### 12-4 Finding Ranges

Given a BST $T$ and two keys $k_1\leq k_2$ return a BST $T'$ that contains all the keys in $T$ that fall in the range $[k_1, k_2]$.

首先找到$T$中所有大于等于$k_1$的元素，再筛选所有小于等于$k_2$的元素。

```pascal
CreateNewTree(T, k1, k2, T') = 
	case T of
	  | Leaf => Leaf
	  | Node(L, value, R) => 
	  	let
    		if((value >= k1) andalso (value <= k2))
    			insert(T', value);
            CreateNewTree(L, k1, k2, T');
            CreateNewTree(R, k1, k2, T');
        in
            T'
        end;
```

#### 12-5 Tree rotations

In a BST $T$ where the root $v$ has two children, let $u$ and $w$ be the left and right child of $v$ respectively. You are asked to reorganize $T$. For each reorganization design a constant work and span algorithm.

- **Left rotation** . Make $w$ the root of the tree.

  ```pascal
  fun leftRotation(v) = 
  	let
  		val (u, k, w) = Node(v);
  		val (L', k', R') = Node(w);
  	in
  		makeNode(makeNode(u, k, L'), k, R')
  	end;		
  ```

  

- **Right rotation**. Make $u$ the root of the tree.

````pascal
fun RightRotation(v) = 
	let
		val (u, k, w) = Node(v);
		val (L', k', R') = Node(u);
	in
		makeNode(L', k', makeNode(R', k, w))
	end;
````

#### 12-6  Size as reduced value

Show that size information can be computed as a reduced value. What is the function to reduce over?

我没有搞清楚reduced value的含义。

```pascal
fun size( T ) = 
  case T of
    TLeaf => 0
    TNode(T) = (L, k, R) => size(L) + size(R) + 1;
```

#### 12-7 Implementing splitRank

Implement the splitRank function.

#### 12-8 Implementing select

Implement the select function using splitRank.

