#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main()
{
	int i, j;
	int a, b, m, n=1;
	int hh, mm;
	int ac, bc, aa, bb, act;
	vector<int> timeT;

	scanf("%d", &n);
	for(j=0;j<n;j++) {
		timeT.clear();
		scanf("%d", &m);
		scanf("%d %d", &a, &b);
		for(i=0;i<a;i++) {
			scanf("%d:%d", &hh, &mm);
			timeT.push_back(hh*600+mm*10+1);
			scanf("%d:%d", &hh, &mm);
			timeT.push_back(hh*600+mm*10+m*10+2);
		}
		for(i=0;i<b;i++) {
			scanf("%d:%d", &hh, &mm);
			timeT.push_back(hh*600+mm*10+3);
			scanf("%d:%d", &hh, &mm);
			timeT.push_back(hh*600+mm*10+m*10+0);
		}
		sort(timeT.begin(), timeT.end());

		aa=0; bb=0; ac=0; bc=0;
		for(i=0;i<timeT.size();i++) {
			act=timeT[i]%10;
			if(act==1) {
				if(aa>0) aa--;
				else ac++;
			} else if(act==0) aa++;
			else if(act==3) {
				if(bb>0) bb--;
				else bc++;
			} else if(act==2) bb++;
		}
		printf("Case #%d: %d %d\n", j+1, ac, bc);
	}
}
