#include <stdio.h>

struct node {
	int a;
	int b;
};

int main()
{
	int T, N;
	int ta, tb;
	int tt, i, j;
	struct node a[1001];
	int sa, sb, count;

	scanf("%d", &T);
	for(tt=0;tt<T;tt++) {
		scanf("%d", &N);
		for(i=0;i<N;i++) {
			scanf("%d %d", &ta, &tb);
			a[i].a=ta; a[i].b=tb;
		}
		count=0;
		for(i=0;i<N;i++) {
			sa=a[i].a; sb=a[i].b;
			for(j=0;j<N;j++) {
				if(i!=j && (a[j].a-sa)*(a[j].b-sb) <0 ) 
					count++;
			}
		}
		printf("Case #%d: %d\n", tt+1, count/2);
	}
}
