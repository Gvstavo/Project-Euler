#include "stdio.h"


/*


An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000


*/

int champernowne(int n){
	static long int x=0,p=1;
	long int aux[7],array[7];
	long int index=0;
	long int i,k=0;
	while ((int)n>0){
		aux[index]=n%10;
		n=n/10;
		index++;
	}
	for (i=index-1;i>=0;i--){
		array[k]=aux[i];
		k++;
	}
	for (i=0;i<index;i++){
		x++;
			if (x==1 || x==10|| x==100|| x==1000|| x==10000|| x==100000|| x==1000000)
				p*=array[i];
	}
	return p;
}
int main(){
	register long int i;
	long int r;
	for (i=0;i<1000000;i++)
		r=champernowne(i);
	printf ("%li\n",r);;
}