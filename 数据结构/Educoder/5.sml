fun printInt (a:int) =
    print(Int.toString(a)^" ");

fun printIntInf (a:IntInf.int) =
    print(IntInf.toString(a)^" ");


fun printReal (a:real) =
    print(Real.toString(a)^" ");

fun printString (a:string) =
    print(a^" ");

fun getInt () =
    Option.valOf (TextIO.scanStream (Int.scan StringCvt.DEC) TextIO.stdIn);

fun getIntInf () =
    Option.valOf (TextIO.scanStream (IntInf.scan StringCvt.DEC) TextIO.stdIn);

fun getReal () =
    Option.valOf (TextIO.scanStream (Real.scan) TextIO.stdIn);
(*****Begin*****)
	val A = getIntInf();
	val B = getIntInf();
	val X = ((0 : IntInf.int,1 : IntInf.int),(1 : IntInf.int,1 : IntInf.int));
	
	fun mul( ((a : IntInf.int, b : IntInf.int) , (c : IntInf.int , d : IntInf.int)), ((e : IntInf.int, f : IntInf.int) , (g : IntInf.int , h : IntInf.int))) = 
		(((a*e+b*g) mod B,(a*f+b*h)mod B),((c*e+d*g)mod B,(c*f+d*h)mod B));
	
	fun cal(((a : IntInf.int, b : IntInf.int) , (c : IntInf.int , d : IntInf.int)), n : IntInf.int) = 
		if n = 1 
			then ((a,b),(c,d))
			else if n mod 2 = 0
				then cal(mul(((a,b),(c,d)),((a,b),(c,d))),n div 2)
				else mul(((a,b),(c,d)),cal(mul(((a,b),(c,d)),((a,b),(c,d))),(n-1) div 2));
	
	fun exert((a : IntInf.int, b : IntInf.int) , (c : IntInf.int , d : IntInf.int)) = 
		c + d -a -b;
	val result = exert(cal(X, A)) mod B;
	printIntInf(result);
	(*val tmp = exert(cal(X,A));
	printIntInf(tmp);*)
(*****End*****)
