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

fun printEndOfLine () =
    print("\n");

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
val l1 = getInt();

val n1 = getIntTable(l1);

val l2 = getInt();

val n2 = getIntTable(l2);

fun Add([], [], c) = (*已经倒置*) if (c=0 ) then [] else [c]
  | Add(a::ass, [], c) = 
        if(a + c > 9)
            then (a+c-10)::Add(ass, [], 1)
            else (a+c)::Add(ass, [], 0)
  | Add([], b::bs, c) = 
        if(b + c > 9)
            then (b+c-10)::Add(bs, [], 1)
            else (b+c)::Add(bs, [], 0)
  | Add(a::ass, b::bs, c) = 
    if(a+b+c>9) then (a+b+c-10)::Add(ass, bs, (a+b+c) div 10)
                else (a+b+c)::Add(ass, bs, 0);
val addresult = Add(rev n1, rev n2, 0);

printIntTable(rev addresult);

fun minus([], [], c) = []
  | minus(a::ass, [], c) = 
        if (a-c<0) then (a-c+10)::minus(ass, [], ~1)
                   else (a-c)::minus(ass, [], 0)
  | minus(a::ass, b::bs, c) = 
        if(a-b-c<0) then (a-b-c+10)::minus(ass, bs, ~1)
        else (a-b-c)::minus(ass, bs, 0);

val minusresult = minus(rev n1, rev n2, 0);

fun removezero([x]) = [x]
  | removezero(x::xs) = 
        if (x=0) then removezero(xs)
                 else x::xs;

printIntTable(removezero(rev minusresult));

fun onemultiply(a, [], c) = [c]
  | onemultiply(a, b::bs, c) = 
        if (a * b + c> 9) then ((a*b+c)mod 10)::onemultiply(a, bs, (a*b+c) div 10)
                          else (a*b+c)::onemultiply(a, bs, 0);

fun multiply([], bs) = [0]
  | multiply(a::ass, bs) = 
        Add(onemultiply(a, bs, 0), 0::multiply(ass, bs), 0);

val multiplyresult = multiply(rev n1, rev n2);

printIntTable(removezero(rev multiplyresult));
    







(*****End*****)

