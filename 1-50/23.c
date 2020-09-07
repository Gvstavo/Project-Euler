#include<stdio.h>
#include<math.h>




int div_sum(int n){

	int i = 2;
	int s = 1;
	for(i=2;i<n;i++)
		if(!(n % i)){
			s+=i;

		}
	return s;
		

}



void perfect_multiples(int n[]){

	register int i;

	for(i=0;i<28123;i++)
		if((!((i+1) % 6) || !((i+1) % 28) || !((i+1) % 496) || !((i+1) % 8128)) && (i+1) != 6 && (i+1) != 28 && (i+1) != 496 && (i+1) != 8128)
			n[i] = 1;
}


void abundant_number(int n[]){


	int i;
	for(i=11;i<28123;i++)
		if(!n[i] && div_sum(i+1) > (i+1))
			n[i] = 1;


}

unsigned long int comb(int start , int end, const int n[]){

	
	int i = 0;
	int k = 0;


	for(i=start;i<=end;i++)
		if(n[i] && n[end - (i + 1)])
			return 1;
	return 0;		


}


int main(){

	int n[28123] = {0};

	unsigned long int s = 78;

	perfect_multiples(n);
	abundant_number(n);


	for(int i = 12; i < 28123; i++)
		if(!(comb(11,i, n)))
			s+= i + 1;

	printf("%lu\n",s);	




}	