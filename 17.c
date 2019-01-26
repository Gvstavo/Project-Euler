#include <stdio.h>

/*


If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 
3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many 
letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 
23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out 
numbers is in compliance with British usage.


*/



int main(){

	int a = 36;
	int b =  67; 
	int s;
	int i;
	int aux;
	int dec[]={6,6,5,5,5,7,6,6};

	int h[]={10,10,12,11,11,10,12,12,11};
	s = 106;
	for(i=0;i<8;i++){
		s+=dec[i];
		s+=9*dec[i]+a;
	}
	aux = s;
	
	for(i=0;i<9;i++){
		s+=h[i];
		s+=99*h[i]+aux+(99*3);
	}
	printf("%i\n",s+11);
	


}