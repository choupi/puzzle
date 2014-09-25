#include <stdio.h>

int room[20][20];

int findOut(int start, int w, int d)
{
	int x=0, y=d-1;
	int dx=0, dy=-1, t;

	if(start<w) {
		x=start; y=d-1; 
		dx=0; dy=-1;
	} else if(start<w+d) {
		x=w-1; y=d+w-start-1; 
		dx=-1; dy=0;
	} else if(start<2*w+d) {
		x=2*w+d-start-1; y=0;
		dx=0; dy=1;
	} else if(start<2*w+2*d) {
		x=0; y=start-2*w-d;
		dx=1; dy=0;
	}
	//printf("start=%d %d %d\n", start, x, y);
	//printf("d=%d %d\n", dx, dy);

	while(1) {
		if(room[x][y]==2) {
			t=dx;
			dx=dy;
			dy=t;
		} else if(room[x][y]==1) {
			t=dx;
			dx=dy*-1;
			dy=t*-1;
		} 
	//printf("d=%d %d %d\n", dx, dy, room[x][y]);
		x=x+dx;
		y=y+dy;
		if(x==w || x<0 || y==d || y<0) break;
	}
	//printf("out=%d %d\n", x, y);
	if(y==d) return x;
	else if(y<0) return 2*w+d-x-1;
	else if(x==w) return w+d-y-1;
	else if(x<0) return 2*w+d+y;
}

int main()
{
	int w, d;
	int i, j;

	scanf("%d %d", &w, &d);
	for(j=0;j<d;j++) {
		for(i=0;i<w;i++) scanf("%d", &(room[i][j]));
	}
	/*for(j=0;j<d;j++) {
		for(i=0;i<w;i++) printf("%d", room[i][j]);
		printf("\n");
	}*/
	//printf("out=%d\n", findOut(1, w, d));
	for(i=0;i<2*w+2*d;i++) {
		j=findOut(i, w, d);
		printf("%d ", j);
	}
}
