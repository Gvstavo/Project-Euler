#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIM 10000000

/*




Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.



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

 
unsigned long long int phi(int n, const unsigned long long int primes[]){

	unsigned long long int _n = n/2;

	unsigned long long int i = 0;

	float phi = (float)n;

	float aux;

	for(i=0;i<n;i++)
		if(!(n % (i + 1)) && !primes[i]){
			aux =  (float)1.0 - (1.0 / ((float)i + (float)1.0));
			phi *= aux;
		}


	return phi;	

}


int main(){




	unsigned long long int *p;

	unsigned long long int  i;

	p = (unsigned long long int*)calloc(LIM,sizeof(unsigned long long int));


	for(i = 0 ; i < LIM ; i++){
		p[i] = prime(i+1);
		if (!p[i])
			p[i] = phi(i+1,p); 
	}
	

}
