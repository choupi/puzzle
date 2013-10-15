#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
int n,m;
long long int A[100][2];
long long int B[100][2];
long long int tab[2][10000];
long long int mt[100];
long long int tA[10000][2];
long long int tB[10000][2];


int main()
{
	int t,T,i,j,maxl;
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++) scanf("%d %d", &A[i][0], &A[i][1]);
		for(i=0;i<m;i++) scanf("%d %d", &B[i][0], &B[i][1]);
		for(i=0;i<100;i++) mt[i]=0xFFFFFFFF;
		for(i=0;i<n;i++) if(A[i][0]<mt[A[i][1]]) mt[A[i][1]]=A[i][0];
		for(i=0;i<m;i++) if(B[i][0]<mt[B[i][1]]) mt[B[i][1]]=B[i][0];
		for(i=0,j=0;i<n;) { 
			if(A[i][0]>0) {tA[j][0]=min(mt[A[i][1]],A[i][0]); tA[j][0]=A[i][1];
							A[i][0]-=tA[j][0]; j++;
			} else i++;
		}
		n=j;
		for(i=0,j=0;i<m;) { 
			if(B[i][0]>0) {tB[j][0]=min(mt[B[i][1]],B[i][0]); tB[j][0]=B[i][1];
							B[i][0]-=tB[j][0]; j++;
			} else i++;
		}
		m=j;
		tab[n%2][m]=0;
		for(i=n-1;i>=0;i--) {
			for(j=m-1;j>=0;j--) {
				if(tA[i][1]==tB[j][1]) 
					tab[i%2][j]=min(tA[i][0],tB[j][0])+tab[(i+1)%2][j+1];
				else tab[i%2][j]=0;
				tab[i%2][j]=max(max(tab[(i+1)%2][j],tab[i%2][j+1]),tab[i%2][j]);
			}
		}
//		for(i=0;i<n;i++) {for(j=0;j<m;j++) printf("%d ",tab[i%2][j]);printf("\n");}
		printf("Case #%d: %ld\n", t+1,tab[0][0]);
	}
}

