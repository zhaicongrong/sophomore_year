fun evenP(0:int):bool = true
  | evenP 1 = false
  | evenP n = evenP(n-2);
  
fun oddP(0:int):bool = false
  | oddP 1 = true
  | oddP n = oddP(n-2);


oddP(3);
oddP(4);
oddP(12);
oddP(15);