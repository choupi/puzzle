#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int textfit(int wordlen[], int wc, int W, int H, int s)
{
	int i,Wt=W, Ht=H-s;
	for(i=0;i<wc;i++) {
		if(W<wordlen[i]*s) return 0;
		if(Wt>=wordlen[i]*s) Wt-=(wordlen[i]*s+s);
		else if(Ht>=s) {
			Ht-=s;
			Wt=W-wordlen[i]*s-s;
		} else return 0;
	}
	return 1;
}

int main()
{
	char alltext[1024];
	char* words[512];
	int wordlen[512];
	int i,j,c,T,W,H,wc=0;
	int maxs, mins, s, maxw;
	char* pt;

	scanf("%d\n", &T);
	for(c=0;c<T;c++) {
		scanf("%d %d", &W, &H);
		getchar();
		gets(alltext);
//		printf("%s\n", alltext);
		pt=strtok(alltext, " ");
//		printf("%p %p\n", alltext, pt);
		wc=0;
		while(pt!=NULL) {
			words[wc]=pt;
			wc++;
			pt=strtok(NULL, " ");
		}
		maxw=0;
		for(i=0;i<wc;i++) {
			wordlen[i]=strlen(words[i]);
			if(wordlen[i]>maxw) maxw=wordlen[i];
		}
//		printf("%d ", maxw);
		maxs=W/maxw+1; mins=0; s=(maxs+mins)/2;
		while(maxs-mins>1) {
//		printf("(%d %d %d)@@", maxs, s, mins);
			if(textfit(wordlen, wc, W, H, s)) {
				mins=s; s=(mins+maxs)/2;
			} else {
				maxs=s;
				s=(mins+maxs)/2;
			}
		}
		printf("Case #%d: %d\n", c+1, mins);
	}
}
