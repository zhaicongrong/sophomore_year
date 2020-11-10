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


fun printIntTable ( [] ) = ()
  | printIntTable ( x::xs ) = 
    let
	val tmp = printInt(x)
    in
	printIntTable(xs)
    end;

fun printIntInfTable ( [] ) = ()
  | printIntInfTable ( x::xs ) = 
    let
	val tmp = printIntInf(x)
    in
	printIntInfTable(xs)
    end;

fun getIntTable ( 0 ) = []
  | getIntTable ( N:int) = getInt()::getIntTable(N-1);

fun getIntInfTable ( 0 ) = []
  | getIntInfTable ( N:int) = getIntInf()::getIntInfTable(N-1);

(*****Begin*****)

val N = getInt();


val charge = getIntTable(N);

val require = getInt();			
			
			
fun num(c :: charge, sum, count) = 
	if c + sum > require
		then 
			num(charge, sum, count)
		else
			if c + sum < require
				then 
					num(c :: charge, sum + c, count+1)
				else
					count;

val count = num(charge, require, 0);
printInt(count);

(*val N = getInt();



val charge = getIntTable(N);
val Y = getInt();
fun count(_, num, 0) = num
  | count(x :: xs, num, c) = 
		if x > c
			then count(xs, num, c)
			else count(xs, num + (c div x), c - x * (c div x));

printInt(count(charge, 0, Y));
*)




(*****End*****)

