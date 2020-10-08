
# We shall say that an n-digit number is pandigital 
# if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

# The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

# Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.


require Integer

1..1000
|> Enum.to_list
|> Enum.flat_map(fn x -> 
     

	x..10000
				|> Enum.to_list
				|> Enum.flat_map(fn k -> 

					digits = [Integer.digits(k) , Integer.digits(x) , Integer.digits(x*k)] |> List.flatten
					cond do
						
						digits |> Kernel.length |> Kernel.<(9) -> []
						digits |> Enum.sort |> Kernel.==(Enum.to_list(1..9)) -> [x*k]
						digits -> []

					end



				end)


end) 
|> Enum.uniq 
|> Enum.sum 
|> IO.inspect 