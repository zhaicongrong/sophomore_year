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

(*****Begin*****)			 
val N = getInt();

val mylist = getIntTable(N);

fun myreverse(number) = 
    if (number = 0) then 1
    else if(number = 1) then 0
    else ~1;

val anotherlist =rev(map myreverse mylist);

fun stack([], _, maxpair, tmppair) = Int.max(maxpair, tmppair)
  | stack(x::xs, [], maxpair, tmppair)= 
        if(x=0) 
            then stack(xs, [x], Int.max(maxpair, tmppair), 0)
            else stack(xs, [], Int.max(maxpair, tmppair), 0)
  | stack(x::xs, y::ys, maxpair, tmppair) = 
        if((x=1) andalso (y=0)) 
            then stack(xs, ys, maxpair, tmppair+2)
            else stack(xs, x::y::ys, maxpair, tmppair);

val matchone = stack(mylist, [], 0, 0);

val matchtwo = stack(anotherlist, [], 0, 0);

printInt(Int.min(matchone, matchtwo));


(*****End*****)

