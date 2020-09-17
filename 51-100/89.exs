# For a number written in Roman numerals to be considered valid there are basic rules which must be followed. Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.

# For example, it would appear that there are at least six ways of writing the number sixteen:

# IIIIIIIIIIIIIIII
# VIIIIIIIIIII
# VVIIIIII
# XIIIIII
# VVVI
# XVI

# However, according to the rules only XIIIIII and XVI are valid, and the last example is considered to be the most efficient, as it uses the least number of numerals.

# The 11K text file, roman.txt (right click and 'Save Link/Target As...'), contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals; see About... Roman Numerals for the definitive rules for this problem.

# Find the number of characters saved by writing each of these in their minimal form.

defmodule Roman do
	

	def number(x) when x == "I", do:  1
	def number(x) when x == "IV", do:  4
	def number(x) when x == "V", do:  5
	def number(x) when x == "IX", do:  9
	def number(x) when x == "X", do:  10
	def number(x) when x == "XL", do:  40
	def number(x) when x == "L", do:  50
	def number(x) when x == "XC", do:  90
	def number(x) when x == "C", do:  100
	def number(x) when x == "D", do:  500
	def number(x) when x == "CD", do:  400
	def number(x) when x == "CM", do:  900
	def number(x) when x == "M", do:  1000


	def number(x) when x == 1, do: "I"
	def number(x) when x == 4, do: "IV"
	def number(x) when x == 9, do: "IX"
	def number(x) when x == 5, do:  "V"
	def number(x) when x == 10, do:  "X"
	def number(x) when x == 40, do:  "XL"
	def number(x) when x == 50, do:  "L"
	def number(x) when x == 90, do:  "XC"
	def number(x) when x == 100, do:  "C"
	def number(x) when x == 400, do:  "CD"
	def number(x) when x == 500, do:  "D"
	def number(x) when x == 900, do:  "CM"
	def number(x) when x == 1000, do:  "M"


	def to_dec(x) when is_list(x) do

		x
		
		|> Enum.reduce(0, fn 

			n , acc when byte_size(n) == 1 -> 

				acc + Roman.number(n)

			n , acc  -> 

				acc + n
							|> String.split("", [trim: true])
							|> Enum.reduce(0 , fn a , aux -> Roman.number(a) + aux end)
				


		end)
		

		
	end

	def to_dec(x) when is_binary(x) do

		if String.match?(x , ~r/(IX|XL|XC|CD|CM|IV)/), do:
			x
			|> String.split(~r/(IX|XL|XC|CD|CM|IV)/, [include_captures: true, trim: true])

			|> Roman.to_dec,
		else:
		
			x
			|> String.split("", [trim: true])
			|> Roman.to_dec


	end 

	def from(x) when is_list(x)  do
		
		x
		|> Enum.to_list
		|> Enum.flat_map_reduce(0 , fn 

			n,acc when n in [4,9,5] and acc < 3 -> 

				{[n 
					|> Kernel.*(:math.pow(10,acc)) 
					|> Kernel.trunc 
					|> Roman.number], acc + 1}

			n,acc when n < 5  and acc < 3 ->

				{10
				|> :math.pow(acc)
				|> Roman.number
				|> String.duplicate(n)
				|> List.wrap , acc + 1}

			n,acc when n > 5  and acc < 3 ->

				prefix = 5
								 |> Kernel.*(:math.pow(10,acc)) 
								 |> Kernel.trunc 
					       |> Roman.number

				ret = Kernel.<>(prefix ,
						10
						|> :math.pow(acc)
						|> IO.inspect
						|> Roman.number
						|> String.duplicate(n - 5)
			
					)
					|> List.wrap	       

				{ ret , acc + 1}

			
			n,acc when acc >= 3 ->

				{ [String.duplicate("M", n)] , acc + 1}
			  				

		end)
		|> elem(0)
		|> Enum.reverse
		|> Enum.join
	

	end

	def from(x) when is_integer(x) do
		x
		|> Integer.digits
		|> Enum.reverse
		|> Roman.from		

		
	end

	

end



non_minimal_form = fn n -> 

	[Regex.scan(~r/.C{4,}/, n) , Regex.scan(~r/.X{4,}/, n) , Regex.scan(~r/.I{4,}/, n)]
	|> List.flatten


end	

# minimal_form = fn n -> 

# 	String.match?(n , ~r/X{4,}/) || 
# 	String.match?(n , ~r/I{4,}/) || 
# 	String.match?(n , ~r/C{4,}/)  


# end	

_r = File.read!("p089_roman.txt")
		 |> String.split("\n") 
		 |> Enum.flat_map(&non_minimal_form.(&1))

		 |> Enum.reduce(0 ,fn x, acc -> 

		 		minimal_form = x 
		 									 |> Roman.to_dec 
		 									 |> Roman.from

		 		acc + (String.length(x) - String.length(minimal_form))

		 end)
		#|> Enum.map(&Roman.to_dec/1)
		|> IO.inspect



