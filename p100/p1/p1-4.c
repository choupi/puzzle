#include <stdio.h>

int mindist(int f[], int fn, int g[], int gn)
{
	int i=0, j=0, d,mind=0xFFFFFF;
	for(i=0;i<gn;i++) {
		while(j+1<fn && f[j+1]<g[i]) j++;
		d=abs(g[i]-f[j]);
		if(d<mind) mind=d;
		if(j+1<fn) {
			d=abs(g[i]-f[j+1]);
			if(d<mind) mind=d;
		}
	}
	return mind;
}

int main()
{
	int f[]={1,3,5,7,9};
	int g[]={2,6,8,10,11,15};
	int h[]={15,16,17,18,19};
	printf("%d\n", mindist(f,5,g,6));
	printf("%d\n", mindist(g,6,f,5));
	printf("%d\n", mindist(g,6,h,5));
	printf("%d\n", mindist(f,5,h,5));
	printf("%d\n", mindist(h,5,f,5));
}
