#include <stdio.h>

int q[10][10]={0};
int c[10]={0};
int m[20];
int p[20];

void print_queen(int n)
{
	int i,j;
	printf("###\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) printf("%c", q[i][j]==1?'Q':'o');
		printf("\n");
	}
}

int nqueen(int n, int k)
{
	int i,sum=0;
	if(n==k) { print_queen(n); return 1; }
	for(i=0;i<n;i++) {
		if(c[i] || m[n+k-i-1] || p[k+i]) continue;
		q[k][i]=1; c[i]=1; m[n+k-i-1]=1; p[k+i]=1;
		sum+=nqueen(n,k+1);
		q[k][i]=0; c[i]=0; m[n+k-i-1]=0; p[k+i]=0;
	}
	return sum;
}

int main()
{
	int i;
	for(i=1;i<9;i++) printf("%d) %d\n", i, nqueen(i,0));
}
