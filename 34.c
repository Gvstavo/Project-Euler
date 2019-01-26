#include "stdio.h"
#define LIM (fat(9))*7


/*

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.


*/

unsigned long int fat(long int n){
	if (n==0 || n==1)
		return 1;
	if (n==2)
		return 2;
	unsigned long int f=1;
	register unsigned long int i;
	for (i=1;i<=n;i++)
		f*=i;
	return f;
}

int fat_of_digits(int n){
	unsigned long int r=n;
	unsigned long int s=0;
	unsigned long int f;
	unsigned int mod;
	while ((int)r>0){
		mod=r % 10;
		f=fat(mod);
		s+=f;
		r=r/10;
		if (s>n)
			return 0;
	}
	if (s==n)
		return 1;
	return 0;
}

int main(){

	register unsigned long int i;
	unsigned long int s=0;
	for (i=3;i<=LIM;i++)
		if (fat_of_digits(i)){
			s+=i;
		}
	printf ("%lu\n",s);


}