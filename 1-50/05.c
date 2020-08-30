#include<stdio.h>

/*



2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?



*/


int main(){


	unsigned long int i = 2520;
	unsigned long int k;

	while(1) {


		i+=2;
		for(k = 2 ; k<=20 ;k++)
			if (i % k)
				break;

		if (k == 21)
			break;
		
	}
	printf("%i",i);

}