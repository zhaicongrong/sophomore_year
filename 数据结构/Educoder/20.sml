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

val Dx = getInt();
val Dy = getInt();
val X = getInt();
val Y = getInt();

fun security([a,b]) : bool = 
    if (a = X andalso b = Y) orelse (a = X+1 andalso b = Y+2) orelse (a = X+1 andalso b = Y-2) orelse (a = X-1 andalso b = Y+2) orelse (a = X-1 andalso b = Y-2) orelse (a = X+2 andalso b = Y+1) orelse (a = X+2 andalso b = Y-1) orelse (a = X-2 andalso b = Y+1) orelse (a = X-2 andalso b = Y-1)
      then false
      else true;
fun try(co, de) :bool = 
    if (security([co,de]))
      then true 
      else false;

fun journey(x,y) = 
    if(x > Dx orelse y>Dy) then 0
      else
        if(try(x,y))  then
          if(x=Dx andalso y=Dy) 
              then 1
              else journey(x+1,y)+journey(x,y+1)
        else 0;

printInt(journey(0,0));
























(*****End*****)

