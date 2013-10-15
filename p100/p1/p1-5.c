#include <stdio.h>

int headtail(int x[], int n)
{
	int i=0, j=n-1, total=0, prefix=x[0], suffix=x[n-1];
	while(i<n && j>=0) {
		if(prefix<suffix) { i++; prefix+=x[i]; }
		else if(prefix>suffix) { j--; suffix+=x[j]; }
		else if(prefix==suffix) { total++; i++; j--; 
			if(i<n) prefix+=x[i]; 
			if(j>=0) suffix+=x[j]; 
		}
	}
	return total;
}

int main()
{
	int x[]={3,6,2,1,4,5,2};
	printf("%d\n", headtail(x,7));
}
