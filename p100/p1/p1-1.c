#include <stdio.h>

int longest_plateau(int inp[], int n)
{
	int i, cur=inp[0];
	int maxsi=0, maxti=-1, si=0, ti=0;
	for(i=1;i<n;i++) {
		if(inp[i]!=cur) {
			if((ti-si)>(maxti-maxsi)) { maxsi=si; maxti=ti; }
			cur=inp[i]; si=i; ti=i;
		} else ti++;
	}
	if(maxti=-1) maxti=ti;
	printf("\n%d: %d ~ %d\n", inp[maxsi], maxsi, maxti);
	return maxsi;
}

int main()
{
	int in[100];
	int i,n=100;
	for(i=0;i<n;i++) { 
		in[i]=100/(30-i/5)+1;
		printf("%d ", in[i]);
	}
	longest_plateau(in, n);
}

