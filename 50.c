#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000000

/*


The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, 
and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/
int prime(int n){
	if (n==2 || n==3 || n==5 || n==7)
		return 1;
	if (n % 2 == 0 || n==1)
		return 0;
	int lim=ceil(sqrt(n));
	int i=1;
	do{
		i+=2;
		if ( n % i == 0)
			return 0;
	}while(i<lim);
	return 1;
}
int main(){
	long int p[MAX]={0};
	long int i;
	long int aux=0,v=0,s=0,l=0,k=0;
	for(int i=0;i<MAX;i++)
		if(prime(i))
			p[i]=1;
	for(i=0;i<MAX;i++){ 
		if(p[i]){
			l=1;
			s=i;
			for(k=i+1;s<MAX && k<MAX;k++){
				if(p[k]){
					s+=k;
					l++;
					if(s<MAX && p[s] && l>v){
						v=l;
						aux=s;
					}
				}
			}

		}
	}
	printf("%lli %lli\n",aux,v);

}