#include<stdio.h>
#include <math.h>

/*



A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2	.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.



*/ 

int gcd(int n1, int n2) {


	while(n1!=n2)

  	if (n1 > n2)  
      n1 -= n2;
    else    
    	n2 -= n1;
  
  return n1;  

}


int main() {


	unsigned long int m = 0,n = 0;
	unsigned long int a = 0,b = 0,c = 0;
	unsigned long int k = 0;
	unsigned long int ret = 0;
	int end = 0; 

	for(m = 2;!end;m+=2){
		for(n = 1; n < m  ;n+=2){

			if(gcd(m,n) == 1 && !end){ 
				a = m*m - n*n;
				b = 2 * m * n;
				c = m*m + n * n;

				for(k=1;;k++){
					if (a*k + b * k + c * k == 1000){
						end = 1;
						break;
					}

					if (a*k + b * k + c * k > 1000)
						break;
				}

			}
			else
				continue;	
		}

	}
	ret = a* k * b * k * c * k;
	printf("%i %i %i %lu",a,b,c, ret);

}