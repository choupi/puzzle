#include <stdio.h>
#include <stdlib.h>

#define MAXN (11)

int split(int *a, int li, int ri)
{
	int i,t,p=li;
	for(i=li+1;i<=ri;i++) {
		if(a[i]<a[li]) {
			p++; t=a[p]; a[p]=a[i]; a[i]=t; 
		}
	}
	t=a[li]; a[li]=a[p]; a[p]=t;
	return p;
}

int median(int *a, int n)
{
	int l=0,r=n-1,m=r/2,p;
	while(1) {
		p=split(a,l,r);
		if(p==m) break;
		else if(p>m) r=p-1;
		else l=p+1;
	}
	return (n%2)?a[m]:(a[m]+a[m+1])/2;
}

int main()
{
	int a[MAXN];
	int i,m;
	for(i=0;i<MAXN;i++) a[i]=rand()%(MAXN*20);
	m=median(a,MAXN);
	for(i=0;i<MAXN;i++) printf("%d ",a[i]); printf("\n");
	printf("%d\n",m);
}
