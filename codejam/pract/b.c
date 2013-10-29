#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MASK[4]={2, 4, 1, 8};
int rMASK[4]={1, 8, 2, 4};

void actPath(int *d, int *x, int *y, char a)
{
    switch (a) {
		case 'W':
			if(*d==0) *y +=1;
			else if(*d==1) *x -=1;
			else if(*d==2) *y -=1;
			else if(*d==3) *x +=1;
			break;
		case 'L':
			if(*d==0) *d =3;
			else if(*d==1) *d =0;
			else if(*d==2) *d =1;
			else if(*d==3) *d =2;
			break;
		case 'R':
			if(*d==0) *d =1;
			else if(*d==1) *d =2;
			else if(*d==2) *d =3;
			else if(*d==3) *d =0;
			break;
		default:
			break;
	}
}
void actPathLab(int *d, int *x, int *y, int xn, int yn, char a, int *map)
{
	if(*x>=0 && *y>=0 && *x<xn && *y<yn && a=='W') 
		map[*y * xn+(*x)] |=MASK[*d];
	actPath(d, x, y, a);
	if(*x>=0 && *y>=0 && *x<xn && *y<yn && a=='W') 
		map[*y * xn+(*x)] |=rMASK[*d];
}

int main()
{
	char fpath[10001];
	char bpath[10001];
	int i, j, k;
	int n, fn, bn;
	int x, y, xmin, ymin, xmax, ymax;
	int xn, yn;
	int xs, ys, xe, ye;
	int tx, ty;
	int d;
	int *map;

	scanf("%d", &n);
	for(k=0;k<n;k++) {
		scanf("%s", fpath);
		fn=strlen(fpath);
		scanf("%s", bpath);
		bn=strlen(bpath);
		d=0; x=0; y=-1;
		xmin=65535; ymin=65535;
		xmax=0; ymax=0;
		for(i=0;i<fn-1;i++) {
			actPath(&d, &x, &y, fpath[i]);
			if(xmin>x) xmin=x;
			if(ymin>y) ymin=y;
			if(xmax<x) xmax=x;
			if(ymax<y) ymax=y;
		}
		actPath(&d, &x, &y, fpath[i]);
		tx=x; ty=y; d ^=2;
		for(i=0;i<bn-1;i++) {
			actPath(&d, &x, &y, bpath[i]);
			if(xmin>x) xmin=x;
			if(ymin>y) ymin=y;
			if(xmax<x) xmax=x;
			if(ymax<y) ymax=y;
		}
		xn=xmax-xmin+1; yn=ymax-ymin+1;
		xs=0-xmin; ys=-1-ymin; xe=tx-xmin; ye=ty-ymin;
		
		map=(int*)malloc(sizeof(int)*xn*yn);
		memset(map, 0, sizeof(int)*xn*yn);
		x=xs; y=ys; d=0;
		for(i=0;i<fn;i++) 
			actPathLab(&d, &x, &y, xn, yn, fpath[i], map);

		d ^=2;
		for(i=0;i<bn;i++) 
			actPathLab(&d, &x, &y, xn, yn, bpath[i], map);

		printf("Case #%d:\n", k+1);
		for(i=0;i<yn;i++) {
			for(j=0;j<xn;j++) printf("%x", map[i*xn+j]);
			printf("\n");
		}
		free(map);
	}
}




