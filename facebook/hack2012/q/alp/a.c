#include <stdio.h>
#include <string.h>

int main()
{
	int T,c,i,j,times;
	int alphabet[26];
	char sen[]="HACKERCUP";
	char ic[1024];

	scanf("%d", &T);
	getchar();
	for(c=0;c<T;c++) {
		for(i=0;i<26;i++) alphabet[i]=0;
/*		while(1) {
			ic=getchar();
			if(ic=='\n') break;
//		printf("%c ", ic);
			alphabet[ic-'A']+=1;
		}
		*/
		gets(ic);
//		printf("%s\n", ic);
		for(i=0;i<strlen(ic);i++) alphabet[ic[i]-'A']+=1;

		alphabet['C']/=2;
		times=1000;
		for(i=0;i<9;i++) {
			if(alphabet[sen[i]-'A']<times) times=alphabet[sen[i]-'A'];
		}
		printf("Case #%d: %d\n", c+1, times);
	}
}
