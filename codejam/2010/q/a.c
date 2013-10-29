#include <stdio.h>

int main()
{
	int t;
	int T, N, K;
	int s;

	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d", &N, &K);
		s=1<<N;
		if((K+1)%s==0) printf("Case #%d: ON\n", t+1);
		else printf("Case #%d: OFF\n", t+1);
	}
}

