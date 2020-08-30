#include "stdio.h"
#include "math.h"


// It was proposed by Christian Goldbach that every odd composite number can be written as the sum
// of a prime and twice a square.

// 9 = 7 + 2×12
// 15 = 7 + 2×22
// 21 = 3 + 2×32
// 25 = 7 + 2×32
// 27 = 19 + 2×22
// 33 = 31 + 2×12

// It turns out that the conjecture was false.

// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
int prime(int n){
	int i;
	int t=ceil(sqrt(n));
	for (i=2;i<t;i++)
		if (n % i ==0)
			return 0;
	return 1;
}
int goldbach(long int n){
	long int i,j,r,q=1;
	for (i=2;i<n;i++){
		q=0;
		if (prime(i)==1)
			while(1){
				q++;
				r=i+2*(q*q);
				if (r==n)
					return 0;
				if (r>n)
					break;	
		}
	}
	return 1;
}
int main(){
	long int k=33;
	while (1){
		k=k+2;
		if (prime(k)==0)
			if (goldbach(k)==1)
				break;
	}
	printf ("%li\n",k);
}