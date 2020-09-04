
#include<stdio.h>
#include<math.h>


// In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

//     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

// It is possible to make £2 in the following way:

//     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

//  How many different ways can £2 be made using any number of coins?


int coin_value(int coin){

	switch(coin){

		case 1:
			return 1;

		case 2:
			return 2;

		case 3:
			return 5;

		case 4:
			return 10;

		case 5:
			return 20;		

		case 6:
			return 50;

		case 7:
			return 100;
		case 8:
			return 200;	

	} 

}

int coin_amount(int value, int coin){

	if(!value)
		return 1;

	if (value < 0 || !coin)
		return 0;

	return coin_amount(value, coin-1) + coin_amount(value-coin_value(coin), coin); 

}



int main(){

	int s = 0;

		s+=coin_amount(200,8);
	printf("%lu",s);
}



