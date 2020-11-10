fun dotprod([], []) = 0.0
  | dotprod(x::xs, y::ys) = x*y + dotprod(xs, ys);
  
fun rowprod(row, []) = []
  | rowprod(row, col::cols) = 
						dotprod(row, col) :: rowprod(row, cols);

fun rowlistprod([], cols) = []
  | rowlistprod(row::rows, cols) = 
			rowprod(row, cols) :: rowlistprod(rows,cols);

fun headcol [] = []
  | headcol ((x::_) :: rows) = x :: headcol rows;

fun tailcols [] = []
  | tailcols ((_::xs) :: rows) = xs :: tailcols rows;

fun transp ([]::rows) = []
  | transp rows = headcol rows :: transp (tailcols rows);
		
fun matprod(rowsA, rowsB) rowlistprod(rowsA, transp rowsB);