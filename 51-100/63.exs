

# The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.

# How many n-digit positive integers exist which are also an nth power?


0..20
|> Enum.to_list
|> Enum.map(fn x -> 


	1..20
	|> Enum.reduce(0 , fn 

		k,acc when x == 0 and k == 1 -> acc + 1
		_k,acc when x == 0 -> acc 

		k,acc -> 

			d = :math.pow(x ,k)
			 		|> :math.log10
			 		|> Kernel.trunc
			 		|> Kernel.+(1)  



			if d == k, do: acc + 1, else: acc

	end)

end)
|> Enum.sum
|> IO.inspect