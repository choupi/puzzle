#include <stdio.h>

int gcd(int, int);
int gcd(int a, int b)
{
    if(a<b) gcd(b,a);
    else if(b==0) return a;
    else gcd(b,a%b);
}

int main()
{
    int T,t,Pd,Pg;
    long long N, D, G,wd,wg;
    scanf("%d", &T);
    for(t=0;t<T;t++) {
    	scanf("%ld %d %d", &N, &Pd, &Pg);
	if((Pd!=0 && Pg==0) || (Pg==100 && Pd!=100)) {
	    printf("Case #%d: Broken\n", t+1);
	    continue;
	}
	D=100/gcd(100,Pd);
	G=100/gcd(100,Pg);
	if(D<=N) printf("Case #%d: Possible\n", t+1);
	else printf("Case #%d: Broken\n", t+1);
    }
}
