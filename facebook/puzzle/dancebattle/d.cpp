#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int ABprun(vector<vector<bool> > &na, int n, int ni, int w)
{
	int i, r, mr=0;
	for(i=0;i<ni;i++) {
		if(!na[i][ni]) {
			na[i][ni]=true;
			r=ABprun(na, n, i, -1*w);
			na[i][ni]=false;
			if(r==w) return w;
			else mr=r;
		}
	}
	for(i=ni;i<n;i++) {
		if(!na[ni][i]) {
			na[ni][i]=true;
			r=ABprun(na, n, i, -1*w);
			na[ni][i]=false;
			if(r==w) return w;
			else mr=r;
		}
	}
	if(mr==0) return -1*w;
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	int n, r;
	fin >> n;
	vector<vector<bool> > na(n, vector<bool>(n, false));
	map<int, int> nm;
	int l, x1, x2, tt;
	fin >>l;
	for(int i=0;i<l;i++) {
		fin >> x1 >> x2;
		if(nm.find(x1)==nm.end()) nm[x1]=nm.size()-1;
		if(nm.find(x2)==nm.end()) nm[x2]=nm.size()-1;
		int nx1=nm[x1];
		int nx2=nm[x2];
		tt=nx2;
		if(nx1>nx2) { nx2=nx1; nx1=nx2; }
//		cout << nx1 <<" "<< nx2<< endl;
		na[nx1][nx2]=true;
	}
//cout << nm.size() << " " << tt << endl;
//for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout << na[i][j] << " ";
	r=ABprun(na, nm.size(), tt, (l%2)?(-1):1);
	if(r>0) cout << "Win" << endl;
	else cout << "Lose" << endl;
}
