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

val Log = Array.array(100, ~1);

val examplelist = getIntTable(N*3);

fun elementupdate(l, h, r) = 
    if (l=r) then 
                if(Array.sub(Log, l)= ~1)
                    then
                        (Array.update(Log, l, 0);[h])
                    else
                        [h]
    else
        if(h>Array.sub(Log, l))
            then
                (Array.update(Log, l, h);elementupdate(l+1, h, r))
            else
                elementupdate(l+1, h, r);

fun myupdate([]) = []
  | myupdate(l::h::r::restlist) = 
      elementupdate(l,h,r)::myupdate(restlist);

val tmp' = myupdate(examplelist);
(*printArray(Log);*)

fun printArray2(index, tmp) = 
    if(index=99) then ()
    else
        if((Array.sub(Log, index)<>tmp) andalso (Array.sub(Log, index) <> ~1)) 
            then 
                (printInt(index);printInt(Array.sub(Log, index));print("\n");printArray2(index+1, Array.sub(Log, index)))
            else
                printArray2(index+1, tmp);
if(N=0) 
    then printInt(0)
    else
        printArray2(1, 0);

(*****End*****)

