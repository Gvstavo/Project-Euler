#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <openssl/dh.h>
#include <openssl/bn.h>

/*

The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

*/


int main(){


	BIGNUM *a , *sum;

	BN_CTX *ctx;

	int i;

	char *ret;

	ctx = BN_CTX_new();
	a = BN_new();
	sum = BN_new();

	BN_dec2bn(&sum, "0");

	for(i = 1 ; i<=1000;i++){

		BN_set_word(a , i);

		BN_exp(a , a, a, ctx);

		BN_add(sum , sum , a);


	}

	ret = BN_bn2dec(sum);


	for(i = strlen(ret) - 10 ; i < strlen(ret); i++)
		printf("%c",ret[i]);



}