<?php 

/*


We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254,
 containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.


*/




$index = array(1,2,3,4,5,6,7,8,9);
$sum = [];
echo "<pre>";
for($i=0;$i<=1000;$i++)
	for($k=0;$k<=10000;$k++){
		$p = $k*$i;
		$conc = $i.$k.$p;
		if(strlen($conc) == 9 && !count(array_diff($index,str_split($conc))))
			$sum[] = $p;
		
	}
var_dump(array_sum(array_unique($sum)));



?>