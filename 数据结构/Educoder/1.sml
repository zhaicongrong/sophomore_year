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
	val N = getIntInf();
	val M = getIntInf();
	fun pow(a : IntInf.int, b : IntInf.int, result : IntInf.int) : IntInf.int= 
		if b = 0 then result
				 else if b mod 2 = 0
							then pow(a * a mod M, b div 2, result)
							else pow( a * a mod M, (b - 1) div 2, a * result mod M);
	val modulo = pow(A, N, 1) mod M;
	printIntInf(modulo);
(*****End*****)
