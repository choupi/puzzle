#include <stdio.h>

int main()
{
    signed long n=1;

    while(1)
    {
	scanf("%li\n", &n);
	if (n<1) break;
	printf("%.0f%%\n", (n==1)?0:n/4.0*100);
    }

    return 0;
}
