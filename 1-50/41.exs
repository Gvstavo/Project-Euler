

#We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

#what is the largest n-digit pandigital prime that exists?

require Integer
defmodule Permutations do
  def of([]) do
    [[]]
  end

  def of(list) do
    for h <- list, t <- of(list -- [h]), do: [h | t]
  end  	
  
end


is_prime = fn 
	
	x when Integer.is_even(x) or x == 1-> false

	x when x in [2,3,5,7] -> true

	x ->

		lim = x |> :math.sqrt	 |> Float.ceil |> Kernel.trunc

		:lists.seq(3 , lim , 2) 
		|> Enum.any?(&Kernel.==(Integer.mod(x , &1) , 0 ))
		|> Kernel.not


end



n = [1..9 , 1..8 , 1..7 , 1..6 , 1..5]
		|> Enum.filter(&Enum.sum(&1) |> Integer.mod(3) |> Kernel.>(0)) 
		|> Enum.max
		


largest_prime = n
								|> Enum.to_list						
								|> Permutations.of
								|> Enum.map(&Integer.undigits/1)
								|> Enum.filter(&is_prime.(&1))
								|> Enum.max


IO.inspect(largest_prime)								
