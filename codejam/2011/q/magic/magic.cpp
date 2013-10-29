#include <stdio.h>
#include <list>
#define IND(x) (x-'A')
using namespace std;

int main()
{
    int T,t,C,c,D,d,N,n;
    char c1, c2, c3;
    char combine[26][26];
    list<int> oppose[26];
    int ecount[26];
    char elist[1000];
    int eind;

    scanf("%d", &T);
    for(t=0;t<T;t++) {
	eind=-1;
	for(c=0;c<26;c++) {
	    for(d=0;d<26;d++) combine[c][d]='-';
	    oppose[c].clear();
	    ecount[c]=0;
	}
    	scanf("%d", &C);
	for(c=0;c<C;c++) {
	    scanf(" %c%c%c",&c1, &c2, &c3);
//printf("##%c@%c@%c##\n", c1, c2, c3);
	    combine[IND(c1)][IND(c2)]=c3;
	    combine[IND(c2)][IND(c1)]=c3;
	}
	scanf("%d", &D);
	for(d=0;d<D;d++) {
	    scanf(" %c%c", &c1, &c2);
	    oppose[IND(c1)].push_back(IND(c2));
	    oppose[IND(c2)].push_back(IND(c1));
	}
	scanf("%d" , &N);
	scanf("%c", &c1);
//printf("%d %d %d %c\n", C, D, N, c1);
	for(n=0;n<N;n++) {
	    scanf("%c", &c1);
	    while(c1!='-') {
	    	if(eind>=0) {
		    if(combine[IND(c1)][IND(elist[eind])]!='-') {
			c1=combine[IND(c1)][IND(elist[eind])];
			ecount[IND(elist[eind])]-=1;
			eind-=1;
			continue;
		    } else if(!oppose[IND(c1)].empty()) {
		    	for(list<int>::iterator oit=oppose[IND(c1)].begin();
				oit!=oppose[IND(c1)].end();oit++) {
			    if(ecount[*oit]>0) {
			    	for(c=0;c<26;c++) ecount[c]=0;
				eind=-1;
				break;
			    }
			}
			if(eind<0) break;
		    } else {
		    	eind+=1;
			elist[eind]=c1;
			ecount[IND(c1)]+=1;
			break;
		    }
		}
		eind+=1;
		elist[eind]=c1;
		ecount[IND(c1)]+=1;
		break;
	    }
	}
//printf("%d", eind);
	printf("Case #%d: [", t+1);
	for(c=0;c<eind;c++) printf("%c, ", elist[c]);
	if(eind>=0) printf("%c", elist[eind]);
	printf("]\n");
    }
    return 0;
}
