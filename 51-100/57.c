#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <openssl/dh.h>
#include <openssl/bn.h>

/*

It is possible to show that the square root of two can be expressed as an infinite continued fraction.

By expanding this for the first four iterations, we get:




The next three expansions are
,
, and
, but the eighth expansion,

, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?

*/ 
int main(){


	BIGNUM *p,*q ;
	BIGNUM *auxp,*auxq;
	BIGNUM *_auxp,*_auxq;

	char *retp, *retq;

	BN_ULONG a = 2;

	p = BN_new();
	q = BN_new();
	auxp = BN_new();
	auxq = BN_new();
	_auxp = BN_new();
	_auxq = BN_new();



	BN_set_word(p , 7);

	BN_set_word(_auxp , 7);

	BN_set_word(q , 5);

	BN_set_word(_auxq , 5);


	BN_set_word(auxp , 3);
	BN_set_word(auxq , 2);

	

	unsigned long long int i = 0;

	int x = 0;

	for(i = 2 ; i < 1000 ;i++){

		BN_copy(_auxp , p);

		BN_mul_word(p , a);

		BN_add(p , p , auxp);

		BN_copy(auxp , _auxp);


		BN_copy(_auxq , q);

		BN_mul_word(q , a);

		BN_add(q , q , auxq);

		BN_copy(auxq , _auxq);



		retp = BN_bn2dec(p);
		retq = BN_bn2dec(q);

		x += (strlen(retp) > strlen(retq))? 1 : 0;


	}
	printf("%i\n",x);

}