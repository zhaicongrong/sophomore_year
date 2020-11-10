fun depthf ([], graph, visited) = rev visited
  | depthf (x::xs, graph, visited) = 
        if x mem