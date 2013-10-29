#include <stdio.h>

#define max(a,b) (a>b?a:b)

struct point{
  int P;
  int V;
};

int p_cmp(const void *a, const void *b) 
{ 
    struct point *ia = (struct point *)a;
    struct point *ib = (struct point *)b;
    return ia->P - ib->P;
} 

int main()
{
    int T,t,C,D,c;
    int tp;
    double td,bl,br,time,md,tmp;

    struct point plist[200];

    scanf("%d", &T);
    for(t=0;t<T;t++) {
    	scanf("%d %d", &C, &D);
	tp=0;time=0;bl=-10000000;br=10000000;
	for(c=0;c<C;c++) {
	    scanf("%d %d", &(plist[c].P), &(plist[c].V));
	    tp+=plist[c].V;
	}
	qsort(plist, C, sizeof(struct point), p_cmp);
	md=0;
	for(c=0;c<C/2;c++) {
	    td=(tp-1)*D;
	    tmp=(td-(plist[C-c-1].P - plist[c].P))/2.0;
//printf("%lf@@@", tmp);
	    tmp+=(max(bl-plist[c].P+tmp,0) +  max(0,plist[C-c-1].P+tmp-br))/2.0;
//printf("%lf###", tmp);
	    if(tmp>md) md=tmp;
	    bl=plist[c].P-tmp+(plist[c].V-1)*D;
	    br=plist[C-c-1].P+tmp-(plist[C-c-1].V-1)*D;
	    tp-=plist[c].V+plist[C-c-1].V;
	}
//printf("%lf %lf\n", bl, br);
	if(C%2) {
	    td=(plist[c].V-1)*D;
//printf("%lf@@@", td);
	    tmp=td/2.0;
//printf("%lf@@@", tmp);
	    tmp+=(max(bl-plist[c].P+tmp,0) +  max(0,plist[c].P+tmp-br))/2.0;
	    if(tmp>md) md=tmp;
	}

	printf("Case #%d: %.8f\n", t+1, md);
    }
}


