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

val a = getIntInf();
val b = getIntInf();
val c = getIntInf();
val d = getIntInf();

fun gcd(m : IntInf.int, n : IntInf.int) = 
	if m = 0 
		then n
		else gcd(n mod m, m);

fun filter(a : IntInf.int, b : IntInf.int, n : IntInf.int) = (a div n, b div n);

val X = filter(a, b, gcd(a, b));
val Y = filter(c, d, gcd(c, d));

fun tmp(n : IntInf.int, y : IntInf.int) = 
	if n < y
		then gcd(n, y)
		else gcd(y, n);

val tmp' = tmp(b, d);
fun plus((x : IntInf.int, y : IntInf.int),(m : IntInf.int, n : IntInf.int)) = 
			let
				val den = y * n div tmp'
				val x' = x * n div tmp'
				val m' = m * y div tmp'
			in
				(x'+m',y * n div tmp')
			end;
			
			
val (s,t) = plus(X,Y);
printIntInf(s);
printString(" ");
printIntInf(t);
(*fun exert( a : IntInf.int, b : IntInf.int) = 
	let
		printIntInf(a)
		printString(" ")
		printIntInf(b)
	in
		1
	end;
exert(plus(X,Y));*)
(*****End*****)
