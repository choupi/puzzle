#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b )
{
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if( *arg1 > *arg2 ) return -1;
	else if( *arg1 == *arg2 ) return 0;
	else return 1;
}


int main()
{
	int N, P, K, L;
	int i, j, k, nn;
	int freq[1005];
	int sum;

	scanf("%d\n", &N);

	for(nn=0;nn<N;nn++) {
		scanf("%d %d %d\n", &P, &K, &L);
		for(i=0;i<L;i++) scanf("%d", freq+i);
		qsort(freq, L, sizeof(int), cmp);
		i=0; sum=0;
		for(j=1;j<P+1;j++) {
			for(k=0;k<K;k++) {
				sum+=freq[i]*j;
				i++;
				if(i>=L) break;
			}
			if(i>=L) break;
		}
		printf("%d\n", sum);
	}
}
		
