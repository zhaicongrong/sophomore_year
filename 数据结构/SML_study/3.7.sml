fun change (coinvals, 0) = []
  | change (c::coinvals, amount) = 
		if amount<c then change(coinvals, amount)
					else c :: change(c::coinvals, amount-c);
					(*This is a greedy algorithm.*)
val gb_coins = [50, 20, 10, 5, 2, 1];
val us_coins = [25, 10, 5, 1];

change(gb_coins, 43);
change(us_coins, 43);

fun allChange (coins, coinvals, 0) = 
		let 
			val list = []
			list = [coins] :: list
		in
			[coins]
		end;
  | allChange (coins, [], amount) = []
  | allChange (coins, c::coinvals, amount) = 
		if amount<0 then []
		else allChange(c::coins, c::coinvals, amount-c) @
			 allChange(coins, coinvals, amount);
			 (*!!!!!!!I don't understand!*)

allChange([],[5,2],16);
allChange([], gb_coins, 16);