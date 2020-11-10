fun mult [] = 1
  | mult (x::L) = x * (mult L);

fun Mult[] = 1
  | Mult(r::R) = mult(r) * Mult(R);
  
Mult [[2,5,3],[2,1],[9,7,6],[5,4,3,2,1]];