#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>
#include <algorithm>
#include <limits>
#include <stdio.h>
using namespace std;

struct mset {
	double ex;
	double pb;
};

void FloydWarshall(vector<vector<double> > &dismap, int m)
{
	for(int k=0;k<m;k++) {
		for(int i=0;i<m;i++) {
			for(int j=0;j<m;j++) 
				dismap[i][j]=min(dismap[i][j], dismap[i][k]+dismap[k][j]);
		}
	}
}

void genTab(bitset<32> &loc, vector<vector<double> > &dismap,
				vector<double> &locprob, vector<mset> &ma, 
				int m, int prev, int lvl, int k)
{
	if(lvl==k) {
//	cout << loc.to_ulong()<<" "<<loc.to_string()<<endl;
		for(int i=1;i<m;i++) {
			if(loc.test(i)) continue;
			double tmin=1E+37;
			double pb;
			for(int j=1;j<m;j++) {
				if(!loc.test(j)) continue;
				bitset<32> tloc=loc;
				tloc.set(j, 0);
				int ind=j*(1<<m) + tloc.to_ulong();
				double tmp=ma[ind].ex+(1-ma[ind].pb)*dismap[i][j];
				if(tmp<tmin) { 
					tmin=tmp; 
					pb=ma[ind].pb;
				}
			}
			int ind=i*(1<<m) + loc.to_ulong();
			ma[ind].ex=tmin;
			ma[ind].pb=pb+locprob[i];
		}
		return;
	}
	for(int i=prev+1;i<m;i++) {
		loc.set(i, 1);
		genTab(loc,dismap,locprob,ma,m,i,lvl+1,k);
		loc.set(i, 0);
	}
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	int m, c;
	map<string, int> locmap;
	vector<double> locprob;

	fin >>m;
	for(int i=0;i<m;i++) {
		string stmp;
		double prob;
		fin >>stmp>>prob;
		locmap[stmp]=locmap.size()-1;
		locprob.push_back(prob);
	}
	vector<vector<double> > dismap(m, 
					vector<double>(m, numeric_limits<double>::max()));
	fin>>c;
	for(int i=0;i<c;i++) {
		string s1, s2;
		double dis;
		fin >>s1>>s2>>dis;
		int i1=locmap[s1], i2=locmap[s2];
		dismap[i1][i2]=dis;
		dismap[i2][i1]=dis;
	}
	for(int i=0;i<m;i++) dismap[i][i]=0;
	FloydWarshall(dismap, m);
	for(int i=1;i<m;i++) {
		if(locprob[i]>0 && dismap[0][i]==numeric_limits<double>::max()) {
			cout <<"-1.00"<<endl;
			return 0;
		}
	}

	bitset<32> locvec(0);
	vector<mset> ma(m*(1<<m));
	for(int i=1;i<m;i++) {
		int ind=i*(1<<m);
		ma[ind].pb=locprob[0]+locprob[i];
		ma[ind].ex=(1-locprob[0])*dismap[i][0];
	}
	for(int k=0;k<m;k++) 
		genTab(locvec,dismap,locprob,ma,m,0,0,k+1);
	for(int i=1;i<m;i++) locvec.set(i, 1);
	double tmin=numeric_limits<double>::max();
	for(int i=1;i<m;i++) {
		locvec.set(i, 0);
		int ind=i*(1<<m) + locvec.to_ulong();
		double tmp=ma[ind].ex;
		if(tmp<tmin) tmin=tmp;
		locvec.set(i, 1);
	}
//	for(int i=0;i<ma.size();i++) cout <<i<<" "<<ma[i].ex<<" "<<ma[i].pb<<endl;
	printf("%.2lf\n", tmin);
}

