+ How many comparisons are needed to find the second largest number on a sequence of n numbers?

  ​	Divide and conquer algorithm: $\frac{2}{3}n$ 

  ​	

  ```
  Algorithm FindSecondMax(N, A[1..N]) returns
  begin
  	Compared←FindMaxTournament(1,N,A[1..N]);
  	Compared2←FindMaxTournament(2,Compared[0],Compared[2..Compared[0]]);
  	return Compared2[1]
  end
  ```

  ```
  Function FindMaxTournament(I,J, A[I..J],N) returns Compared[0..K]
  begin
  	if I = J then //base case
  		Compared[0..N];
  		Compared[0]← 1;
  		Compared[1]← A[I];
  		return Compared;
  	endif
  	Compared1← FindMaxTournament(I, I+(J-I)/2, A,N);
  	Compared2← FindMaxTournament(1+I+(J-I)/2,J, A,N);
  	if Compared1[1]>Compared2[1] then
  		K←Compared1[0]+1;
  		Compared1[0]←K;
  		Compared1[K]←Compared2[1];
  		return Compared1;
  	else
  		K←Compared2[0]+1;
  		Compared2[0]←K;
  		Compared2[K]←Compared1[1];
  		return Compared2;
  	endif
  end
  ```

  This algorithm's work is $O(n+logn-2)$ 	

  so I till now I don't know how divide and conquer algorithm can make the work become $O(\frac{3}{2}n)$ . so sad~

  

  naive algorithm : $O(2n-3)$ this is like quicksort, just pick a standard number and then contract the problem. The number of comparison is $n-1+(\frac{1}{2}n-1)+...$ 

  

  + expected bonds

    + the average case
    + might be quite large
    + is used to analyze the work

  + high-probability bonds

    + it is very unlikely that the cost will be above some bound
    + is used to analyze the span(cost of the longest time)

    

    

    ```
    max2 S = 
    let
    	replace ((m1, m2), v) = 
    		if v<m2 then (m1,m2)
    		else if v<=m1 then (m1,v)
    		else (v, m1)
    	val init = if S1>=S2 then (S1, S2) else (S2, S1)
    in
    	iter replace init S<3,...,n>
    end
    ```

    

    the number of comparison: Y

    $E(Y) = 1\ +\ n-2\ +\ \sum_{i=3}^{n}{X_i}$ 

    and $E(X_i)=\frac{2}{i}$ 

    

    ##### Finding the kth smallest element

    ![幻灯片 1 - Adobe Acrobat Pro DC](C:\Users\ZHT\Desktop\幻灯片 1 - Adobe Acrobat Pro DC.jpg)

    

    

  

  

  

  