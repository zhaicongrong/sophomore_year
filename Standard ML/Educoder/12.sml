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

val N = getIntInf();

fun insert( X , N : IntInf.int) = 
	if N > 0 
		then
			let
				val tmp = getIntInf()
				val Y = tmp :: X
			in
				insert(Y, N - 1)
			end
		else
			X;
val X = insert([], N);

val judge = null X;

fun MAX(X : IntInf.int list, tmpmax : IntInf.int) = 
	if null X
		then tmpmax
		else if hd X > tmpmax
				then
					MAX(tl X, hd X)
				else
					MAX(tl X, tmpmax);

if null X = true
	then printString("Empty Table")
	else
		printIntInf(MAX(X, hd X));
	
			

		













(*****End*****)

