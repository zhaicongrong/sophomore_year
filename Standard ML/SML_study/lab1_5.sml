fun double (0:int):int = 0
  | double n = 2 + double(n-1);
  
fun square (1:int):int = 1  
  | square n = double(n)-1 + square(n-1);
  
square(13);
square(5);