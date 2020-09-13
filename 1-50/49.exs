

# The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and,
# (ii) each of the 4-digit numbers are permutations of one another.

# There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

# What 12-digit number do you form by concatenating the three terms in this sequence?

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


primes = 1000..9999
			 	 |> Enum.filter(&is_prime.(&1))


seq = primes
			|> Enum.reduce([], fn x, acc ->

					perm = x 
								 |> Integer.digits
								 |> Permutations.of
								 |> Enum.map(&Integer.undigits/1)

					if x + 3330 in primes && 
					   x + 2 * 3330 in primes && 	
					   x + 3330 in perm && 
					   x + 2 * 3330 in perm, do: acc ++ [[x , x + 3330 , x + 2 * 3330]],
					else: acc   		 


 


				end)		 	 

IO.inspect(seq)