#include "math.h"
#include "stdio.h"
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
int prime(unsigned long long int n){
	if (n==2 || n==3 || n==5 || n==7)
		return 1;
	if (n % 2 == 0 || n==1)
		return 0;
	unsigned long long int lim=ceil(sqrt(n));
	unsigned long long int i=1;
	do{
		i+=2;
		if ( n % i == 0)
			return 0;
	}while(i<lim);
	return 1;
}

int main(){
	long int i,s=2;
	for (i=2;i<2000000;i++)
		if (prime(i)){	
			s+=i;
		}
	printf ("%li\n",s);
}