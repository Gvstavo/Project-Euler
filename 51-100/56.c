#include<stdio.h>
#include<math.h>
#include<string.h>
#include <openssl/dh.h>
#include <openssl/bn.h>

/*



A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. 
Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?


*/


int main(){


	BIGNUM *r, *a,*p;

	BN_CTX *temp;

	temp = BN_CTX_new() ;
	a = BN_new();
	p = BN_new();;
	r = BN_new();
	char *str;

	unsigned long int s = 0;

	unsigned long int aux = 0; 

	int x = 0;

	for(int i = 2; i < 100 ; i++ )
		for(int k = 2; k< 100 ; k++){
			if (i == 10)
				break;

			BN_set_word(a,i); 
			BN_set_word(p,k);


			BN_exp(r , a, p, temp);

			str = BN_bn2dec(r);

		 for(x=0;x<strlen(str);x++)
				s += str[x]-'0';

			if (s > aux)
				aux = s;
			s = 0;
		}

	printf("%lu\n",aux);	


}