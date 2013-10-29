#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, tt;
	int T, L, P, C;
	double D;

	scanf("%d", &T);
	for(tt=0;tt<T;tt++) {
		scanf("%d %d %d", &L, &P, &C);
		D=(double)P/(double)L;
		i=1;
		while(pow(C, i)<D) i++;
		j=0;
		while(pow(2, j)<i) j++;
		printf("Case #%d: %d\n", tt+1, j);
	}
}
