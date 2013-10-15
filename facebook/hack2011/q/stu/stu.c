#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare( const void *lhs, const void *rhs )
{
    char* lh=*((char**)lhs);
    char* rh=*((char**)rhs);
    char w1[22];
    char w2[22];
    strcpy(w1, lh);
    strcpy(w2, rh);
    strcat(w1, rh);
    strcat(w2, lh);
    return strcmp(w1, w2);
//    return strcmp(lh, rh);
}

int main()
{
    int N, M, Nc;
    int i;
    char* word[10];
    char words[10][12];
    scanf("%d", &N);
    for(Nc=0;Nc<N;Nc++) {
	scanf("%d ", &M);
	for(i=0;i<M;i++) {
	    scanf("%s", words[i]);
	    word[i]=words[i];
	}
	qsort(word, M, sizeof(char*), compare);
	for(i=0;i<M;i++) printf("%s", word[i]);
	printf("\n");
    }
    return 0;
}
