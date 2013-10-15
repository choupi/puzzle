#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXN (50)
#define GAPEQ(x) ((4*x+3)*x+1)

void shell_sort(int *a, int n)
{
	int gap, tmp, i,j,k,p2=1;
	p2=log((-3.0+sqrt(16.0*n-7.0))/8.0)/log(2.0);
	p2=1<<(p2+1);
	do {
	for(i=0;i<MAXN;i++) printf("%d ",a[i]); printf("\n");
		p2>>=1;
		gap=GAPEQ(p2);
		printf("g:%d ",gap);
		for(i=gap;i<n;i++) {
			for(j=i-gap;j>=0 && a[j]>a[j+gap]; j-=gap) {
			printf("(%d,%d) ", j,j+gap);
				tmp=a[j]; a[j]=a[j+gap]; a[j+gap]=tmp;
			}
		}
		printf("\n");
	} while(gap>1);
}


int main()
{
	int a[MAXN];
	int i;
	for(i=0;i<MAXN;i++) a[i]=rand()%(MAXN*100);
	shell_sort(a,MAXN);
	for(i=0;i<MAXN;i++) printf("%d ",a[i]); printf("\n");
}
