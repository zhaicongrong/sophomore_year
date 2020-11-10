fun bincarry (0, ps) = ps
  | bincarry (1, []) = [1]
  | bincarry (1, p::ps) = (1-p) :: bincarry(p, ps);
  
fun binsum (c, [], qs) = bincarry (c,qs)
  | binsum (c, ps, []) = bincarry (c,qs)
  | binsum (c, p::ps, q::qs) = 
		((c+p+q) mod 2) :: binsum ((c+p+q) div 2, ps, qs);
		
fun binprod ([], _) = []
  | binprod (0::ps, qs) = 0 :: binprod(ps, qs)
  | binprod (1::ps, qs) = binsum(0, qs, 0::binprod(ps,qs));
  
binprod ([1, 1, 0, 1], [0, 1, 1, 1, 1]);

