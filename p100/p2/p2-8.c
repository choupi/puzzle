#include <stdio.h>

int ipower(int m, int n)
{
	int i,prod=1,mm=m;
	for(i=n;i>0;i=i>>1) {
		if(i&1) prod*=mm;
		mm*=mm;
	}
	return prod;
}

int main()
{
	printf("%d\n", ipower(2,19));
	printf("%d\n", ipower(2,15));
	printf("%d\n", ipower(2,9));
	printf("%d\n", ipower(2,7));
}
