#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Euler discovered the remarkable quadratic formula:

n²+n+41

It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39
. However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41

is clearly divisible by 41.

The incredible formula n²−79n+1601
was discovered, which produces 80 primes for the consecutive values 0≤n≤79

. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n²+an+b

, where |a|<1000 and |b|≤1000

where |n|
is the modulus/absolute value of n
e.g. |11|=11 and |−4|=4

Find the product of the coefficients, a
and b, for the quadratic expression 
that produces the maximum number of primes for consecutive values of n, starting with n=0.
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
	int a,b,n=0,m=0;
	int a1,b1;
	for(a=-1000;a<1000;a++){
		for(b=-1000;b<=1000;b++){
			if(prime(abs(n*n+n*a+b)))
				while(prime(abs(n*n+n*a+b)))
					n++;
			if(n>m){
				a1=a;
				b1=b;
				m=n;
			}
			n=0;
		}
	}
	printf("%i \n",a1*b1);
}