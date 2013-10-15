#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int prob[2][51];
double sp[51];
int order[51];

int compare( const void* a, const void* b )  // comparison function
{
       int* arg1 = (int*) a;
       int* arg2 = (int*) b;
       if( sp[*arg1] > sp[*arg2] ) return -1;
       else if( sp[*arg1] == sp[*arg2] ) return 0;
       else return 1;
}
int main()
{
    mpq_t out;
    mpq_t out2;
    mpq_t tmp;
    int T, R, N, pt;
    int Nc, i, j;

    mpq_init(out);
    mpq_init(out2);
    mpq_init(tmp);
    scanf("%d", &N);
    for(Nc=0;Nc<N;Nc++) {
	scanf("%d %d", &R, &T);
	for(i=0;i<T;i++) {
	    scanf("%d %d", prob[0]+i,prob[1]+i);
	    sp[i]=(double)prob[0][i]/(double)prob[1][i];
	    order[i]=i;
//printf("%d %d\n", prob[0][i], prob[1][i]);
	}
	qsort(order, i, sizeof(int), compare);
	mpq_set_si(out, 1, 1);
	for(i=0;i<R-1;i++) {
	    mpq_set_si(tmp, prob[0][order[i]]-1,prob[0][order[i]]);
	    mpq_mul(out2, out, tmp);
	    mpq_swap(out, out2);
	}
	for(;i<T;i++) {
	    mpq_set_si(tmp, prob[1][order[i]]-1,prob[1][order[i]]);
	    mpq_mul(out2, out, tmp);
	    mpq_swap(out, out2);
	}
	mpq_out_str(stdout, 10, out);
	printf("\n");
    }
    return 0;
}


