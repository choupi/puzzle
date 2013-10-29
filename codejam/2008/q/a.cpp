#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;
#define min(x,y) ((x>y)?y:x)

struct strCmp {
	bool operator()( const char* s1, const char* s2 ) const {
		return strcmp( s1, s2 ) < 0;
	}
};

int main()
{
	int S[100], Q[1000];
	int R[100][1000];
	int Rm=0, tmp=65535;
	int i, j, l;
	int m, n, k;
	char ss[100][100];
	char stmp[100];
	map<const char*, int, strCmp> se;
	map<const char*, int>::iterator iter;

	for(j=0;j<100;j++) S[j]=j;

	cin >> k;
	cin.getline(stmp, 100);
	for(l=0;l<k;l++) {
		se.clear();
		Rm=0;
		cin >> m;
		cin.getline(stmp, 100);
		for(j=0;j<m;j++) {
			cin.getline(ss[j], 100, '\n');
			se[ss[j]]=j;
		}
		cin >> n;
		cin.getline(stmp, 100);
		for(i=0;i<n;i++) {
			cin.getline(stmp, 100);
			Q[i]=se.find(stmp)->second;
		}
		for(j=0;j<m;j++) {
			if(S[j]==Q[0]) R[j][0]=65535;
			else R[j][0]=0;
		}
		for(i=1;i<n;i++) {
			tmp=65535;
			for(j=0;j<m;j++) {
				if(S[j]==Q[i]) {
					R[j][i]=65535;
				}
				else {
					R[j][i]=min(R[j][i-1], Rm+1);
				}
				if(R[j][i]<tmp) tmp=R[j][i];
			}
			Rm=tmp;
		}
		if(n>0) {
			tmp=65535;
			for(j=0;j<m;j++) 
				if(R[j][n-1]<tmp) tmp=R[j][n-1];
		} else tmp=0;
		printf("Case #%d: %d\n", l+1, tmp);
	}
	return 0;
}
