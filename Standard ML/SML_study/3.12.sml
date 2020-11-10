fun squares r = 
  let fun between (x,y) = 
    let val diff = r - x*x
      fun above y = 
        if y>x then []
        else if y*y<diff then above(y+1)
        else if y*y=diff then (x,y)::between(x-1,y+1)
        else between(x-1,y)
    in above y end;
    val firstx = floor(Math.sqrt(real r));
  in between (firstx, 0) end;
  (*注意此处的嵌套，我觉得还是非常复杂的。*)