#include<stdio.h>
#include<math.h>
#include<string.h>
#include <openssl/dh.h>
#include <openssl/bn.h>


// int BN_exp(BIGNUM *r, BIGNUM *a, BIGNUM *p, BN_CTX *ctx);

int main(){

	BIGNUM *r, *a,*p;
	BN_CTX *temp;

	unsigned long int i,s=0;

	temp = BN_CTX_new() ;
	a = BN_new();
	p = BN_new();;
	r = BN_new();
	char *str;

	BN_dec2bn(&a, "2");
	BN_dec2bn(&p, "1000");

	BN_exp(r , a, p, temp);

	str = BN_bn2dec(r);

	for(i=0;i<strlen(str);i++)
		s += str[i]-'0';

	printf("%lu\n",s);

} 