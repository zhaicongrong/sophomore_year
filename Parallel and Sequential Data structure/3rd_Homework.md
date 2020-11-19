Exercise 10.11. What is the expected maximum value of throwing two dice?

$E(X) = \frac{1}{6}\cdot  \frac{1}{6}\cdot 1+\ \frac{1}{6}\cdot \frac{2}{6}\cdot 2 +\frac{1}{6}\cdot \frac{3}{6}\cdot 3+\frac{1}{6}\cdot \frac{4}{6}\cdot 4+\frac{1}{6}\cdot \frac{5}{6}\cdot 5+\frac{1}{6}\cdot \frac{6}{6}\cdot 6=\frac{91}{36}$ 



Exercise 10.20. Rewrite the quicksort algorithm so that it takes a comparison function $cmp\ :\ \alpha \times \alpha \rightarrow order$ and a sequence of type $\alpha \ seq$ , and only uses the comparison once when comparing the pivot with each key. The type $order$ is the set ${Less, Equal, Greater}$. 

```Standard ML
quicksort S = 
	if |s|=0 then S
	else let
		p = pick a pivot from S;
		val s1 = <>;
		val s2 = <>;
		val s3 = <>;
		case cmp(p, S) = 
		  | Less : s1 = s1 ++ s;
		  | Equal : s2 = s2 ++ s;
		  | Greater : s3 = s3 ++ s;
		 map cmp p S;
		(R1, R3) = (quicksort(s1), quicksort(s2))
	in
		R1 ++ s2 ++ R3
	end;
		
```



12-1 Design an algorithm for inserting a given key into a BST.

```
insert(T, k) = 
	case T of
	| Leaf => (Nil, k, Nil)
	| Node(L, k', R) =>
		if (k > k') then 
			case R of
			| Leaf => R = (Nil, k, R)
			| Node => insert(R, k)
		else if (k = k') then () 
		else if (k < k') then
        	     case L of
        	     | Leaf => L = (L, k, Nil)
        	     | Node => insert(L, k)
```



12-2 Design an algorithm for deleting a given key from a tree.

``` Standard ML
fun delete((L, k', R), k) = 
	if (find((L, k', R), k) = false) then T
	else
		if (k < Leaf) 
			then (delete(L, k), k', R)
			else if(k > Leaf) 
					then (L, k', delete(R, k))
					else L||R	
```



Exercise 12.13. Prove correct the functions intersection, difference, and union.

intersect: 

当$t_1$或$t_2$只有一个Leaf时，取交集直接就是Leaf本身，不需要再考虑另一棵树。因此对于边界的处理是正确的。

当$t_1$和$t_2$都是树时，将$t_1$分为左子树，根节点和右子树，并通过根节点$k$拆分树$t_2$。如果$k$在$t_2$中不存在，则丢弃元素$k$，否则将$k$还是作为根节点，并继续分别对$t_1$$t_2$的左子树和右子树进行intersect操作。输出的元素必定同时存在两棵树中。

由于intersect是递归操作，结束递归调用的条件是某一棵树仅有Leaf，因此会对每一个$t_1$树中的小于等于$t_2$树中的最大元素的元素都进行split操作。因此两棵树中同时存在的元素必定会被返回。

因此intersect函数是正确的。

difference:

当$t_1$为leaf时，$t_1$于$t_2$的差集必定为Leaf。同理，当$t_2$为Leaf时，两者差集必定为$t_1$本身。

在$t_1$或$t_2$不为Leaf时，和intersect同样的操作进行树$t_2$的拆分。唯一不同的是如果$t_1$的根节点如果在$t_2$中不存在就返回根节点的值，再分别对$t_1 t_2$的左子树右子树进行difference操作。difference操作会对$t_1$中每个小于$t_2$最大元素的元素进行split操作，而所有大于最大元素的元素都会直接被返回。所以每个在$t_1$而不在$t_2$中的元素都会被返回。因此该算法是正确的。

union:

当$t_1$为leaf时，$t_1$于$t_2$的并集必定为$t_2$。同理，当$t_2$为Leaf时，两者并集必定为$t_1$。

在$t_1$或$t_2$不为Leaf时，利用$t_1$的根节点对树$t_2$进行拆分。分别对$t_1 t_2$的左子树右子树递归地进行并集操作，并合并结果。union操作只会去除两棵树中重复地元素并只留下一个元素，保留了所有只出现一次的元素。因此该算法是正确的。



$T_1$ doesn’t have to be perfectly balanced as we assumed
A similar reasoning can be used to show that $T_1$ only has to be approximately balanced.

想要达到$O(mlg\frac{n}{m})$ 的复杂度并不需要要求树$T_1$保持完全平衡，因为推导work的条件是work的递归式是leaf dominated的。因此只需要保证$T_1$大致是平衡的，即$T_1$的高度在$lg|T_1|$的线性范围内，都可以达到此推导出的复杂度。



Exercise 12.17 Prove that if the priorities are unique, then there is exactly one tree structure that satisfies the Treap properties.





