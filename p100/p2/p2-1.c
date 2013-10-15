#include <stdio.h>

int main()
{
	int a=1,b=0,c=0;
	int a3=1, b3=0, c3=0, abc=100;
	while(a<10) {
		if(a3+b3+c3==abc) printf("%d%d%d\n", a,b,c);
		c++; abc++;
		if(c>9) { 
			b++; c=0; 
			if(b>9) { a++; b=0; a3=a*a*a; }
			b3=b*b*b;
		}
		c3=c*c*c;
	}
}

