defmodule Poker do


	def card, do: 1..9 |> Enum.to_list |> Kernel.++(["T","J","Q","K","A"]) |> Enum.join

	defp is_sequence(values) do

		str_values = Enum.join(values)
		{:ok , regex} = 	Regex.compile(str_values)

		String.match?(Poker.card , regex)
	end

	def ranking(hand) do
		case hand do
			
			["T",suit,"J",suit,"Q",suit,"K",suit,"A",suit] -> :royal_flush
			[v1,suit,v2,suit,v3,suit,v4,suit,v5,suit] ->
				if is_sequence([v1 , v2 , v3 , v4 , v5]) do
					:straight_flush
				else 
					:flush
				end

			[v1 , s1 , v2 , s2 , v3 , s3 , v4 , s4 , _ , _] when  v1 == v2 and v1 == v3 and v1 == v4  and s1 != s2 and s1 != s3 and s1 != s4 -> :four_of_a_kind 

			[_ , _ , v1 , s1 , v2 , s2 , v3 , s3 , v4 , s4] when  v1 == v2 and v1 == v3 and v1 == v4  and s1 != s2 and s1 != s3 and s1 != s4 -> :four_of_a_kind 

			[v1 , s1 , v2 , s2 , v3 , s3 , v4 , s4 , v5, s5]  when v1 == v2  and v1 == v3 and s1 != s2 and s1 != s3  and v4 == v5 and s4 != s5 -> :full_house

			[v1 , s1 , v2 , s2 , v3 , s3 , v4 , s4 , v5, s5]  when v1 == v2 and s1 != s2 and  v3 == v4 and v3 == v5 and s3 !=s4 and s3 !=s5  -> :full_house


			_  ->
				[v1 , _ , v2 , _ , v3 , _ , v4 , _ , v5, _] = hand 

				cond do
					is_sequence([v1,v2,v3,v4,v5]) -> :straight
					true ->
						case hand do
							[v1 , s1 , v2 , s2 , v3 , s3 ,_ , _ , _, _] when v1 == v2 and v1 == v3 and s1 != s2 and s1 != s3 -> :three_of_a_kind

							[_,_,_,_,v1 , s1 , v2 , s2 , v3 , s3] when v1 == v2 and v1 == v3 and s1 != s2 and s1 != s3 -> :three_of_a_kind

							[v1 , s1 , v2 , s2 , v3 , s3 , v4 , s4 , _ , _] when v1 == v2 and s1 != s2 and v3 == v4 and s3 != s4 -> :two_pair
							
							[_ , _, v1 , s1 , v2 , s2 , v3 , s3 , v4 , s4] when v1 == v2 and s1 != s2 and v3 == v4 and s3 != s4 -> :two_pair

							[v1 , s1 , v2 , s2 , _,_,v3 , s3 , v4 , s4] when v1 == v2 and s1 != s2 and v3 == v4 and s3 != s4 -> :two_pair

							[v1 , s1 , v2 , s2 , _ , _, _ , _ , _, _]   when v1 == v2 and s1 != s2 -> :pair

							[_ , _, _ , _ , _, _, v1 , s1 , v2 , s2]   when v1 == v2 and s1 != s2 -> :pair

							[_ , _, v1 , s1 , v2 , s2,_ , _ , _, _, ]   when v1 == v2 and s1 != s2 -> :pair

							[_ , _,  _, _, v1 , s1 , v2 , s2,_ , _ ]   when v1 == v2 and s1 != s2 -> :pair

							_ -> :highest_card


						end
				end

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
|> Enum.map(fn x -> 
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
#|> IO.inspect

# Poker.ranking(["A","D","K","D","Q","D","J","D","T","D"])
# |> IO.inspect


# Poker.ranking(["4","D","J","D","8","D","2","D","9","D"])
# |> IO.inspect


# Poker.ranking(["4","D","J","D","8","D","2","D","9","D"])
# |> IO.inspect


# Poker.ranking(["T","D","J","D","Q","D","K","D","A","D"])
# |> IO.inspect

# Poker.ranking(["4","D","5","D","6","D","7","D","8","D"])
# |> IO.inspect


# Poker.ranking(["8","D","J","C","J","D","J","S","J","H"])
# |> IO.inspect


# Poker.ranking(["10","D","10","C","10","H","J","S","J","H"])
# |> IO.inspect

# Poker.ranking(["7","S","7","H","10","D","10","C","10","H"])
# |> IO.inspect

# Poker.ranking(["5","S","6","H","7","D","8","C","9","H"])
# |> IO.inspect

Poker.ranking(["4","S","4","H","7","D","7","C","9","H"])
|> IO.inspect

# C D S H