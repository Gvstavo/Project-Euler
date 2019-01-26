#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*


Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576.
 We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 
918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as 
the concatenated product of an integer with (1,2, ... , n) where n > 1?



*/
char *strrev(char *str){
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


int stint(char str[]){
	int i;
	int r=0,c=0;
	for (i=strlen(str)-1;i>=0;i--){
		if (isdigit(str[i])){
			r+=(str[i]-'0')*pow(10,c);
			c++;
		}	
	}
	return r;

}
int itoa(int n,char str[]){
	int mod; 
	int j=0;
	while((int)n>0){
		str[j]=(n % 10)+48;
		n=n/10;
		j++;
	}
	strrev(str);
	//puts(str);
}
int is_pan(char str[]){
 	int i,k;
 	for (i=0;i<strlen(str);i++)
 		for (k=0;k<strlen(str);k++){
 			if (str[i]=='0' || str[k]=='0')
 				return 0;
 			if (str[i]==str[k] && i!=k)
 				return 0;
 			}
 	return 1;

}
int main(){
	int i;
	int k;
	int aux;
	int e=0;
	long int m=0,r=0;
	char str[20],ing[20];
	memset(str,'\0',sizeof(str));
	for (i=10000;e!=1;i--)
		for (k=1;;k++){
			aux=i*k;
			itoa(aux,ing);
			strcat(str,ing);
			memset(ing,'\0',sizeof(ing));
			if (strlen(str)>9){memset(str,'\0',sizeof(str));break;}
			if (strlen(str)<9) continue;
			if (is_pan(str)){
				e=1;
				r=stint(str);
				break;
			}	
		}
	printf ("%li\n",r);		
}

