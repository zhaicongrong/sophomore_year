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

```pascal
type T = TLeaf
	   | TNode of (T * K * Z * T);

reducedVal T = 
	case T of
	  TLeaf => 0
	| TNode(_, _, s, _) => s;

makeNode (L, k, R) = 
	let
		s = reducedVal(L) + 1 + reducedVal(R)
	in
		TNode(L, k, s, R)
	end;
	   
```

#### 12-7 Implementing splitRank

Implement the splitRank function.

```pascal
fun splitRank(T, i) = 
case T of = 
    Leaf => (Leaf, -1, Leaf)
  | Node(L, k, R) =>
	case compare(k, i) of = 
		LESS => 
			let
				(L', R') = splitRank(R, i);
			in
				(makeNode(L, k, L'), R')
			end;
		EQUAL => (L, R);
		GREATER => 
			let
				(L', R') = splitRank(L, i);
			in
				(L, makeNode(R', k, R))
			end;
```

#### 12-8 Implementing select

Implement the select function using splitRank.

```pascal
fun select(T, i) = 
	case T of
		Leaf => Raise Exception of OutOfRange
	  | Node(_, k, _) =>
	  	let
			(L, R) = splitRank(T, k)
		in
			case compare(|L|, i) of
				LESS => select(R, i - 1 - |L|)
				EQUAL => k
				GREATER => select(L, i)
		end;    		
```

#### Exercise 13.3. Convince yourself that there is no way to create an infinite sized set using the interface and with finite work.

创建集合中的每一个元素都至少需要$O(1)$的work，因此如果需要创建一个无限大也需要无限大的work。无法通过sequence接口中的函数，通过有限的work进行创建。

#### Exercise 12.8. Show that the work of the bulk operations is $O(n+m)$, i.e., never no more than the sum of the sizes of the inputs.

由书本上得到，intersect，union和difference的work都是$O(mlog(1+\frac{n}{m}))$。

因为对于$x>0$，都有$log(1+x)<x<1+x$

因此$O(mlog(1+\frac{n}{m}))\ <\ O(m\dot (1\ +\ \frac{n}{m})) = O(n\ +\ m)$

因此不会大于输入的总长度。

#### 12.10. What is the work and span of each of the implementations of fromSeq above.

$fromseq A\ = \ I^{Set.insert\ \varnothing}\ A$ : 需要按照顺序地调用$|A|$次insert操作。并且无法进行并行操作，因此$W$和$S$都是$O(n)$的复杂度。

$fromseq\ A = R^{Set.union\  \varnothing}\ A$：得到有关work的递归式：$W(n)\ =\ 2\cdot W(\frac{n}{2})\ +\ O(n)$， reduced操作将长为$n$的串分为两半再进行处理，最后归并时union操作需要的$W$为$O(mlog(1+\frac{n}{m})$，,因此得到work的复杂度时$O(n^2)$。

得到有关span的递推式：$S(n)\ =\ S(\frac{n}{2})\ +\ O(n)$，因此得到$S(n)\ =\ O(n)$。

#### Exercise 13.24. Describe how to implement previous and next using the other ordered set functions.

`privious(S, A) = Select(S, Rank(S, A) - 1)`

`next(S, A) = select(S, Rank(S, A) + 1)`

#### 13-3 Union on Different Sizes

Based on the cost specification for Sets, what is the assymptotic work and span for taking the union of two sets one of size n and the other size $\sqrt{n}$? You can assume the comparison for sets takes constant work. Please simplify as much as possible.

$W\ =\ O(nlog(1\ +\ \frac{m}{n}))\ =\ O(\sqrt{n}log(1+\frac{n}{\sqrt{n}}))=\sqrt{n}log(1+\sqrt{n})=\sqrt{n}logn$

$S\ =\ O(logn)$

#### 13-4 Cost of Table Collect

The following code implements Table.collect(S).

$Seq.reduce (Table.union\ Seq.append) <> \{k-><v>:v\in S\}$

Derive (tight) asymptotic upper bounds on the work and span for the code in terms of $n\ =\ |S|$. You can assume the comparison function used by the table takes constant work, and that the Sequence is a array sequence. You don't need a proof.

seq.append操作需要的 $W=O(n+m),S=1$，table.union需要 $W=mlog(1+\frac{n}{m})$和$S=lg(n+m)$。

得到递推关系式：$W(n)=2\cdot W(n/2)+O(n)+O(nlogn)$， 因此$W(n)=nlog^2n$。

同样，$S(n)=S(n/2)+O(1)+log(2n)$， 得到$S(n)=log^2n$。

#### 13-6 Union on Multiple Sets

The following code takes the union of a sequence of sets:

`fun UnionSets(S) = Seq.reduce Set.Union {} S`

For example

`UnionSets <{5.7}, {3, 1, 5, 2}, {2, 5, 8}>`

would return the set {1, 2, 3, 5, 7, 8}. Derive (tight) asymptotic upper bounds for the work and span for `UnionSets` in terms of $n=|S|$ and $m=\sum_{x\in S}|x|$. You can assume the comparison used for the sets takes constant work. Please keep your analysis to under a page. We do not need a formal proof. An explanation based on the tree-methond is sufficient.

假设一种理想情况：每一个sequence长度都为$\frac{m}{n}$。

$W=\frac{n}{2}\cdot \frac{m}{n}\cdot log2+\frac{n}{4}\cdot \frac{2m}{n}+...=mlogn$。

$S=log\frac{m}{n}+log\frac{2m}{n}+log\frac{4m}{n}+...=\sum_{i=1}^{logn}i+lognlogm-{(logn)}^2=lognlogm$。

由于$m>n$，有$S=lognlogm$作为上限。