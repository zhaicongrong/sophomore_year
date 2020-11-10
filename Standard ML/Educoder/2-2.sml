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
val M = getInt();
val K = getInt();

val A = Array2.array(N, N, 99999);
val L = Array.array(N, 99999);
val Log = Array.array(N, 0);

Array.update(L, K-1, 0);
val List = getIntTable(3 * M);
fun getArray2([]) = 0
  | getArray2(x::y::w::ls) = 
        if (Array2.sub(A, x-1, y-1) > w)
            then (Array2.update(A, x-1, y-1, w);Array2.update(A, y-1, x-1, w);getArray2(ls))
        else
            getArray2(ls);

val tmp' = getArray2(List);

fun getArray(i) = 
    if (i=K-1) then 0
    else
        (Array.update(L, i, Array2.sub(A, K-1, i));getArray(i+1));

val tmp2' = getArray(0);

Array.update(Log, K-1, 1);

fun findMin(index,(tmpindex, tmpmin)) = 
    if index>N-1 then (tmpindex, tmpmin)
        else
            if ((Array.sub(L, index) < tmpmin) andalso (Array.sub(Log, index)=0)) 
                then findMin(index+1, (index, Array.sub(L, index)))
            else 
                findMin(index+1, (tmpindex, tmpmin));

fun shrink(minindex, i) = 
    if i>N-1 then 0
    else
        if(Array.sub(L, i)>Array.sub(L, minindex)+Array2.sub(A, K-1, i))
            then (Array.update(L, i, Array.sub(L, minindex)+Array2.sub(A, K-1, i));shrink(minindex, i+1))
            else
                shrink(minindex, i+1);

fun Dijkstra(times) =
    if (times>N) 
        then 0
        else if (times<0) 
                then ~1
            else
            let
                val tmp = findMin(0,(~1, 99999))
                Array.update(Log, #1 tmp, 1)
                shrink(#2 tmp, 0)
            in
                Dijkstra(times+1)
            end;

val tmp3' = Dijkstra(1);


(*****End*****)