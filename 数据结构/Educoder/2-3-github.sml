fun printInt (a:int) =
    print(Int.toString(a)^" ");

fun getInt () =
    Option.valOf (TextIO.scanStream (Int.scan StringCvt.DEC) TextIO.stdIn);

fun printIntTable ( [] ) = ()
  | printIntTable ( x::xs ) = 
    let
	val tmp = printInt(x)
    in
	printIntTable(xs)
    end;

fun getIntTable ( 0 ) = []
  | getIntTable ( N:int) = getInt()::getIntTable(N-1);

fun printArray ( Arr ) =
    let
	val cur = ref 0
	val len = Array.length(Arr)
    in
	while !cur < len
	do
	(
	  printInt(Array.sub(Arr,!cur));
	  cur := !cur + 1)
    end;

fun printString( s ) = print(s ^ " ");

val N = getInt()

val list = getIntTable(N);

fun process([], newlist, length, maxlength) = maxlength
  | process(x::xs, [], length, maxlength) = 
        if(length>maxlength) 
            then process(xs, [x], 1, length)
            else
                process(xs, [x], 1, maxlength)
  | process(x::xs, l::ls, length, maxlength) = 
        if(x=1 andalso l=0)
            then process(xs, ls, length+2, maxlength)


