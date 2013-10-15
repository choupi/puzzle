#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#define MINF (999999999)

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	string ins;
	int cap;
	vector<vector<int> > good;
	int i;

	fin>>cap;
	getline(fin, ins);
	i=0;
	int maxg=0;
	while(getline(fin, ins)) {
		if(ins.size()==0) break;
		istringstream ss(ins);
		string tmps;
		vector<int> g(2);
		ss >> tmps >> g[0] >> g[1];
		good.push_back(g);
		int tmpm=good[i][0]-(cap%good[i][0]);
		if(maxg<tmpm) maxg=tmpm;
		i++;
	}
	//cerr << cap<<" "<<maxg<<endl;

	int maxt=maxg+cap+1;
	vector<int> tab(maxt, 0);
	for(i=1;i<maxt;i++) {
		int mmin=MINF;
		for(int j=0;j<good.size();j++) {
			int va=(i-good[j][0]<0)?MINF:tab[i-good[j][0]];
			if(va+good[j][1]<mmin) mmin=va+good[j][1];
		}
		tab[i]=mmin;
	}
	int mmin=MINF;
//	for(i=0;i<maxt;i++) cout <<i<<": "<<tab[i] <<endl;
	for(i=cap;i<maxt;i++) if(tab[i]<mmin) mmin=tab[i];
	cout << mmin <<endl;
}

