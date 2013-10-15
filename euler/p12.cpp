#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN (50000)

int main()
{
    int i, j, jj, k, bb, prod;
    map<int,int> table[MAXN];
    int oldp=2;
    table[2][2]=1;
    table[3][3]=1;
    for(i=4;i<MAXN;i++) {
    	bb=0;
    	for(j=sqrt(i)+1;j>1;j--) { 
	    if(i%j==0) {
	    	jj=i/j;
		table[i]=table[jj];
		for(map<int,int>::iterator it=table[j].begin();
			it!=table[j].end();it++)
		    table[i][it->first]+=it->second;
		bb=1;
		break;
	    }
	    if(bb) break;
	}
	if(!bb) table[i][i]=1;
	prod=1;
	for(map<int,int>::iterator jb=table[i].begin();jb!=table[i].end();
		jb++) {
	    if((*jb).first==2) prod*=jb->second;
	    else if((*jb).second>0) prod*=((*jb).second+1);
	}
	if(oldp*prod>500) { 
	    printf("%d: %d %d\n", i-1, (i-1)*i/2, oldp*prod);
	    break;
	}
	oldp=prod;
    }
}
    
