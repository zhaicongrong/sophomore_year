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

val L = getIntTable(N);

fun sort([], _, _) = []
  | sort(m :: ms, point, update) = 
	if m < point
		then sort(ms, point, m :: update)
		else (List.rev(ms) @ [point] @ update) @ [m];
	
fun deal(_, []) = []
  | deal(f :: fs, [x]) = (f :: x :: fs)
  | deal(front, x1 :: x2 :: xs) =
	if x1 > x2
		then
			sort(List.rev(x1 :: front), x2, []) @ xs
		else
			deal(x1 :: front, x2 :: xs);
			
			
val K = deal([], L);
printIntTable(K);

	

























(*****End*****)
