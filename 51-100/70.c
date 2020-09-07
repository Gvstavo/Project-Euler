#include<stdio.h>
#include<math.h>


/*




Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.



*/


int phi(int n){
	int k=2;
	float phi=(float)n;
	float aux;
	if(!(n % k)){
		while(!(n % k))
			n/=k;
		phi/=2.0;
	}
	k=3;
	while(n>1){
		if(!(n % k)){
			while(!(n % k))
				n/=k;
			aux=1.0-(1.0/(float)k);
			phi*=aux;
		}
		k+=2;
	}
	return phi;
}


int main(){

	unsigned long int lim = pow(10,6);

	unsigned long int i = 2;

	for(i=1;i<lim;i++)
		phi(i);

}
