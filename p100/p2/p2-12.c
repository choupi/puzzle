#include <stdio.h>

int cnr_add(int n, int r)
{
	int i,j,ii;
	int cnr[100][50];
	if(r>n-r) r=n-r;
	cnr[0][0]=1;
	for(i=1;i<r+1;i++) cnr[0][i]=0;
	for(i=1,ii=1;i<n+1;i++,ii=i&1) {
		cnr[ii][0]=1;
		for(j=1;j<r+1;j++) cnr[ii][j]=cnr[(ii+1)&1][j]+cnr[(ii+1)&1][j-1];
	}
	return cnr[n&1][r];
}

int cnr_add1(int n, int r)
{
	int i,j;
	int cnr[50];
	if(r<n-r) r=n-r;
	for(i=0;i<r+1;i++) cnr[i]=1;
	for(i=1;i<n-r+1;i++) 
		for(j=1;j<r+1;j++) cnr[j]+=cnr[j-1];
	return cnr[r];
}

int main()
{
	printf("%d %d\n", cnr_add(4,2), cnr_add1(4,2));
	printf("%d %d\n", cnr_add(5,2), cnr_add1(5,2));
	printf("%d %d\n", cnr_add(10,4), cnr_add(10,4));
	printf("%d %d\n", cnr_add(10,6), cnr_add(10,6));
}
