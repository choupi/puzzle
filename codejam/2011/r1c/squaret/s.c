#include <stdio.h>

int main()
{
    int T,t,R,C,i,j;
    int fail;
    char tile[51][51];
    
    scanf("%d", &T);
    for(t=0;t<T;t++) {
    	scanf("%d %d", &R, &C);
	fail=0;
	for(i=0;i<R;i++) scanf("%s", tile[i]);
	for(j=0;j<C;j++) tile[R][j]='\0';
	for(i=0;i<R;i++) {
	    for(j=0;j<C;j++) {
	    	if(tile[i][j]=='#' && tile[i][j+1]=='#' &&
			tile[i+1][j]=='#' && tile[i+1][j+1]=='#') {
//		printf("#%d %d#",i,j);
		    tile[i][j]='/'; tile[i][j+1]='\\';
		    tile[i+1][j]='\\'; tile[i+1][j+1]='/';
/*for(i=0;i<R;i++) {
for(j=0;j<C;j++) printf("%c", tile[i][j]);
printf("\n");
}*/
		} else if(tile[i][j]=='#') {
//		printf("@%d %d@",i,j);
		    fail=1;
		    break;
		}
	    }
	    if(fail==1) break;
	}
	printf("Case #%d:\n", t+1);
	if(fail==1) printf("Impossible\n");
	else {
	    for(i=0;i<R;i++) {
	    	for(j=0;j<C;j++) printf("%c", tile[i][j]);
		printf("\n");
	    }
	}
    }
}
