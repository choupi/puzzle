#include <stdio.h>
#include <string.h>
#define MAXC (200)

int main()
{
    int N, Nc;
    int R, C, K, M;
    int i, j, maxi, x;
    int ri, ci, cur, last;
    int map[100][MAXC];
    double mp[2][MAXC];
    double maxp=0;
    
    scanf("%d", &N);
    for(Nc=0;Nc<N;Nc++) {
	memset(map, 0, 100*MAXC);
	scanf("%d %d %d %d", &R, &C, &K, &M);
	for(i=0;i<M;i++) {
	    scanf("%d %d", &ri, &ci);
	    map[R-ri-1][2*ci+ri%2]=1;
	}
	for(i=0;i<2*C-1;i++) mp[0][i]= (i==2*K+1 && i%2)? 1.0 : 0.0;
//for(x=0;x<2*C-1;x++) printf("%.1lf ", mp[0][x]); printf("\n");
	for(i=1;i<R;i++) {
	    cur=i%2;
	    last=(i-1)%2;
	    for(j=0;j<2*C-1;j++) {
		if(j%2==cur && map[i][j]==0) mp[cur][j]=0.0;
		else {
		    if(map[i][j]==1 || map[i-1][j]==1) 
			mp[cur][j]=mp[last][j];
		    else if(j==last) mp[cur][j]=mp[last][j+1];
		    else if(j==2*C-2-last) mp[cur][j]=mp[last][j-1];
		    else mp[cur][j]=(mp[last][j-1]+mp[last][j+1])/2.0;
		}
	    }
//for(x=0;x<2*C-1;x++) printf("%.1lf ", mp[cur][x]); printf("\n");
	}
	maxp=0.0;
	for(i=0;i<2*C-1;i++) if(mp[0][i]>maxp) { maxp=mp[0][i]; maxi=i;}
	printf("%d %.6lf\n", maxi/2, maxp);
    }
    return 0;
}
