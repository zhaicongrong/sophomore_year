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

(*****Begin*****)			 
val N = getInt();
val A = getIntTable(N);

fun merge([], ys) = ys : int list
  | merge(xs, []) = xs
  | merge(x::xs, y::ys) = 
    if x < y then x::merge(xs, y::ys)
             else y::merge(x::xs, ys);

fun mergesort xs = 
    let fun sort(0, xs) = ([], xs)
          | sort(1, x::xs) = ([x], xs)
          | sort(n, xs) = 
                let val (l1, xs1) = sort((n+1) div 2, xs)
                    val (l2, xs2) = sort(n div 2, xs1)
                in (merge (l1,l2), xs2)
                end 
        val (l, _) = sort (length xs, xs)
    in l end;

val B = mergesort(A);
printIntTable(B);
(*****End*****)

