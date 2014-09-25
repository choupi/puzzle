#include <stdio.h>

const int MN=101, C=30;
int bn[MN];

int find_match(int c, int n)
{
    int r=-1,mc=0;
    for(int i=0;i<n;i++) {
	    if(c<0 && bn[i]>=c && bn[i]<mc) {
		    mc=bn[i];
			r=i;
		} else if(c>0 && bn[i]<=c && bn[i]>mc) {
		    mc=bn[i];
			r=i;
		}
	}
	return r;
}

int main()
{
    int n=0, cap=0, cnt=0, r;
	while(scanf("%d", bn+n)!=EOF) n++;
	for(int i=0;i<n;i++) bn[i]-=50;
	//for(int i=0;i<n;i++) printf("%d ", bn[i]);printf("\n");
	while(1) {
	    r=-1;cnt++;
	    if(cap>0) r=find_match(cap*-1,n);
		if(r>=0) {
		    cap+=bn[r];
			printf("%d unload %d\n", r+1, -1*bn[r]);
			bn[r]=0;
			continue;
		}
		r=find_match(C-cap,n);
		if(r>=0) {
		    cap+=bn[r];
			printf("%d load %d\n", r+1, bn[r]);
			bn[r]=0;
			continue;
		}
	    if(cap>0) r=find_match(cap*-1-C,n);
		if(r>=0) {
		    bn[r]+=cap;
			printf("%d unload %d\n", r+1, cap);
			cap=0;
			continue;
		}
		r=find_match(C-cap+C,n);
		if(r>=0) {
		    bn[r]-=C-cap;
			printf("%d load %d\n", r+1, C-cap);
			cap=C;
			continue;
		}
		break;
	}
	//for(int i=0;i<n;i++) printf("%d ", bn[i]);
	//printf("%d\n", cnt);
}

