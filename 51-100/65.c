#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <openssl/dh.h>
#include <openssl/bn.h>

/*

The square root of 2 can be written as an infinite continued fraction.

The infinite continued fraction can be written, , indicates that 2 repeats ad infinitum. In a similar way,

.

It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations. Let us consider the convergents for

.

Hence the sequence of the first ten convergents for

are:

What is most surprising is that the important mathematical constant,

.

The first ten terms in the sequence of convergents for e are:

The sum of digits in the numerator of the 10th convergent is

.

Find the sum of digits in the numerator of the 100th convergent of the continued fraction for
.
*/ 
int main(){


	BIGNUM *p,*q ;
	BIGNUM *auxp,*auxq;
	BIGNUM *_auxp,*_auxq;

	char *retp, *retq;

	BN_ULONG a[] = {1,4,1};

	int index = 0;

	int sum = 0;


	p = BN_new();
	q = BN_new();
	auxp = BN_new();
	auxq = BN_new();
	_auxp = BN_new();
	_auxq = BN_new();



	BN_set_word(p , 106);

	BN_set_word(_auxp , 106);

	BN_set_word(q , 39);

	BN_set_word(_auxq , 39);


	BN_set_word(auxp , 87);
	BN_set_word(auxq , 32);

	

	unsigned long long int i = 0;

	int x = 0;

	for(i = 6 ; i < 99 ;i++){

		if (index == 1)
			a[1] += 2; 

		BN_copy(_auxp , p);

		BN_mul_word(p , a[index]);

		BN_add(p , p , auxp);

		BN_copy(auxp , _auxp);


		BN_copy(_auxq , q);

		BN_mul_word(q , a[index]);

		BN_add(q , q , auxq);

		BN_copy(auxq , _auxq);



		retp = BN_bn2dec(p);
		retq = BN_bn2dec(q);

		index = (index + 1) % 3;

	}


	for(int i = 0 ; i < strlen(retp); i++)
		sum+= retp[i]-'0';

	printf("%i\n",sum);

}