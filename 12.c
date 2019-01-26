#include "stdio.h"
int div(long int a){
	long int i=0,div=0;
	do{
		i++;
		if (a % i == 0){
			div++;
		}
	}while (i!=a);
	return div;
}
int main(){
	long int p,i=0,s=0;
	do{
		i++;
		s+=i;
		p=div(s);
	}while (p<500); 
	printf ("\n%li",s);
	getchar();
}