#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int main()
{
    char source[95];
    char target[95];
    char number[32];
    char out[32];
    int an, p;
    int i, j, k;
    int sn, tn, nn, n;
    map<char, int> smap;

	scanf("%d", &n);
	for(k=0;k<n;k++) {
		smap.clear();
		scanf("%s", number);
		nn=strlen(number);
		scanf("%s", source);
		sn=strlen(source);
		for(i=0;i<sn;i++) smap[source[i]]=i;
		scanf("%s", target);
		tn=strlen(target);
		an=0;p=1;
		for(i=nn-1;i>=0;i--) {
			an+=smap[number[i]] *p;
			p*=sn;
		}
		j=0;
		while(an!=0) {
			out[j]=target[an%tn];
			an/=tn;
			j++;
		}
		printf("Case #%d: ", k+1);
		for(i=j-1;i>=0;i--) printf("%c", out[i]);
		printf("\n");
	}
}

