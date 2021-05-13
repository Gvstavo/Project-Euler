defmodule Poker do


	def ranking(hand) do

		case hand do
			
			["A",suit,"K",suit,"Q",suit,"J",suit,"T",suit] -> :royal_flush
			__ -> :high_card

		end


	end
	
end

{:ok , txt } = File.read("54/_54/p054_poker.txt") 
	
sorter = fn x -> 
	{value , _suit} = String.split_at(x,1)

	case value do
		"T"  -> 10
		"J" -> 11
		"Q" -> 12
		"K" -> 13
		"A" -> 14
		_ -> String.to_integer(value)
	end

end

txt 
|> String.split("\n",trim: true) 
|> Enum.map(&String.split_at(&1,14))
|> Enum.map(&Tuple.to_list/1)
|> Enum.flat_map(fn x -> 
	[a , b] = x

	[
		a 
		|> String.split(" ", trim: true)
		|> Enum.sort_by(sorter)
		|> Enum.join
		|> String.split("",trim: true),
		b 
		|> String.split(" ", trim: true)
		|> Enum.sort_by(sorter)
		|> Enum.join
		|> String.split("",trim: true),
	]

end)

Poker.ranking(["A","D","K","D","Q","D","J","D","T","D"])
|> IO.inspect

# C D S H