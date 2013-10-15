#include <stdio.h>

int main()
{
	int t,T,i,sum,n,k,tmp,mins,minss,mini;
	int s[201];
	double st;
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d", &n);
		sum=0;mins=999;
		for(i=0;i<n;i++) {
			scanf("%d", &s[i]);
			sum+=s[i];
			if(s[i]<mins) {mins=s[i];mini=i;}
		}
		minss=999;
		for(i=0;i<n;i++) if(i!=mini && s[i]<minss) minss=s[i];
		printf("Case #%d:",t+1);
		for(i=0;i<n;i++) {
			st=(sum+((i==mini)?minss:mins)-s[i])/2.0/(double)sum*100;
			printf(" %.6lf",st>0?st:0.00000);
		}
		printf("\n");
	}
}

