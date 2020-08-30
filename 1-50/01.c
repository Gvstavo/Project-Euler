#include <stdio.h>

/*


If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

int recSumMultiples3or5(int value, int sum, int limit){ //recursive alternative

	if(value == limit)
		return sum;

	if(!(value % 3) || !(value % 5)){
		sum+= value;
		value++;
	}
	else
		value++;	
	recSumMultiples3or5(value , sum , limit);
}

int iteSumMultiples3or5(){

	int i;
	int s=0;

	for(i=3;i<1000;i++)
		if(!(i % 3) || !(i % 5))
			s+= i;
	return s;

}

int main(){

	printf("%i\n",iteSumMultiples3or5());
	printf("%i\n",recSumMultiples3or5(3,0,1000));

}
