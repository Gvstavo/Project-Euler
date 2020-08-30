#include<stdio.h>
#include <math.h>
/*



By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?


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


	int count = 1;

	register unsigned long int i = 0;

	for(i=3;;i+=2){
		if(prime(i))
			count++;

		if(count == 10001)
			break;
	}
	printf("%lu",i);

}