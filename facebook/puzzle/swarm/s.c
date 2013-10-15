#include <stdio.h>

#define MAX(a,b) (a>b?a:b)

int main(int argc, char* argv[])
{
	int P, T, Z;
	int stab[1002][2];
	int ptab[1002][1002];
	int ttab[1002];
	int i, j, k, pp;
	int sum;
	FILE* f=fopen(argv[1], "r");

	fscanf(f, "%d", &P);
	for(pp=0;pp<P;pp++) {
		fscanf(f, "%d %d", &T, &Z);
		for(i=0;i<T;i++) fscanf(f, "%d %d", &stab[i][0], &stab[i][1]);
		for(i=0;i<T;i++) {
			stab[i][0]*=3;
			ptab[0][i]=0;
			ttab[i]=0;
		}
		for(i=0;i<Z;i++) ptab[i][0]=0;
		for(i=1;i<Z+1;i++) {
			for(j=0;j<T;j++) {
				if(stab[j][0]>i) ptab[i][j+1]=ptab[i][j]; 
				else ptab[i][j+1]=MAX(ptab[i][j], 
						ptab[i-stab[j][0]][j]+stab[j][1]);
			}
		}
		i=Z; j=T; sum=0;
		while(i*j!=0) {
			if(i>=stab[j-1][0] && 
					ptab[i][j]==ptab[i-stab[j-1][0]][j-1]+stab[j-1][1]) {
				ttab[j-1]=1;
				sum+=stab[j-1][0];
				i=i-stab[j-1][0];
			}
			j--;
		}
		printf("%d %d\n", sum, ptab[Z][T]);
		for(i=0;i<T;i++) { 
			if(ttab[i]) {
				printf("%d %d", i, stab[i][0]);
				break;
			}
		}
		for(i=i+1;i<T;i++) if(ttab[i]) printf(" %d %d", i, stab[i][0]);
		printf("\n");
	}
	return 0;
}
