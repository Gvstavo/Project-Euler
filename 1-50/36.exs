
# The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

# Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.





is_palindrome_dec = fn x ->

	d = Integer.digits(x)

	d == Enum.reverse(d)

end

is_palindrome_bin = fn x ->

	d = Integer.digits(x,2)

	d == Enum.reverse(d)

end	


1..1000000
|> Enum.to_list
|> Enum.reduce(0,fn x,acc -> 

	if is_palindrome_bin.(x) && is_palindrome_dec.(x), do:
		acc + x,
	else:
		acc	

end)
|> IO.inspect