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
val standard = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];

val n = getIntInf();

fun quick_Multiply(a, b, c) = 
    let
        val tmpa = a mod c;
        val tmpb = b mod c;
    in
        (a * b) mod c
    end;

fun quick_Power(a, b, c, result) = 
    if (b = 0) then result
    else
        if (b mod 2 = 0) 
            then quick_Power(a*a mod c, b div 2, c, result)
        else
            quick_Power(a*a mod c, b div 2, c, result*a mod c);

fun resolve(x, s, t) = (*初始值，s = 0, t = x, 输入的x实为x-1*)
    if(x mod 2 = 0) then resolve(x div 2, s+1, t div 2)
                    else (s, t);

fun twiceinspect(a, s, t) = 
    if(a >= n) then true
    else
        let 
            val b = quick_Power(a, t, n)
            val h = s
            
            val k = quick_Multiply(b, b, x)
            val judge = true
            if ((k = 1) andalso (b<>1) andalso (b<>x-1)) 
                then judge = false
                else 
                

(*二次探测*)
fun try([] s, t) = true
  | try(a::as, s, t) = 
        if (twiceinspect(a, s, t) = true) 
            then try(as, s, t)
            else false;
    




fun MillerRabin(x) = 
    if (n = 2) then true
    else
        if (n mod 2 = 1) then false
            else
                let
                    val (s, t) = resolve(n-1, 0, n-1)






(*****End*****)

