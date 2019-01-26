#include "stdio.h"
#define t(x) x*(x+1)/2
#define p(x) x*(3*x-1)/2 	
#define h(x) x*(2*x-1)	

/*


Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
Triangle 	  	Tn=n(n+1)/2 	  	1, 3, 6, 10, 15, ...
Pentagonal 	  	Pn=n(3n−1)/2 	  	1, 5, 12, 22, 35, ...
Hexagonal 	  	Hn=n(2n−1) 	  	1, 6, 15, 28, 45, ...

It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.

*/

int main(){
	unsigned long int i=285;
	unsigned long int j=165;
	unsigned long int k=143;
	unsigned long int f;
	int e=0;
	while (e==0){
		i++;
		while (1){
			j++;
			if (p(j)>t(i))
				break;
			if (p(j)==t(i))
				while (1){
					k++;
					if (h(k)>p(j))
						break;
					if (h(k)==p(j) || h(k)==t(i)){
						e=1;
						break;
					}
				}
		}
		j=165;
		k=143;
	}
	printf ("%llu\n",t(i));
}
