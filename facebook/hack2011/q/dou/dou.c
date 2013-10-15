#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int N, X;
    int Xs, Nc;
    int Xtmp, Xi;
    int counter;

    scanf("%d", &N);
    for(Nc=0;Nc<N;Nc++) {
	scanf("%d", &X);
	if(X==1 || X==0) {
	    printf("1\n");
	    continue;
	}
	Xs=sqrt(X);
	counter=0;
	for(i=Xs;i>=sqrt(X/2);i--) {
	    Xtmp=sqrt(X-i*i);
	    if(Xtmp*Xtmp+i*i == X) {
		counter++;
		printf("(%d %d) ", i, Xtmp);
	    }
	}
	printf("%d\n", counter);
    }
    return 0;
}
	    
