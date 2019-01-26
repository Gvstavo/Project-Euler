#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 255
/*


The number, 197, is called a circular prime because all rotations of the digits: 
197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?



*/

int stint(char str[]){
	int i;
	int r=0,c=0;
	for (i=strlen(str)-1;i>=0;i--){
		if (isdigit(str[i])){
			r+=(str[i]-'0')*pow(10,c);
			c++;
		}	
	}
	return r;

}

int prime(int n){
	if (n==1)
		return 0;
	if (n==2)
		return 1;
	int i;
	int sq=ceil(sqrt(n))+1;
	for (i=2;i<sq;i++)
		if (n % i==0)
			return 0;
	return 1;
}
void itoa(int n,char str[]){ //int to string
	memset(str,'\0',strlen(str));
	char aux[MAX];
	int mod;
	int index=0;
	int i;
	while ((int)n>0){
		mod=n % 10;
		aux[index]=(mod+48);
		n=n/10;
		index++;
	}
	int x=0;
	for (i=index-1;i>=0;i--){
		str[x]=aux[i];
		x++;
	}
}
int rot(int n){
	char str[MAX];
	char r[MAX];
	char aux;
	int i=0,a,x=0;
	itoa(n,str);
	memset(r,'\0',MAX);
	strcpy(r,str);
	do{
		aux=str[0];
		for (i=1;i<strlen(str);i++)
			str[i-1]=str[i];		
		str[i-1]=aux;
		a=stint(str);
		if (prime(a)==0){
			return 0;
		}
	}while(strcmp(r,str)!=0);	
	return 1;
}
int main(){
	int i;
	int x=13;
	for (i=100;i<1000000;i++)
		if (prime(i))
			if (rot(i)){
				x++;
			}
	printf ("%i\n",x);

}