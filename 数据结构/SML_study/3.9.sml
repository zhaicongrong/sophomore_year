val matrix = [["a","b","c"],["d","e","f"]];

fun headcol [] = []
  | headcol ((x::_) :: rows) = x :: headcol rows;

fun tailcols [] = []
  | tailcols ((_::xs) :: rows) = xs :: tailcols rows;
  
headcol matrix;
tailcols matrix;

fun transp ([]::rows) = []
  | transp rows = headcol rows :: transp (tailcols rows);
  
transp matrix