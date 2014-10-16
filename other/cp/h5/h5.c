#include <stdio.h>
#define N 256

void upper_solver(double *A, double *x, double *y, int n)
{
	int k=n-1, i=n*(n+1)/2-1, j;
	//printf("%d\n", i);
	double f;
	while(i>=0) {
		f=0;
		for(j=n-1;j>k;j--) f+=A[i--]*x[j];
		x[k]=(y[k]-f)/A[i--];
		//printf("%lf %lf %lf\n", y[k], x[k], A[i+1]);
		k-=1;
	}
}

int main(void)
{
    int i, j;
    int n; 
    double A[N * (N + 1) / 2];
    double *aptr = A;
    double x[N];
    double y[N];
    scanf("%d", &n);
    for ( i = 0 ; i < n ; i++ )
        for ( j = i ; j < n ; j++ ) {
            scanf("%lf", aptr);
            aptr++;
        }
    for ( i = 0 ; i < n ; i++ )
        scanf("%lf", &(y[i]));
    upper_solver(A, x, y, n);

    for ( i = 0 ; i < n ; i++ )
        printf("%lf ", x[i]);
	printf("\n");

    return 0;
}
