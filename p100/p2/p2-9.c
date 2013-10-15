#include <stdio.h>

int fib_it(int n)
{
	int f1=1, f2=1, i;
	for(i=3;i<=n;i++) {
		if(i&1) f1=f1+f2;
		else f2=f1+f2;
	}
	if(n&1) return f1;
	else return f2;
}

int main()
{
	printf("%d\n", fib_it(4));
	printf("%d\n", fib_it(5));
	printf("%d\n", fib_it(6));
}

