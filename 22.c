#include <stdio.h>
#include <stdlib.h>
#define URL "nnames.txt"

/*



Using names.txt (right click and 'Save Link/Target As...'), a 
46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order,
 COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. 
 So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

*/
int main(){
	FILE *p;
	int pos=1;
	int sum=0;
	unsigned long int total=0;
	char aux;
	p=fopen(URL,"r");
	while (1){
		aux=fgetc(p);
		if (aux==EOF)
			break;
		if (aux=='\n'){
			total+=sum*pos;
			pos++;
			sum=0;
		}
		else
			sum+=aux-64;
				
	}
	printf ("%li\n",total);
	

}
