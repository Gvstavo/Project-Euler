#include <stdio.h>

/*


You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/



int bs(int a){
	if(a % 400 == 0 || ((a % 4 ==0) && (a % 100)))
		return 1;
	else
		return 0;
}

int main(){
	int s=3;
	int a=1901;
	int m=1;
	int d=1;
	int q=0;
	while(a<=2000){
		d++;
		s++;
		if(s==8)
			s=1;
		if(bs(a) && m==2)
			if(d>29){
				d=1;
				m++;
			}
		if((!bs(a)) && m==2){
			if(d>28){
				d=1;
				m++;
			}
		}
		if(d==31 && (m==4 || m==6 || m==9 || m==11)){
			d=1;
			m++;
		}
		if(d==32 &&(m!=2 && m!=4 || m!=6 || m!=9 && m!=11)){
			d=1;
			m++;
		}
		if(m==13){
			m=1;
			a++;
		}

		if(d==1 && s==1) q++;

	}
	printf("%i\n",q);
}
