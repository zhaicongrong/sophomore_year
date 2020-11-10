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

fun getIntVector ( 0 ) =  Vector.fromList []
  | getIntVector ( N:int) = Vector.fromList(getIntTable(N));

fun getIntInfVector ( 0 ) = Vector.fromList []
  | getIntInfVector ( N:int) = Vector.fromList(getIntInfTable(N));


(*****Begin*****)

(*val N = getInt();
val List = getIntTable(N);

fun getSum([]) = 0
  | getSum(x::xs) = x + getSum(xs);

fun divide([]) = [[]]
  | divide([x]) = [[x, 0]]
  | divide(x1::x2::xs) = [x1,x2] :: divide(xs);

fun get_parallel_sum([x]) = x
  | get_parallel_sum(A) = get_parallel_sum(map getSum(divide(A)));

val M = get_parallel_sum(List);
printInt(M);*)

val N = getInt();

val V = getIntVector(N);

fun parallel_sum(left, right) = 
    if left + 1 = right 
        then Vector.sub(V, left) + Vector.sub(V, right)
        else
            if left = right
                then Vector.sub(V, left)
                else
                    parallel_sum(left, (left+right)div 2) + parallel_sum((left+right)div 2+1, right);

val sum = parallel_sum(0, N-1);
printInt(sum);

(*****End*****)
