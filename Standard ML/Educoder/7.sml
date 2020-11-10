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
val num = getIntInf();
fun sum( n : IntInf.int, k : IntInf.int) = 
	if k = 0
		then n
		else
			let
				val tmp = getIntInf()
				val n' = n + tmp
			in
				sum(n', k - 1)
			end;
printIntInf(sum(0, num));
(*****End*****)
