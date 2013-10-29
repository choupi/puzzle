#include <stdio.h>
/*
#include <gmp.h>

int Cm(int cp, int cc, int mm)
{
printf("%d %d\n", cp, cc);
	int prod=1, i;
	if(cc==1) return cp;
	if(cc==cp) return 1;
	if(cc==0) return 1;
	if(cc<0) return 0;
	mpz_t t;
	mpz_t t2;
	mpz_init2(t, 1);
	mpz_init(t2);
	for(i=cp;i>(cp-cc);i--) {
		mpz_mul_si(t2, t, i);
		mpz_swap(t, t2);
	}
	for(i=cc;i>1;i--) {
		mpz_cdiv_q_ui(t2, t, i);
		mpz_swap(t, t2);
	}
	mpz_mod_ui(t2, t, mm);
	return mpz_get_ui(t2);
}*/
		

int main()
{
	int T, tt, N=500;
	int n, i, j, k;
	long long prod, sum;
	int m=100003;
	long long table[500][500]={0};
	long long cnk[500][500]={0};

	scanf("%d", &T);

	for(i=0;i<N;i++) {
		for(j=0;j<N;j++) {
			if(i<j) cnk[i][j]=0;
			else if(i==j || j==0) cnk[i][j]=1;
			else cnk[i][j]=(cnk[i-1][j-1]+cnk[i-1][j])%m;
		}
	}
	table[2][1]=1;
	table[3][1]=1;
	table[3][2]=1;
	table[4][1]=1;
	table[4][2]=1;
	table[4][3]=1;
	for(i=5;i<N;i++) {
		table[i][1]=1;
		table[i][2]=1;
		for(j=3;j<i;j++) {
			prod=0;
			for(k=1;k<j;k++) 
/*				prod+=table[j][k]*Cm(i-j-1, (j-k-1), m);*/
				prod+=table[j][k]*cnk[i-j-1][j-k-1];
			table[i][j]=prod%m;
		}
	}
	/*
	for(i=2;i<N;i++) {
		for(j=1;j<i;j++) printf("%d ", table[i][j]);
		printf("\n");
	}*/
	for(tt=0;tt<T;tt++) {
		scanf("%d", &n);
		sum=0;
		for(i=1;i<n;i++) sum+=table[n][i];
		printf("Case #%d: %d\n", tt+1, sum%m);
	}
}
