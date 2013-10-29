#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int pix[105];
	int np[105];
	int T, D, I, M, N;
	cin >> T;

	for(int tt=0;tt<T;tt++) {
		cin >> D>> I>> M>> N;
		for(int i=0;i<N;i++) cin >> pix[i];
		for(int i=0;i<N;i++) np[i]=pix[i];

		int cost=0;
		for(int i=1;i<N;i++) {
			int ta=np[i]-np[i-1];
			if(abs(ta)<=M) continue;
			int da=abs(ta)-M;
			int mm=da;
			int fa1=0, fa2=0, fa3=da-M;
			if(i+1<N) {
				fa1=abs(np[i]-np[i+1]);
				fa2=abs(np[i-1]-np[i+1]);
			}
			if(fa1>M) fa1-=M;
			else fa1=0;
			if(fa2>M) fa2-=M;
			else fa2=0;
			if(fa3>M) fa3-=M;
			else fa3=0;
			if(M!=0 && I+fa1+fa3 < D+fa2) {
				if(mm<I) {
					np[i]+=(ta>0)?(-1*da):da;
					cost+=mm;
					continue;
				}
				np[i-1]+=(ta>0)?M:(-1*M);
				i--;
				cost+=I;
			}
			else {
				if(mm<D) {
					np[i]+=(ta>0)?(-1*da):da;
					cost+=mm;
					continue;
				}
				np[i]=np[i-1];
				cost+=D;
			}
		}
		cout << "Case #"<<tt+1<<": "<<cost<<endl;
	}
}

		
