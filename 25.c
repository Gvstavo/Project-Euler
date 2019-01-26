#include <stdio.h>
#include <string.h>

/*

The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

*/


void intcpy(int destino[],int origem[]){
	int i;
	for (i=0;i<1000;i++)
		destino[i]=origem[i];
}



int FibInd(int f1[],int f2[]){
	int i;
	int r=0;
	int s=0;
	int aux[1000];
	int cont=2;
	memset(aux,0,sizeof(aux));
	while(f1[0]==0){
		intcpy(aux,f1);
		for (i=999;i>=0;i--){
			s=f1[i]+f2[i]+r;
			if (s>=10){
				f1[i]=s % 10;
				r=(int)s/10;
			}
			else{
				r=0;
				f1[i]=s;
			}
		}
		cont++;
		intcpy(f2,aux);
	}
	return cont;


}
int main(){
	int f1[1000];
	int f2[1000];
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	f1[999]=1;
	f2[999]=1;
	printf ("%i",FibInd(f1,f2));
}