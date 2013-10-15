#include <stdio.h>
#include <stdlib.h>

#define MODN (1000000007)

int compare (const void * a, const void * b)
{
  return ( *(long long int*)a - *(long long int*)b );
}

int main()
{
	long long int a[10001];
	int T,t,N,K,i;
	long long int c, sum;

	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d", &N, &K);
		for(i=0;i<N;i++) scanf("%lld", a+i);
		qsort(a, N, sizeof(long long int), compare);
		//for(i=0;i<N;i++) printf("%lld", a[i]);
		c=1; sum=0;
		for(i=K-1;i<N;i++) {
			sum+=c*a[i];
			sum=sum%MODN;
			c=(c*(i+1)/(i-K+2))%MODN;
		}
		printf("Case #%d: %lld\n", t+1, sum);
	}
}

