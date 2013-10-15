#include <stdio.h>
#include <string.h>

#define A_LEN (10000)
#define B_LEN (10)

void init_BM(char* b, int* alpha)
{
	int i,nb=strlen(b);
	for(i=0;i<256;i++) alpha[i]=nb;
	for(i=0;i<nb-1;i++) alpha[b[i]]=nb-i-1;
}

int match_BM_(int* alpha, char* a, char* b)
{
	int c=0;
	int i,j,na=strlen(a),nb=strlen(b);
	for(i=0;i<na;) {
		for(j=nb-1;j>=0;j--) {
			c++;
			if(a[i+j]!=b[j]) {
				i+=alpha[a[i+nb-1]];
				break;
			}
		}
		if(j<0) { 
			printf("%d\n", c); 
			return i;
		}
	}
	printf("%d\n", c);
	return -1;
}

int BM_(int* alpha, char* a, char* b)
{
	int i,j,k,na=strlen(a),nb=strlen(b);
	for(i=nb-1;i<na;) {
		for(j=nb-1,k=i;j>=0 && a[k]==b[j];k--,j--) ;
		if(j<0) return k+1;
		else i+=alpha[a[i]];
	}
	return -1;
}

int match_BM(char* a, char* b)
{
	int alpha[256];
	init_BM(b,alpha);
	printf("%d\n",BM_(alpha,a,b));
	return match_BM_(alpha,a,b);
}

int main()
{
	//char a[100]="bcbcbabcabcaabcabcabcacab";
	//char b[10]="abcabcacab";
	char a[A_LEN];
	char b[B_LEN];
	int i,j;
	char *p;
	for(i=0;i<10;i++) {
		for(j=0;j<A_LEN-1;j++) a[j]=(rand()%4==0)+'a';
		a[A_LEN]='\0';
		for(j=0;j<B_LEN-1;j++) b[j]=rand()%2+'a';
		b[B_LEN]='\0';
		//printf("%s\n@@%s\n", a,b);
		
		p=strstr(a,b);
		printf("%d %d\n", match_BM(a,b), p-a<0?-1:p-a);
	}
}
