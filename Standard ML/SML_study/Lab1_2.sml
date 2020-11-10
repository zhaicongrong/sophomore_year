fun mult [] = 1
  | mult (x::L) = x * (mult L);
  
mult [2,3,4,5];