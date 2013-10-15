#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct mPair {
	int a;
	int b;
	int sc;
};

bool cmpP(const mPair &a, const mPair &b)
{
	if(a.sc==b.sc) return a.b > b.b;
	return a.sc < b.sc;
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	int m, n;
	string stmp;
	fin >> m >>n;
	vector<vector<int> > englist(m, vector<int>(n, n+100));
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
			tni=ni;
			tn++;
		} 
		engN[i]=tn;
	}
	vector<vector<mPair> > ml(m);
	for(int i=0;i<m/2;i++) {
		for(int j=m/2;j<m;j++) {
			if(i==j) continue;
			int sc=0;
			for(int k=0;k<n;k++) {
				if(englist[i][k]>n || englist[j][k]<englist[i][k]) continue;
				else if(englist[i][k]==englist[j][k]) 
					sc+=(engN[i]-englist[i][k])*(engN[i]-englist[i][k]);
				else sc+=(engN[i]-englist[i][k]);
			}
			mPair p;
			p.a=i; p.b=j; p.sc=sc;
			ml[i].push_back(p);
		}
		make_heap(ml[i].begin(), ml[i].end(), cmpP);
//		sort_heap(ml[i].begin(), ml[i].end(), cmpP);
	}
	
	
	vector<mPair> totl;
	for(int i=0;i<m/2;i++) {
		totl.push_back(ml[i].front());
		pop_heap(ml[i].begin(), ml[i].end(), cmpP);
		ml[i].pop_back();
	}
	make_heap(totl.begin(), totl.end(), cmpP);
	vector<int> vx(m, -1);
	while(!totl.empty()) {
		mPair p=totl.front();
		pop_heap(totl.begin(), totl.end(), cmpP);
		totl.pop_back();
		if(vx[p.b]<0) {
			vx[p.a]=p.b;
			vx[p.b]=p.a;
		} else {
			totl.push_back(ml[p.a].front());
			push_heap(totl.begin(), totl.end(), cmpP);
			pop_heap(ml[p.a].begin(), ml[p.a].end(), cmpP);
			ml[p.a].pop_back();
		}
	}

	for(int i=0;i<m/2;i++) cout << i << " "<<vx[i]<<endl; 
/*
	for(int i=0;i<ml.size();i++) {
		for(int j=0;j<ml[i].size();j++) 
			cout << ml[i][j].a <<" "<<ml[i][j].b<<" "<<ml[i][j].sc<<endl;
	}
	*/
}

