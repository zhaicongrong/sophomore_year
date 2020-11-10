fun mult [] = 1
  | mult (x::L) = x * (mult L);

fun mult' ([],a) = a
  | mult' (x::L, a) = mult' (L, x*a);
  
mult' ([2,3,4,5], 6);
mult' ([1,2,3], 1);

fun Mult' ([], a) = a
  | Mult' (x::L, a) = Mult'(L, a) * mult(x);
  
Mult'([[1,2],[2,3],[3,4]],4);