#include <stdio.h>
#include <string.h>
#define FACT 6


/*


A permutation is an ordered arrangement of objects. 
For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. 
If all of the permutations are listed numerically or alphabetically, 
we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?


*/



void swap(char str[],int a,int b){
	char aux;
	aux=str[a];
	str[a]=str[b];
	str[b]=aux;
}

int src(int k,char str[]){
	int i;
	for(i=strlen(str)-1;i>k;i--)
		if(((int)str[i]-48)>(int)str[k]-48)
			return i;
		
// Find the largest index l greater than k such that a[k] < a[l].
}
int max(char str[]){//first
//Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
	int i;
	int m;
	int a;
	m=-1;
	for(i=0;i<strlen(str)-1;i++){
		if(((int)str[i]-48)<((int)str[i+1]-48) && i>m)
			m=i;
	}
	return m;
}
void reverse(char str[],int start){//...
	char aux;
	int end;
	int i=0;
	end=strlen(str)-1;
	if(end==start) return;
	for(i=start;i<end;i++){
		swap(str,i,end--);
	}

}

int main(){
	char list[]={"0123456789"};
	long int i=1; 
	int k=1;
	int l;
	while(i<1000000){
		k=max(list);
		if(k<0) break;
		l=src(k,list);
		swap(list,k,l);
		reverse(list,k+1);
		i++;

	}
	puts(list);
}
/*

    Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
    Find the largest index l greater than k such that a[k] < a[l].
    Swap the value of a[k] with that of a[l].
    Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/