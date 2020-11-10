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
val N = getInt();

val Q = getInt();

val Vector1 = getIntVector(N);

val Vector2 = getIntVector(Q);

fun find(element, left, right, mid) =
    if (left>right) then ~1 
    else
      if(Vector.sub(Vector1,mid) < element) then find(element, mid+1,right,(mid+1+right)div 2)
      else if(Vector.sub(Vector1,mid) > element) then find(element, left, mid-1,(left+mid-1)div 2)
           else mid;
val Left = 0;
val Right = Vector.length(Vector1) - 1;

fun scan(v, tip) = 
	if tip = Vector.length(v)
		then []
		else
			find(Vector.sub(Vector2,tip),Left, Right, (Left + Right) div 2) :: scan(v, tip + 1);

printIntTable(scan(Vector2, 0));

















(*****End*****)

