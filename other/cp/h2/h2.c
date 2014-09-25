#include <stdio.h>

int main()
{
	int x=0, y=0, d=0;
	int dx[]={0,1,0,-1}; 
	int dy[]={1,0,-1,0};
	int t=0, it, act;
	while(1) {
		scanf("%d%d", &it, &act);
		x+=dx[d]*(it-t);
		y+=dy[d]*(it-t);
		if(act==3) break;
		else if(act==1) d=(4+d-1)%4;
		else if(act==2) d=(d+1)%4;
		t=it;
	}
	printf("%d %d\n", x*10,y*10);
}
			
