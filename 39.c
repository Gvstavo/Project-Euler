#include "stdio.h"
#include "math.h"

/*


If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, 
there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?


*/
int pit(int a,int b){
	int i,n;
	float real,dif;
	i=a*a+b*b;
	real=sqrt(i);
	n=sqrt(i);
	dif=real-n;
	if (dif==0)
		return sqrt(i);
	else
		return 0;
}
int per(int n){
	int i,j;
	int s=0;
	int x=0;
	for (i=3;i<n;i++){
		for (j=i;j<n;j++){
			if (pit(i,j)>0){
				s=i+j+pit(i,j);
				if (s==n){
					x++;
				}
			}
		}
	}
	return x;
}
int main(){
	int i;
	int m=0,r,index;
	for (i=12;i<=1000;i++){
		r=per(i);
		if (r>m){
			index=i;
			m=r;
		}
	}
	printf ("%i\n",index);
}