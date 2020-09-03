#include<stdio.h>
#include<math.h>
#include<string.h>
/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

*/



void parse_array(int m[][50], char str[]){

	FILE *fp;

	fp = fopen("13.txt","r");

	int x = 0 , y = 0;

	while( fgets (str, 255, fp) !=NULL ) {

		for(x = 49; x>=0; x--)
			m[y][x] = ((int)str[x] - 48);
		y++;


	}
	fclose(fp);

}


int sum(int n[][50] , unsigned long int result[]){

	int index = 1023;
	unsigned long int s = 0 ;
	unsigned long int aux = 0 ;
	for(int i = 99; i >= 0; i-- ){
		for(int k = 50; k >=0 ; k--)	
			s+=n[i][k];

		if (s < 10){
			aux = 0;
			result[index] = s;
			s = 0;
		}

		else{

			aux = (int)s / 10;
			result[index] = !i ? s : s % 10;
			s = aux;

		}

		index--;
		

	
	}
	return index;		

}

int main(){


	int n[100][50] = {0};

	unsigned long int result[1024] = {0};

	char str[255] = {'\0'};

	int ret = 0;
	
	parse_array(n , str);

	ret = sum(n , result);
	//printf("%i\n",sum(n , result));

	for(int i = 0; i < 1024; i++)

		printf("%i",result[i]);
	// for(int i = 0; i < 100; i++ ){
	// 	for(int k = 0; k < 50 ; k++)
	// 		printf("%i",n[i][k]);
	puts("\n");
	// }
	

}