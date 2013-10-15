#include <stdio.h>

int main()
{
    int N, Nc;
    long long int G, W, M, Mt, gt, gt2;
    long long int c, i, ct, it;
    double pt, pt2, pt3;
    long long int table[2][256];

    scanf("%d", &N);
    for(Nc=0;Nc<N;Nc++) {
	scanf("%ld %ld %ld", &G, &W, &M);
//printf("%ld %ld\n", W,M); fflush(stdout);
	ct=W>G?0:1;
	for(i=0;i<W;i++) { table[0][i]=0; table[1][i]=0; }
	gt=W>G?W:G;
	for(;i<G+W;i++) { table[0][i]=0; table[1][i]=1; }
	table[0][i]=1; table[1][i]=1;
	c=i;
//printf("%ld %ld\n", it,Mt); fflush(stdout);
	for(i=i+1;i<M;i++) {
	    c=(c+1) % 256;
	    ct=(c-W<0)? c+256-W : c-W;
	    pt=(double)table[0][ct]*(double)(table[1][ct]+1);
	    ct=(c-G<0)? c+256-G : c-G;
	    pt2=(double)(table[0][ct]+1)*(double)table[1][ct];
	    ct=(c-1<0)? c+256-1 : c-1;
	    pt3=(double)table[0][ct]*(double)table[1][ct];
	    if(pt2>pt && pt2>pt3) {
		ct=(c-G<0)? c+256-G : c-G;
		table[0][c]=table[0][ct]+1;
		table[1][c]=table[1][ct];
	    } else if(pt3>pt && pt3>=pt2) {
		ct=(c-1<0)? c+256-1 : c-1;
		table[0][c]=table[0][ct];
		table[1][c]=table[1][ct];
	    } else {
		ct=(c-W<0)? c+256-W : c-W;
		table[0][c]=table[0][ct];
		table[1][c]=table[1][ct]+1;
	    }
	}
	printf("%ld %ld\n", table[0][c], table[1][c]);
    }
    return 0;
}
