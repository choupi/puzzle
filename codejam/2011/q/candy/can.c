#include <stdio.h>

int main()
{
    int T,t,N,n,nn;
    int num[20];
    int sum, sxor, tsum, txor, msum=0;

    scanf("%d", &T);
    for(t=0;t<T;t++) {
        tsum=0; txor=0; msum=0;
    	scanf("%d", &N);
	for(n=0;n<N;n++) {
	    scanf("%d", num+n);
	    tsum+=num[n];
	    txor^=num[n];
	}
	if(txor!=0) { printf("Case #%d: NO\n", t+1); continue; }
	for(n=1;n< (1<<N)-1 ;n++) {
	    sum=0; sxor=0;
	    for(nn=0;nn<N;nn++) {
	    	if(n& (1<<nn)) { sum+=num[nn]; sxor^=num[nn]; }
	    }
	    if(sxor==(sxor ^ txor) && sum>msum) msum=sum;
	}
	if(msum>0) printf("Case #%d: %d\n", t+1, msum);
	else printf("Case #%d: NO\n", t+1);
    }
}
