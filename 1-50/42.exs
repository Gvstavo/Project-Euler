

#The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

#1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

#By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.




is_triangular = fn x ->


	delta = 1 - 4 * (x * -2)

	if delta >= 0 do 

		x1 = (-1 + :math.sqrt(delta)) / 2
		x2 = (-1 - :math.sqrt(delta)) / 2


		Kernel.match?({_ , 1} , Float.ratio(x2)) 
		||
		Kernel.match?({_ , 1} , Float.ratio(x1))
	else
		false	


	end
end	



sum_txt = File.read!("p042_words.txt")
					|> String.split(",")
					|> Enum.map(&String.replace(&1 , ~s("), ""))	
					|> Enum.map(fn word -> 


							word
							|> String.to_charlist
							|> Enum.reduce(0 , fn x, acc -> 

								(x - 64) + acc

							end)

					end)
					|> Enum.reduce(0 , fn x, acc -> 
						#x |> IO.inspect
						if is_triangular.(x), do: acc + 1 ,
						else: acc

					end)


IO.inspect(sum_txt)					


			
