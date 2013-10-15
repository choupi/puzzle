#include <stdio.h>

void factor(int a)
{
	int i, aa=a, ei;
	printf("%d=", a);
	for(i=2;i<=a;i++) {
		ei=0;
		if(aa<i) break;
		while(aa%i==0) { ei++; aa=aa/i; }
		if(ei) printf("%d(%d) ", i, ei);
	}
	printf("\n");
}

int main()
{
	factor(72);
	factor(181944);
	factor(191);
}
