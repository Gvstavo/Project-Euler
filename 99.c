#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*


Comparing two numbers written in index form like 211 and 37 is not difficult, 
as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, 
as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'),
 a 22K text file containing one thousand lines with a base/exponent pair on each line, 
 determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.

*/


int stint(char str[],int start, int end){
	int i;
	int r=0,c=0;
	for (i=start;i>=end;i--){
		if (isdigit(str[i])){
			r+=(str[i]-'0')*pow(10,c);
			c++;
		}	
	}
	return r;

}
int strsrc(char str[],char c){
	int i;
	for(i=0;i<strlen(str);i++)
		if(str[i]==c)
			return i;
	return -1;
}
int main(){
	char str[50];
	FILE *arq;
	int k=0,x=0,aux=0;
	float exp,b,r,m=0.0;
	memset(str,0,sizeof(str));
	arq=fopen("base_exp.txt","r");
	while(fgets(str,50,arq)!=NULL){
		k=strsrc(str,',');
		b=(float)log10((float)stint(str,k,0));
		exp=(float)stint(str,strlen(str)-1,k+1);
		r=(float)exp*b;
		x++;
		if(r>m){
			m=r;
			aux=x;
		}

	}
	printf("%i\n",aux);	
}