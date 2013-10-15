#include <stdio.h>

int disk[8];
int peg[4][8];
int npeg[4]={0};

void tower(int n, int start, int mid, int end)
{
	if(n==1) {
//		printf("%d) %d->%d\n", n,start,end);
		disk[n]=end;
		npeg[start]--; peg[end][npeg[end]]=n; npeg[end]++;
	} else {
		tower(n-1, start, end, mid);
//		printf("%d) %d->%d\n", n,start,end);
		disk[n]=end;
		npeg[start]--; peg[end][npeg[end]]=n; npeg[end]++;
		tower(n-1, mid, start, end);
	}
}

int main()
{
	int i,n=4;
	for(i=0;i<8;i++) disk[i]=1;
	tower(n,1,2,3);
	for(i=0;i<n;i++) printf("%d ", peg[3][i]);
}
