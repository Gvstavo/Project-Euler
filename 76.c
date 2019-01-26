#include <stdio.h>

/*


It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?
*/

int p(int n,int k){
	if(k>n)
		return 0;
	if(n==k || k==1)
		return 1;
	return (p(n-1,k-1)+p((n-k),k));
}
int main(){
	int s=-1;
	for(int i=1;i<=100;i++)
		s+=p(100,i);
	printf("%i\n",s);
}