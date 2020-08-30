#include <stdio.h>
#include <math.h>

/*

A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/


int isPalindrome(int n){

	int d = log10(n);
	int aux=0;
	int i,a=0,b=0,f=0;

	aux = n;

	for(i=d;i>=0;i--){
		a = n % 10;
		n/=10;
		f += a*pow(10,i);
	}
	return (aux == f);

}


int main(){
	int i,k,m=0,p=0,aux=0;
	for(i=100;i<1000;i++)
		for(k=100;k<999;k++){
			p = k*i;
			if(isPalindrome(p) && p>aux)
				aux = p;	
		}
	printf("%i\n",aux);
			
}

