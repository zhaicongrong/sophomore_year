case methodA(problem) of
    Success s => show s
  | Failure   => (case methodB(problem) of
                    Success s => show s 
                  | Failure   => "Both methods failed"
                  | Impossible => "No solution exists")
  | Impossible => "No solution exists";

exception Failure;
exception Impossible;

