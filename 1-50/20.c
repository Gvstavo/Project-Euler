#include "stdio.h"
#include "math.h"
#include "string.h"
#include <openssl/bn.h>
#include <openssl/dh.h>
#include "openssl/bn.h"

/* 

! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

*/

int main(){
	BIGNUM *a;
	char *r;
	int i=1,p=1,s=0;
	a=BN_new();
	BN_dec2bn(&a, "1");
	do{
		i++;
		BN_mul_word(a,i);
	}while (i<100);
	r=BN_bn2dec(a);
	for (i=0;i<strlen(r);i++)
		s+=r[i]-'0';
	printf ("%li\n",s);

	


	
}