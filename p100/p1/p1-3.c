#include <stdio.h>

int eq_count(int f[], int fn, int g[], int gn)
{
	int i=0, j=0, total=0;
	while(i<gn && j<fn) {
		if(g[i]>f[j]) j++;
		else if(g[i]<f[j]) i++;
		else { total++; i++; j++; }
	}
	return total;
}

int main()
{
	int f[]={1,3,4,7,9};
	int g[]={3,5,7,8,10};
	printf("%d\n", eq_count(f,5,g,5));
}
