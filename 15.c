#include <stdio.h>
unsigned long long int nroutes(int n){
	unsigned long long int r=1;
	for(int i=1;i<=n;i++)
		r=r*(n+i)/i;
	return r;
}
int main(){
	printf("%llu\n",nroutes(2));
}