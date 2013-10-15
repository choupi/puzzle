#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct mPair {
	int a;
	int b;
	int sc;
};

bool cmpP(const mPair &a, const mPair &b)
{
	if(a.sc==b.sc && a.a==b.a) return a.b < b.b;
	if(a.sc==b.sc) return a.a > b.a;
	return a.sc < b.sc;
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	int m, n;
	string stmp;
	fin >> m >>n;
	vector<vector<int> > englist(m, vector<int>(n, n+100));
	vector<vector<int> > engNl(m);
	vector<int> engN(m);
	for(int i=0;i<n+1;i++) getline(fin, stmp);
	for(int i=0;i<m;i++) {
		getline(fin, stmp);
		if(stmp.size()==0) break;
		for(int j=0;j<stmp.size();j++)
			if(stmp[j]==',') stmp[j]=' ';
		istringstream sstr(stmp);
		int mi, ni, tni=-1, tn=0;
		sstr >> mi;
		while(sstr) {
			sstr >> ni;
			if(ni==tni) break;
			englist[i][ni]=tn;
			engNl[i].push_back(ni);
			tni=ni;
			tn++;
		} 
		engN[i]=tn;
	}
	vector<vector<mPair> > ml(m/2);
	vector<vector<int> > mpf(m, vector<int>(m/2, 0));
	for(int i=0;i<m/2;i++) {
		for(int j=m/2;j<m;j++) {
			if(i==j) continue;
			int sc=0;
			for(int k=0;k<engNl[i].size();k++) {
				int kk=engNl[i][k];
				if(englist[i][kk]>n || englist[j][kk]<englist[i][kk]) continue;
				else if(englist[i][kk]==englist[j][kk]) 
					sc+=(engN[i]-englist[i][kk])*(engN[i]-englist[i][kk]);
				else sc+=(engN[i]-englist[i][kk]);
			}
			mPair p;
			//cout << i<<" "<<j<<" "<<sc<<endl;
			p.a=i; p.b=j; p.sc=sc;
			ml[i].push_back(p);
			sc=0;
			for(int k=0;k<engNl[j].size();k++) {
				int kk=engNl[j][k];
				if(englist[j][kk]>n || englist[i][kk]<englist[j][kk]) continue;
				else if(englist[i][kk]==englist[j][kk]) 
					sc+=(engN[j]-englist[j][kk])*(engN[j]-englist[j][kk]);
				else sc+=(engN[j]-englist[j][kk]);
			}
			//cout << j<<" "<<i<<" "<<sc<<endl;
			mpf[j][i]=sc;
		}
	}
	for(int i=0;i<m/2;i++) make_heap(ml[i].begin(), ml[i].end(), cmpP);
	
	vector<int> px(m, -1);
	queue<int> qx;
	for(int i=0;i<m/2;i++) qx.push(i);
	while(!qx.empty()) {
		int m=qx.front();
		qx.pop();
		int w=ml[m].front().b;
		pop_heap(ml[m].begin(), ml[m].end(), cmpP);
		ml[m].pop_back();
		if(px[w]>-1) {
			int pw=px[w];
			if(mpf[w][pw]<mpf[w][m] || 
				(mpf[w][pw]==mpf[w][m] && m>pw)) {
				qx.push(pw);
				px[m]=w;
				px[w]=m;
			} else qx.push(m);
		} else {
			px[m]=w;
			px[w]=m;
		}
	}
	for(int i=0;i<m/2;i++) cout << i <<" "<<px[i]<<endl;
				
}

