Exercise 10.11. What is the expected maximum value of throwing two dice?

$E(X) = \frac{1}{6}\cdot  \frac{1}{6}\cdot 1+\ \frac{1}{6}\cdot \frac{2}{6}\cdot 2 +\frac{1}{6}\cdot \frac{3}{6}\cdot 3+\frac{1}{6}\cdot \frac{4}{6}\cdot 4+\frac{1}{6}\cdot \frac{5}{6}\cdot 5+\frac{1}{6}\cdot \frac{6}{6}\cdot 6=\frac{91}{36}$ 



 ![幻灯片 1 - Adobe Acrobat Pro DC](C:\Users\ZHT\Desktop\幻灯片 1 - Adobe Acrobat Pro DC.jpg)

Exercise 10.20. Rewrite the quicksort algorithm so that it takes a comparison function $cmp\ :\ \alpha \times \alpha \rightarrow order$ and a sequence of type $\alpha \ seq$ , and only uses the comparison once when comparing the pivot with each key. The type $order$ is the set ${Less, Equal, Greater}$. 

```Standard ML
quicksort S = 
	if |s|=0 then S
	else
		p = pick a pivot from S;
		case cmp(S, p) = 
		  | Less :
		val front = <>;
		val behind = <>;
		
```



