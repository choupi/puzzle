#include <stdio.h>

void direct(int n)
{
	int nn,i,j;
	for(nn=0;nn<(1<<n);nn++) {
		printf("%d {",nn);
		for(i=1,j=1;i<=nn;i=i<<1,j++) 
			if(i&nn) printf("%d ", j);
		printf("}\n");
	}
}

int main()
{
	direct(4);
}

