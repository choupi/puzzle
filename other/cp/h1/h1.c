#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	int cs=0, ss=0;
	int ta,tb,tc;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	//printf("%d %d %d %d %d\n", a,b,c,d,e);
	ta=a-e-e;
	tb=b-e-e;
	tc=c-e-e;
	cs=a*b*c-2*d*(ta*tb+ta*tc+tb*tc);
	ss=2*(a*b+b*c+a*c)+8*d*(ta+tb+tc);
	printf("%d %d\n", ss, cs);
}
