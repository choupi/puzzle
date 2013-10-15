#include <stdlib.h>
#include <stdio.h>

struct gene {
    int st;
    int ed;
    int score;
};

int compare_g( const void* a, const void* b ) {  
    struct gene *arg1 = (struct gene*) a;
    struct gene *arg2 = (struct gene*) b;
    if( arg1->ed < arg2->ed ) return -1;
    else if( arg1->ed == arg2->ed ) return 0;
    else return 1;
}

int main(int argc, char* argv[])
{
    int i, j, g, off, max, tmp;
    struct gene *glist;
    int *sc;
    FILE *fin=fopen(argv[1], "r");

	fscanf(fin, "%d", &off);
	fseek(fin, off+off/80+(off%80?1:0), SEEK_CUR);

    fscanf(fin, "%d", &g);

    glist=(struct gene*)malloc(g*sizeof(struct gene));
    sc=(int*)malloc(g*sizeof(int));
    for(i=0;i<g;i++) 
    	fscanf(fin, "%d %d %d", &(glist[i].st), &(glist[i].ed), &(glist[i].score));
	
    qsort(glist, g, sizeof(struct gene), compare_g);
    for(i=0;i<g;i++) sc[i]=-65535;

    max=0;
    for(i=0;i<g;i++) {
    	tmp=0;
	for(j=0;j<i;j++) {
	    if(glist[j].ed < glist[i].st && sc[j]>tmp) tmp=sc[j];
	}
	sc[i]=tmp+glist[i].score;
	if(max<sc[i]) max=sc[i];
    }
    printf("%d\n", max);
}
