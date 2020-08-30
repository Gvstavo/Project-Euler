#include <stdio.h>
/*



The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting
 to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, 
less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, 
find the value of the denominator.



*/


int dcf(int a,int b){
	int c=a,e=b;
	int n[2];
	int d[2];
	int x=1;
	float aux,m;
	m=(float)a/(float)b;
	if((float)m>1.0) return 0;
	n[1]=a % 10;
	d[1]=b % 10;
	n[0]=a/10;
	d[0]=b/10;
	for(int i=0;i<2;i++)
		for(int k=0;k<2;k++)
			if(n[i]==d[k]){
				aux=(float)((float)n[!i]/(float)d[!k]);
				if((float)aux==(float)m)
					return 1;
			}
	return 0;
}



int main(){
	int i,k,x=0;
	int d=1,n=1;
	for(i=12;i<99;i++){
		for(k=13;k<99;k++){
			if(!(i % 10) || !(k % 10)  || i==k || !(i % 11) ||!(k % 11)) 
				continue;
			if(dcf(i,k)){
				n*=i;
				d*=k;
			}
		}
	}
	for(i=2;i<n;i++){
		if(!(n % i) && !(d % i)){
			n/=i;
			d/=i;
		}
	}
	printf("%i/%i\n",n,d);

}