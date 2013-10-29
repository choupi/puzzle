#include <iostream>
#include <map>
using namespace std;

int main()
{
	int T;

	cin >> T;

	for(int tt=0;tt<T;tt++) {
		int N, M;
		map<string, bool> dirs;
		cin >> N >>M;
		for(int i=0;i<N;i++) {
			string ds;
			cin >> ds;
			dirs[ds]=true;
			while(ds.size()>2) {
				int tl=ds.find_last_of('/');
				ds=ds.substr(0, tl);
				if(ds.size()>1) dirs[ds]=true;
			}
		}
		int dsize=dirs.size();
		for(int i=0;i<M;i++) {
			string ds;
			cin >> ds;
			dirs[ds]=true;
			while(ds.size()>2) {
				int tl=ds.find_last_of('/');
				ds=ds.substr(0, tl);
				if(ds.size()>1) dirs[ds]=true;
			}
		}
//		map<string, bool>::iterator iter;
//		for(iter=dirs.begin();iter!=dirs.end();iter++) cout<< iter->first<<"@"<<endl;
//		cout << dsize <<" "<<dirs.size();
		cout << "Case #" << tt+1 << ": "<<dirs.size()-dsize<<endl;
	}
}


