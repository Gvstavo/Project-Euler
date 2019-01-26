#include <stdio.h>

#include <string.h>
#include <math.h>
/*


It can be seen that the number, 125874, and its double, 251748, 
contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.


*/
char *strrev(char *str){
      char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
void itoa(int n,char str[]){
	int mod,i=0;
	while ((int)n>0){
		mod=n%10;
		n=n/10;
		str[i]=(mod+48);
		i++;
	}
	strrev(str);
}

void sstr(char v[],int tam){
	int i=0;
	char a;
	if (!tam)
		return;
	for (i=0;i<tam-1;i++){
		if (v[i]>v[i+1]){
			a=v[i];
			v[i]=v[i+1];
			v[i+1]=a;
		}
	}
	sstr(v,tam-1);
}

int main(){
	char str[10]={0};
	char aux[10]={0};
	int i=0;
	int ok=0;
	while(!ok){
		i++;
		itoa(i,aux);
		itoa(i*2,str);
		sstr(aux,strlen(aux));
		sstr(str,strlen(str));
		if(!strcmp(str,aux)){
			for(int k=3;k<=6;k++){
				memset(str,0,sizeof(str));
				itoa(i*k,str);
				sstr(str,strlen(str));
				if(strcmp(str,aux))
					break;
				if(k==6)
					ok=1;
			}
		}
		memset(aux,0,sizeof(aux));
		memset(str,0,sizeof(aux));
	}
	printf("%i\n",i);

}