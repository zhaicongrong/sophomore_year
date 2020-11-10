fun merge([], ys) = ys : real list
  | merge(xs, []) = xs
  | merge(x::xs, y::ys) = 
        if x<=y then x::merge(xs, y::ys)
                else y::merge(x::xs, ys);

fun tmergesort [] = []
  | tmergesort [x] = [x]
  | tmergesort xs = 
        let val k = length xs div 2
        in merge (tmergesort (List.take(xs,k)),
                  tmergesort (List.drop(xs,k)))
        end;

fun mergepairs([l], k) = [l]
  | mergepairs(l1::l2::ls, k) = 
    if k mod 2 = 1 then l1::l2::ls
    else mergepairs(merge(l1,l2)::ls,k div 2);

mergepairs ([[1.0],[2.0],[4.0],[3.0],[5.0],[7.0]],6);
   