#include <stdio.h>

int gcd(long long a, long long b);
int gcd(long long a, long long b)
{
    if(b>a) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}

int comp (const void * a, const void * b)
{
  return ( *(long long*)a - *(long long*)b );
}

int main()
{
    int T,t,N,n;
    long long L,H;
    long long G,tmp;
    long long notes[10010]={0};

    scanf("%d", &T);
    for(t=0;t<T;t++) {
    	scanf("%d %ld %ld", &N,&L,&H);
	for(n=0;n<N;n++) scanf("%ld",&notes[n]);
	if(L==1) {
	    printf("Case #%d: 1\n", t+1);
	    continue;
	}
	qsort(notes,N,sizeof(long long),comp);
	G=1;
	for(n=0;n<N;n++) if(notes[n]!=1) { G=notes[n]; break; }
	for(n=n+1;n<N;n++) {
	    if(notes[n]<G && G%notes[n]==0) continue;
	    tmp=gcd(G,notes[n]);
	    G=G/tmp *notes[n];
	    if(G>H) break;
	}
	if(G>H) printf("Case #%d: NO\n",t+1);
	else printf("Case #%d: %ld\n",t+1,G);
    }
}

