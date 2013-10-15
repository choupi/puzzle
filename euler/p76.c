#include <stdio.h>
#define MAXN (101)

int main()
{
    int table[MAXN+1][MAXN+1];
    int i,j;
    table[1][0]=0;
    for(i=1;i<MAXN;i++) {
	table[i][1]=1;
	for(j=2;j<MAXN;j++) {
	    if(j<i) table[i][j]=table[i][j-1]+table[i-j][j];
	    else table[i][j]=table[i][i-1]+1;
//	    printf("%5d", table[i][j]);
	}
//	printf("\n");
    }
    printf("%d\n", table[100][99]);
}
