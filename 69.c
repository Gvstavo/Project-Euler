#include <stdio.h>
/*


Euler's Totient function, φ(n) [sometimes called the phi function], 
is used to determine the number of numbers less than n which are relatively prime to n. 
For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
n 	Relatively Prime 	φ(n) 	n/φ(n)
2 	1 	1 	2
3 	1,2 	2 	1.5
4 	1,3 	2 	2
5 	1,2,3,4 	4 	1.25
6 	1,5 	2 	3
7 	1,2,3,4,5,6 	6 	1.1666...
8 	1,3,5,7 	4 	2
9 	1,2,4,5,7,8 	6 	1.5
10 	1,3,7,9 	4 	2.5

It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
time ≈ 17s, requires more effective solution 

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
	float aux;
	float max=0;
	int n;
	for(long int i=2;i<=1000000;i+=2){
		aux=(float)i/(float)phi(i);
		if(aux>max){
			max=aux;
			n=i;
		}
	}
	printf("%i %f\n",n,max);
}