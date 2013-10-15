#include <stdio.h>

void lexical(int n)
{
	int a[10]={1};
	int pos=1,i;

	printf("{ }\n");
	while(1) {
		printf("{");
		for(i=0;i<pos;i++) printf("%d ",a[i]);
		printf("}\n");
		if(pos<n && a[pos-1]<n) {
			a[pos]=a[pos-1]+1;
			pos++;
		} else if(a[pos-1]<n) a[pos-1]++;
		else if(a[pos-1]==n && pos>1) { 
			pos--;
			a[pos-1]++;
		} else break;
	}
}
		
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
	lexical(4);
}

