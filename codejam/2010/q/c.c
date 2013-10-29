#include <stdio.h>
#include <gmp.h>

int main()
{
	int T, N;
	int g[1000];
	long long s[1000];
	int e[1000];
	int i, j, l, ll, t;
	int t1, t2;
	int k, R;
	long long sum, tmp;

	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d %d", &R, &k, &N);
		for(i=0;i<N;i++) scanf("%d", g+i);
		for(i=0;i<N;i++) {
			tmp=g[i];
			j=(i+1)%N;
			while(1) {
				if(tmp+g[j]>k || j==i) break;
				else {
					tmp+=g[j];
					j=(j+1)%N;
				}
			}
			s[i]=tmp;
			e[i]=j;
		}
		t1=e[0]; t2=e[e[0]];
		while(t1!=t2) {
			t1=e[t1];
			t2=e[e[t2]];
		}
		l=0;
		t2=t1; t1=0;
		while(t1!=t2) {
			t1=e[t1];
			t2=e[t2];
			l++;
		}
		j=1;
		t2=e[t2];
		while(t1!=t2) {
			t2=e[t2];
			j++;
		}
		tmp=0;
		sum=0;
		ll=0;
		for(i=0;i<l;i++) {
			sum+=s[ll];
			ll=e[ll];
		}
		for(i=0;i<j;i++) {
			tmp+=s[ll];
			ll=e[ll];
		}
		tmp*=(R-l)/j;
		/*printf("tmp: %lld sum: %lld\n", tmp, sum); */
		for(i=0;i<(R-l)%j;i++) {
			sum+=s[ll];
			ll=e[ll];
		}
		sum+=tmp;
/*		printf("R:%d s:%d len:%d\n", R, l, j); */
		printf("Case #%d: %lld\n", t+1, sum);
	}
}
