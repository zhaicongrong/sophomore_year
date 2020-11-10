2+1;
val pi = 3.1415;
fun area r = pi * r * r;
area 1.0;

fun min(a,b) : real = if a < b then a else b;

local
	fun itlib (n, prev, curr) : int = 
		if n=1 then curr
		else itfib (n-1, curr, prev+curr)
in
	fun fib (n) = itfib(n, 0, 1)
end;

val pi = 4.0 * Math.atan 1.0
and e = Math.exp 1.0
and log2 = Math.ln 2.0;

val one = "BONG ";
val three = one ^ one ^ one;
val five = three ^ one ^ one;

val one = three and three = one;

fun pos d = neg(d-2.0) + 1.0/d 
and neg d = if d>0.0 then pos(d-2.0) - 1.0/d
					 else 0.0;
					 
4.0 * pos(201.0);
4.0 * neg(201.0);
4.0 * pos(8003.0);
4.0 * neg(8003.0);

fun sum (d, one) = 
	if d > 0.0 then sum(d-2.0, ~one) + one/d else 0.0;
	
