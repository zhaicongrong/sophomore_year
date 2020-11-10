fun divisibleByThree (n:int) : bool = 
	let val x : int = n div 3 
	in x * 3 = n 
	end;

divisibleByThree(5);
divisibleByThree(12);