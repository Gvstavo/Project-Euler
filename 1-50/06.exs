
# the sum of the squares of the first ten natural numbers is, 385

# The square of the sum of the first ten natural numbers is, 3025

# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640

# .

# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.



square_of_the_sum = 1..100
										|> Enum.sum
										|> :math.pow(2)

 sum_of_squares = 1..100
 								 |> Enum.map(&:math.pow(&1,2))
 								 |> Enum.sum


square_of_the_sum - sum_of_squares
|> IO.inspect


