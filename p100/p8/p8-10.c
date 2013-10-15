#include <stdio.h>

#define CELL_DIE_LESS (2)
#define CELL_DIE_MORE (3)
#define CELL_DIE_OLD (0xFFFFFF)
#define CELL_BORN (3)



int count_neiber(int* cur, int pos, int k)
{
	int c=0, kk=k*k;
	if(pos-k-1>=0 && cur[pos-k-1]>0) c++;
	if(pos-k  >=0 && cur[pos-k]>0) c++;
	if(pos-k+1>=0 && cur[pos-k+1]>0) c++;
	if(pos-1  >=0 && cur[pos-1]>0) c++;
	if(pos+1  <kk && cur[pos+1]>0) c++;
	if(pos+k-1<kk && cur[pos+k-1]>0) c++;
	if(pos+k  <kk && cur[pos+k]>0) c++;
	if(pos+k+1<kk && cur[pos+k+1]>0) c++;
	return c;
}

int next_generation(int* cur, int* ng, int k)
{
	int i,j,ind=0, nc, tc=0;
	for(i=0;i<k;i++) {
		for(j=0;j<k;j++,ind++) {
			if(cur[ind]> CELL_DIE_OLD) { ng[ind]=0; continue; }
			nc=count_neiber(cur, ind, k);
			if(cur[ind]>0) {
				if(nc< CELL_DIE_LESS || nc> CELL_DIE_MORE) ng[ind]=0;
				else { ng[ind]=cur[ind]+1; tc++; }
			} else if(nc== CELL_BORN) {
				ng[ind]=1; tc++;
			}
		}
	}
	return tc;
}

void print_cell(int* c, int k)
{
	int i,j,ind=0;
	for(i=0;i<k;i++) printf("^");
	printf("\n");
	for(i=0;i<k;i++) {
		for(j=0;j<k;j++,ind++) { 
			if(c[ind]>5) printf("%c ", '@');
			else if(c[ind]>0) printf("%c ", '.');
			else printf("  ");
		}
		printf("\n");
	}
	for(i=0;i<k;i++) printf("=");
	printf("\n");
}

int main()
{
	int i,j,n=10, k=15;
	int c1[1024];
	int c2[1024];
	int *p1=c1, *p2=c2, *tp;
	for(i=0;i<k;i++) {
		for(j=0;j<k;j++) { 
			c1[i*k+j]=(rand()%4==0);
		}
	}
	print_cell(c1,k);
	for(i=0;i<n;i++) {
		next_generation(p1, p2, k);
		tp=p1; p1=p2; p2=tp;
		print_cell(p1,k);
	}
	return 0;
}
