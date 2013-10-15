#include <stdio.h>

void sieve(int a[], int n)
{
	int i,j,k;
	for(i=3,k=3;i<n/2;i++,k+=2) {
		if(a[i]) continue;
		for(j=i+k;j<n;j+=k) a[j]=1;
	}
	printf("2 ");
	for(i=3, j=3;i<n;i++,j+=2) {
		if(a[i]) continue;
		else printf("%d ", j);
	}
	printf("\n");
}

int main()
{
	int a[100]={0};
	sieve(a, 99);
}
