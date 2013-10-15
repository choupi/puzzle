#include <stdio.h>

int ipower(int m, int n)
{
	int i,prod=1,mm=m;
	for(i=n;i>0;i=i>>1) {
		if(i&1) prod*=mm;
		mm*=mm;
	}
	return prod;
}

int cnr_log(int n, int r)
{
	int p=ipower((1<<n)+1, n);
	int q=(1<<n)-1;
	printf("%d %d\n", p, q);
	return (p>>(r*n))&q;
}

int main()
{
	printf("%d\n", cnr_log(4,2));
	printf("%d\n", cnr_log(5,2));
}
