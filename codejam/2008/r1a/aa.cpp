#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;

bool cmp( int a, int b ) {
     return a > b;
}

int main()
{
	int i, j, r, s, t;
	long long x[800], y[800];
	int n, T, tt;
	long long sum;

	scanf("%d", &T);
	for(t=0;t<T;t++) {
		sum=0;
		scanf("%d", &n);
		for(i=0;i<n;i++) scanf("%d", x+i);
		for(i=0;i<n;i++) scanf("%d", y+i);
		sort(x, x+n);
		sort(y, y+n, cmp);
		sum=inner_product(x, x+n, y, sum);

/*		for(i=0;i<n;i++) {
			sum+= (long long)x[i]*y[i];
		}*/
		printf("Case #%d: %lld\n", t+1, sum);
	}
}
