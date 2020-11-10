fun sum ([], us) = us 
  | sum (ts, []) = ts
  | sum ((m,a)::ts, (n,b)::us) = 
        if m>n then (m,a)::sum(ts, (n,b)::us)
        else if n>m then (n,b)::sum(m,(m,a)::us)
        else
            if Real.==(a+b,0.0) then (ts,us)
                                else (m, a+b)::sum(ts, us);r