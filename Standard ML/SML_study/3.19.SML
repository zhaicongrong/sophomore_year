fun ins (x, []) : real list = [x]
  | ins (x, y::ys) = 
        if x<=y then x::y::ys
                else y::ins(x,ys);

fun insort [] = []
  | insort (x::xs) = ins(x, insort xs);