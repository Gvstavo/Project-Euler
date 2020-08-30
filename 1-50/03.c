#include <stdio.h>
#include <math.h>

/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
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

	unsigned  long long int i=0,m=1,lim = ceil(sqrt(600851475143));
	for(i=0;i<lim;i++){
		if(prime(i) && !(600851475143 % i))
			m= i;
	}
	printf("%llu\n",m);
		 

}