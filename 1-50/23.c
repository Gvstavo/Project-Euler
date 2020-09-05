#include<stdio.h>
#include<math.h>




void perfect_multiples(int n[]){

	register int i;

	for(i=0;i<28123;i++)
		if((!((i+1) % 6) || !((i+1) % 28) || !((i+1) % 496) || !((i+1) % 8128)) && (i+1) != 6 && (i+1) != 28 && (i+1) != 496 && (i+1) != 8128)
			n[i] = 1;
}

int main(){

	int n[28123] = {0};

	perfect_multiples(n);



}	