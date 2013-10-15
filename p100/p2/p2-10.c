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

void mmul(int r[][2], int a[][2], int b[][2])
{
	int r0=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	int r1=a[0][0]*b[1][0]+a[0][1]*b[1][1];
	int r2=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	int r3=a[1][0]*b[1][0]+a[1][1]*b[1][1];
	r[0][0]=r0; r[0][1]=r1; r[1][0]=r2; r[1][1]=r3;
}

int fib_mt(int n)
{
	int a[2][2]={1,1,1,0};
	int c[2][2]={1,0,1,0};
	int f[2][2]={1,1,1,1};
	int i;
	for(i=n-2;i>0;i=i>>1) {
		if(i&1) mmul(c,c,a);
		mmul(a,a,a);
	}
	mmul(c,c,f);
	return c[0][0];
}


int main()
{
	printf("%d %d\n", fib_mt(4), fib_it(4));
	printf("%d %d\n", fib_mt(5), fib_it(5));
	printf("%d %d\n", fib_mt(6), fib_it(6));
}

