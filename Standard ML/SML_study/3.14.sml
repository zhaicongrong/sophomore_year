infix mem;
fun (x mem []) = false
  | (x mem (y::l)) = (x=y) orelse (x mem l);

fun newmem(x,xs) = if x mem xs then xs else x::xs;

fun setof [] = []
  | setof(x :: xs) = newmem(x, setof xs);

fun union([], ys) = ys
  | union(x::xs, ys) = newmem(x, union(xs, ys));

fun inter([], ys) = []
  | inter(x::xs, ys) = if x mem ys then x::inter(xs, ys)
                                   else inter(xs, ys);

infix subs;
fun ([] subs ys) = true
  | ((x::xs) subs ys) = (x mem ys) andalso (xs subs ys);

fun powset ([], base) = [base]
  | powset (x::xs, base) = 
        powset(xs, base) @ powset(xs, x::base); 

fun cartprod([], ys) = []
  | cartprod(x::xs, ys) = 
      let val xsprod = cartprod(xs,ys)
          fun pairx [] =  xsprod
            | pairx(y::ytail) = (x,y) :: (pairx ytail)
      in pairx ys end;

"Sally" mem ["Regan","Goneril","Cordelia"];

powset(rev ["the","weird","sisters"],[]);

fun depthf ([], graph, visited) = rev visited
  | depthf (x::xs, graph, visited) = 
        if x mem visited then depthf (xs, graph, visited)
        else depthf(nexts(x,graph) @ xs, graph, x::visited);

fun nexts(a, []) = []
  | nexts(a, (x,y)::pairs) = 
      if a=x then y::nexts(a,pairs)
             else nexts(a,pairs);

val graph1 = [("a","b"),("a","c"),("a","d"),("b","e"),("c","f"),("d","e"),("e","f"),("e","g")];

fun depth args = 
    let fun rdepth([], graph, visited) = visited
          | rdepth(x::xs, graph, visited) = 
              rdepth(xs, graph, 
                                if x mem visited then visited
                                else rdepth (nexts(x, graph), graph, x::visited))
    in rev(rdepth args) end;(*这边有点难懂*)

fun topsort graph = 
  let fun sort([], visited) = visited
        | sort(x::xs, visited) = 
            sort(xs, if x mem visited then visited
                     else x::sort(nexts(x, graph),visited))
      val (starts,_) = ListPair.unzip graph
  in
    sort(starts, [])
  end;


fun pathsort graph = 
  let fun sort([], path, visited) = visited
        | sort(x::xs, path, visited) = 
            if x mem path then hd[]
            else sort(xs, path,
                              if x mem visited then visited else
                              x::sort(nexts(x, graph),x::path,visited))
      val (starts,_) = ListPair.unzip graph
  in sort(starts, [], []) end;
depthf(["a"], graph1, []);