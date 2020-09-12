

# The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

# Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

#     d2d3d4=406 is divisible by 2 - 1 2 3
#     d3d4d5=063 is divisible by 3 - 2 3 4
#     d4d5d6=635 is divisible by 5 - 3 4 5
#     d5d6d7=357 is divisible by 7 - 4 5 6
#     d6d7d8=572 is divisible by 11 - 5 6 7
#     d7d8d9=728 is divisible by 13 - 6 7 8
#     d8d9d10=289 is divisible by 17 - 7 8 9

# Find the sum of all 0 to 9 pandigital numbers with this property.


defmodule Permutations do
  def of([]) do
    [[]]
  end

  def of(list) do
    for h <- list, t <- of(list -- [h]), do: [h | t]
  end  	
  
end

Permutations.of([0,1,2,3,4,5,6,7,8,9]) 
|> Enum.reject(&Kernel.==(hd(&1),0))
|> Enum.reduce(0 , fn x , acc -> 

	cond do

		x |> Enum.slice(1..3)  |> Integer.undigits 	|> Integer.mod(2) |> Kernel.==(0) &&
		x |> Enum.slice(2..4)  |> Integer.undigits 	|> Integer.mod(3) |> Kernel.==(0) && 
		x |> Enum.slice(3..5)  |> Integer.undigits 	|> Integer.mod(5) |> Kernel.==(0) &&
		x |> Enum.slice(4..6)  |> Integer.undigits 	|> Integer.mod(7) |> Kernel.==(0) && 
		x |> Enum.slice(5..7)  |> Integer.undigits 	|> Integer.mod(11) |> Kernel.==(0) && 
		x |> Enum.slice(6..8)  |> Integer.undigits 	|> Integer.mod(13) |> Kernel.==(0) && 
		x |> Enum.slice(7..9)  |> Integer.undigits 	|> Integer.mod(17) |> Kernel.==(0) ->
			acc + Integer.undigits(x)

		true ->
			acc

	end			

end)
|> IO.inspect