#include <stdio.h>

int gt_count(int f[], int fn, int g[], int gn)
{
	int i, j=0, total=0;
	for(i=0;i<gn;i++) {
		while(g[i]>=f[j] && j<fn) j++;
		total+=fn-j;
	}
	return total;
}

int main()
{
	int f[]={1,3,5,7,9};
	int g[]={2,3,4,7,8};
	printf("%d\n", gt_count(f,5,g,5));
}
