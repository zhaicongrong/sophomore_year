datatype person = King
                | Peer of string*string*int
                | Knight of string
                | Peasant of string;

fun title King = "His majesty the king"
  | title (Peer(deg,terr,_)) = "The" ^ deg ^ " of " ^ terr
  | title (Knight name) = "Sir " ^ name
  | title (Peasant name) = name;

val persons = [King, Peasant "Jack Cade", Knight "Gawain"];

fun sirs [] = []
  | sirs ((Knight s) :: ps) = s :: (sirs ps)
  | sirs (p :: ps) = sirs ps;

sirs persons;

fun superior (King, Peer _) = true
  | superior (King, Knight _) = true
  | superior (King, Peasant _) = true
  | superior (Peer _, Knight _) = true
  | superior (Peer _, Peasant _) = true
  | superior (Knight _, Peasant _) = true
  | superior _ = false;

datatype degree = Duke | Marquis |  Earl | Viscount | Baron;

datatype order = LESS | EQUAL | GREATER;

datatype 'a option = NONE | SOME of 'a;

datatype ('a, 'b)sum = In1 of 'a | In2 of 'b;

[In2(King), In1("Scotland")];
[In1("tyrant"), In2(1040)];

fun concat1 [] = ""
  | concat1 ((In1 s)::l) = s ^ concat1 l
  | concat1 ((In2 _)::l) =     concat1 l;

concat1 [In1 "O!", In2 (1040,1057), In1 "Scotland" ];