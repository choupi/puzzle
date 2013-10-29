#include <stdio.h>

int main()
{
    int T,t,N,n,i;
    int ocnt;
    int tg[101];
    int tw[101];
    char sched[101][101];
    double WP[101];
    double OWP[101];
    double OOWP[101];

    scanf("%d", &T);
    for(t=0;t<T;t++) {
    	scanf("%d", &N);
	for(n=0;n<N;n++) scanf("%s", sched[n]);
	for(n=0;n<N;n++) {
	    tg[n]=0; tw[n]=0;
	    for(i=0;i<N;i++) {
	    	if(sched[n][i]=='.') continue;
		if(sched[n][i]=='1') tw[n]++;
		tg[n]++;
	    }
	    WP[n]=(double)tw[n]/(double)tg[n];
	}
	for(n=0;n<N;n++) {
	    OWP[n]=0; ocnt=0;
	    for(i=0;i<N;i++) {
	    	if(sched[n][i]=='.') continue;
	    	if(sched[n][i]=='0') OWP[n]+= (double)(tw[i]-1)/(double)(tg[i]-1);
		else OWP[n]+= (double)tw[i]/(double)(tg[i]-1);
		ocnt++;
	    }
	    OWP[n]/=(double)ocnt;
	}
	for(n=0;n<N;n++) {
	    OOWP[n]=0; ocnt=0;
	    for(i=0;i<N;i++) { 
	    	if(sched[n][i]=='.') continue;
		OOWP[n]+=OWP[i];
		ocnt++;
	    }
	    OOWP[n]/=(double)ocnt;
	}
	printf("Case #%d:\n", t+1);
	for(n=0;n<N;n++) printf("%.9lf\n", WP[n]*0.25+OWP[n]*0.5+OOWP[n]*0.25);
    }
}


