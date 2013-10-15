#include <stdio.h>

int main()
{
	int i,j,c,T,M,K,P,W;
	int A,B,C,D;
	long long N,n;

	scanf("%d", &T);
	for(c=0;c<T;c++) {
		scanf("%lld %d %d %d %d %d %d %d %d", &N,&P,&W,&M,&K,&A,&B,&C,&D);
		for(n=0;n<N;n++) {
			printf("%d: %d %d\n", n+1, P, W);
			P=(A*P + B)%M + 1;
			W=(C*W + D)%K + 1;
		}
	}
}
