fun quorem (ts, (n,b)::us) = 
    let fun dividing ([], qs) = (rev qs, [])
          | dividing ((m,a)::ts, qs) = 
                if m<n then (rev qs, (m,a)::ts)
                else dividing (sum (ts, termprod ((m-n, ~a/b), us)),(m-n, a/b)::qs)
    in dividng (ts, []) end;