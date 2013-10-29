#include <stdio.h>

int cmp (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main()
{
    int T,tt,t,N,C,c,L,tmp;
    long long time;
    int ai[1000010];

    scanf("%d",&T);
    for(tt=0;tt<T;tt++) {
    	scanf("%d %d %d %d", &L,&t,&N,&C);
	for(c=0;c<C;c++) scanf("%d", &ai[c]);
	for(;c<N;c++) ai[c]=ai[c%C];
	tmp=t/2;
	time=0;
	for(c=0;c<N;c++) {
	    if(ai[c]<=tmp) { time+=ai[c]*2; tmp-=ai[c]; ai[c]=0;}
	    else { time+=tmp*2; ai[c]-=tmp; tmp=0; }
	}
//	printf("%d---%d@@",ai[0],time);
	qsort(ai,N,sizeof(int),cmp);
//	printf("%d@@@",ai[0]);
	for(c=0;c<L;c++) time+=ai[c];
	for(;c<N;c++) time+=ai[c]*2;
	printf("Case #%d: %lld\n", tt+1,time);
    }
}

