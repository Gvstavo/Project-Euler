#include "stdio.h"
#include "math.h"

/*


Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.



*/
int itoa(long int n){
	unsigned long  int mod,i=0,s=0,r=n;
	while ((int)n>0){
		mod=n%10;
		s+=pow(mod,5);
		n=n/10;

	}
		return (s==r);

}
int main(){
	register long int i;
	long int s=0;
	for (i=2;i<=999999;i++){
		if (itoa(i))
			s+=i;
	}
	printf ("%li\n",s);
	


}
