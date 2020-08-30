#include <stdio.h>
/*


Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?


*/


unsigned long long int nroutes(int n){

	unsigned long long int r=1;
	for(int i=1;i<=n;i++)
		r=r*(n+i)/i;
	return r;
}
int main(){

	printf("%llu\n",nroutes(2));
}
