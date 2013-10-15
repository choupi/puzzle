#include <stdio.h>

int givensum(int n)
{
	int i=1,j=2,sum=3, count=0;
	while(1) {
		if(sum==n) { 
			count++; 
			printf("%d@", i);
		}
		if(sum>=n) { sum-=i; i++; }
		else if(sum<n) { j++; sum+=j; }
		if(i+j>n) break;
	}
	return count;
}

int main()
{
	printf("%d\n", givensum(4));
	printf("%d\n", givensum(16));
	printf("%d\n", givensum(27));
	printf("%d\n", givensum(10000));
}
