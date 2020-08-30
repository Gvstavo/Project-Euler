#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAX 255



/*


The number 3797 has an interesting property. 
Being prime itself, it is possible to continuously remove digits from left to right, and remain prime 
at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.


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
	memset(str,'\0',MAX);
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
int left(int n){
	char str[MAX];
	itoa(n,str);
	int i,r;
	for (i=0;i<strlen(str)-1;i++){
		str[i]=' ';
		r=stint(str); //string to int
		if (!prime(r))
			return 0;
	}
	return 1;

}
int right(int n){
	char str[MAX];
	itoa(n,str);
	int i,r;
	for (i=strlen(str)-1;i>=0;i--){
		str[i]=' ';
		r=stint(str);
		if (!prime(r))
			return 0;
	}
	return 1;
}
int main(){
	int i=10;
	int x=0;
	int s=0;
	do{
		i++;
		if (prime(i))
			if (left(i) && right(i)){
				s+=i;
				x++;
			}
	}while (x!=11);
	printf ("%i\n",s);

}