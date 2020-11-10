fun upto (m,n) =
	if m>n then [] else m :: upto(m+1, n);
upto (2,5);

fun prodof3 [i,j,k] : int = i*j*k;
3 :: [2,3,4,5];
fun prod [] =1
  | prod (n::ns) = n * (prod ns);
  
prod[2,3,4,5,6,7];

fun maxl [m] : int = m
  | maxl (m::n::ns) = if m>n then maxl(m::ns)
							 else maxl(n::ns);

val max = maxl[1,2,10,5,~2];

fun factl (n) = prod(upto (1,n));

(*表的测试和分解*)
fun null [] = true
  | null (_::_) = false;
  
fun hd (x::_) = x;
fun tl (_::xs) = xs;
