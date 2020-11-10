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
 val M = getIntInf();
 val N = getIntInf();
 
 fun formlist(start : IntInf.int, endp : IntInf.int, cur : IntInf.int) = 
	if cur > endp
		then []
		else cur :: formlist(start, endp, cur + 1);
		
fun printlist([]) = ()
  | printlist(x :: xs) = 
		let
			val tmp = printIntInf(x)
		in
			printlist(xs)
		end;
		
val mylist = printlist(formlist(M, N, M));


			
 
 
 
 
 
 
 
 
 
 
 
 
 
(*****End*****)

