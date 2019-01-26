#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*


Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is 
formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal,
 but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; 
 that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above,
 a square spiral with side length 9 will be formed. If this process is
 continued, what is the side length of the square spiral for which the ratio of primes 
 along both diagonals first falls below 10%?


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
int ulam(int x){
	int a=x*x;
	int i;
	int d;
	int k=0;
	for(i=1;i<=3;i++){
		d=a-(x-1)*i;
		if(prime(d)){
			k++;
		}
	}
	return k;
}
int main(){
	int s=0;
	int k=0;
	int i=1;
	int t=0;
	int a;
	float p=1.0;
	while(p>=0.1){
		i+=2;
		s+=ulam(i);
		k++;
		a=(k*4)+1;
		p=(float)s/(float)a;
	}
	printf("%i\n",i);
	
	

}


