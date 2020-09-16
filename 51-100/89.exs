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
	def number(x) when x == 100, do:  "X"
	def number(x) when x == 400, do:  "CD"
	def number(x) when x == 500, do:  "D"
	def number(x) when x == 900, do:  "CM"
	def number(x) when x == 1000, do:  "M"


	def to_dec(x) when is_list(x) do

	
		x
		|> Enum.map(&Roman.number/1)
		|> Enum.sum
		

	end

	def to_dec(x) when is_binary(x) do
		
		x
		|> String.replace("IV","|IV|")
		|> String.replace("IX","|IX|")
		|> String.replace("XL","|XL|")
		|> String.replace("IV","|IV|")
		|> String.replace("CD","|CD|")
		|> String.replace("CM","|CM|")
		|> String.split("|", [trim: true])
		|> Roman.to_dec


	end 

	def from(x) when is_list(x) do
		
		x
		|> Enum.reverse(fn x -> end)

	end

	def from(x) when is_integer(x) do
		x
		|> Integer.digits
		|> Roman.from		

		
	end

end




Roman.to_dec("XIX") |> IO.inspect


# end		

#IVIXXLXCCDCM




#I can only be placed before V and X.
#X can only be placed before L and C.
#C can only be placed before D and M

# IV
# IX
# XL
# XC
# CD
# CM
