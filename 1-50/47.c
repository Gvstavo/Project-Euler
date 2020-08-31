#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/*



The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?



*/

int primes[100000] = {0};


int cmp(const void * a, const void * b) {

  return ( *(int*)a - *(int*)b );
}





int prime(unsigned long long int n){
	if (n==2 || n==3 || n==5 || n==7)
		return 1;
	if (n % 2 == 0 || n==1)
		return 0;
	unsigned long long int lim=ceil(sqrt(n));
	unsigned long long int i=1;
	do{
		i+=2;
		if ( n % i == 0)
			return 0;
	}while(i<lim);
	return 1;
}

int prime_factors(int n , unsigned long int f[] ){

	unsigned long int i = 0;
	unsigned long int div = 1;
	int index = 0;
	int ret = 1;

	for(i=0;n!=1;i++){
 		div = primes[i];
 		 
 		while(!(n % div) )
  				 
  		div*=primes[i];

  	if(primes[i] == 0) puts("...");
  	div/=primes[i];

  	n/=div;
  	if (div != 1){

   		f[index] = div; 		 
  		index++;
  	}

	}

	 return index-1;

}	

void assign_array(unsigned long int arr1[] , const unsigned long int arr2[]) {

	int i = 0;
	for(i = 0; i< 100; i++){

		arr1[i] = arr2[i];

	}

}

int create_array(const unsigned long int arr1[],const unsigned long int arr2[],const unsigned long int arr3[], const unsigned long int arr4[],int i1, int i2,int i3, int i4){

	int size = i1+i2+i3+i4;
	long int new_arr[size] ;

	int i = 0;
	int index = 0;
	int dup = 0;

	memset(new_arr, 0 , sizeof(new_arr));

	for(i = 0; i < i1; i++ ){
		new_arr[index] = arr1[i];

		index++;
	}
	for(i = 0; i < i2; i++ ){
		new_arr[index] = arr2[i];
		index++;
	}

	for(i = 0; i < i3; i++ ){
		new_arr[index] = arr3[i];
		index++;
	}
	for(i = 0; i < i4; i++ ){
		new_arr[index] = arr4[i];
		index++;
	}


	qsort(new_arr, size, sizeof(long int), cmp);

	for(i = 0; i < size-1; i++){
		if(new_arr[i] == new_arr[i+1])
			dup++;
	
	}

	return size - dup ;


	
}

int prime_diff(unsigned long int n1, unsigned long int n2, unsigned long int n3, unsigned long int n4,int leftover){

	static unsigned long int cache[4];
	static unsigned long int factors0[100] ; 
	static unsigned long int factors1[100] ; 

	static unsigned long int factors2[100] ; 
	static unsigned long int factors3[100];
	int aux = 0;
	static int index0 , index1 , index2, index3;

	if ( !leftover){
		cache[0] = n1;
	 	cache[1] = n2;
	 	cache[2] = n3;
	 	cache[3] = n4; 
	 	index0 = 0; 
	 	index1 = 0; 
	 	index2 = 0;
	 	index3 = 0;

		memset(factors0, 0 , sizeof(factors0));

		memset(factors1, 0 , sizeof(factors1));

		memset(factors2, 0 , sizeof(factors2));

		memset(factors3, 0 , sizeof(factors3));

	 	index0 = prime_factors(n1 , factors0);
	 	index1 = prime_factors(n2 , factors1);
	 	index2 = prime_factors(n3 , factors2);
	 	index3 = prime_factors(n4 , factors3);
	}

	if(leftover == 1){

		cache[0] = cache[1];
		cache[1] = cache[2];
		cache[2] = cache[3];
		cache[3] = n4;


		index0 = index1;
		index1 = index2;
		index2 = index3;

	
		

		memset(factors0, 0 , sizeof(factors0));
	 	assign_array(factors0, factors1);
		

	 	memset(factors1, 0 , sizeof(factors1));
	 	assign_array(factors1, factors2);
		

		
	 	memset(factors2, 0 , sizeof(factors2));
	 	assign_array(factors2, factors3);

		memset(factors3, 0 , sizeof(factors3));

	 	index3 = prime_factors(n4 , factors3);
	

	}

	if(leftover == 2){

		cache[0] = cache[1];
		cache[1] = cache[2];
		cache[2] = n3;
		cache[3] = n4;

		memset(factors0, 0 , sizeof(factors0));
		assign_array(factors0, factors1);

		memset(factors1, 0 , sizeof(factors1));
		assign_array(factors1, factors2);

		index0 = index1;
		index1 = index2;

		memset(factors2, 0 , sizeof(factors2));	
		memset(factors3, 0 , sizeof(factors3));

		index2 = prime_factors(n3,  factors2);
		index3 = prime_factors(n4,  factors3);
		

	}

	if(leftover == 3){

		cache[0] = cache[1];
		cache[1] = n2;
		cache[2] = n3;
		cache[3] = n4;

		index0 = index1;

		memset(factors0, 0 , sizeof(factors0));
		assign_array(factors0, factors1); 

		memset(factors1, 0 , sizeof(factors1));
		memset(factors2, 0 , sizeof(factors2));	
		memset(factors3, 0 , sizeof(factors3));

		index1 = prime_factors(n2 , factors1);
		index2 = prime_factors(n3,  factors2);
		index3 = prime_factors(n4,  factors3);

	}

	
	return create_array(factors0,factors1,factors2, factors3,index0+1,index1+1,index2+1,index3+1); 

	 



}

int main(){

	unsigned long long int register i;
	int index =0;
	int ret;
	unsigned long long  int leftover = 0;	


	for(i = 2;index < 100000 ; i++)
		if(prime(i) ){
			primes[index] = i;
 			index++;
		}


	for(i=644;;i++ ){

		ret = prime_diff(i , i+1 ,i + 2, i+3,leftover % 4);
		
		leftover++;

		if (ret >= 16)
			break;
	}

	printf("%lu\n",i);






}
