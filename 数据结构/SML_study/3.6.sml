fun concat [] = []
  | concat(l::ls) = l @ concat ls;

concat [["When","shall"],["we","three"],["meet","again"]];
List.concat [["When","shall"],["we","three"],["meet","again"]];
fun zip(x::xs, y::ys) = (x,y) :: zip(xs, ys)
  | zip _ = [];

zip([1,2,3,4],["a","b","c","d"]);

fun unzip [] = ([], [])
  | unzip ((x,y)::pairs) = 
			let val (xs, ys) = unzip pairs	
			in (x::xs, y::ys) end;
			
unzip[(1,"m"),("j","j"),(3,"k")];