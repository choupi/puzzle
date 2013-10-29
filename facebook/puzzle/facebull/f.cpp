#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

#define BITNO (64)

long long gmin;
bitset<BITNO> gbitM;
struct machine {
	string mname;
	string cA;
	string cB;
	int cAn;
	int cBn;
	long long price;
};

bool mCmp(machine a, machine b)
{
	return a.price < b.price;
}

void DFS(vector<machine> &vecM, vector<vector<int> > &adj, 
		bitset<BITNO> &bitM, bitset<BITNO> &bit, int cur, bool t)
{
	bit.set(cur);
	for(int i=0;i<adj[cur].size();i++) {
		if(!bitM.test(adj[cur][i])) continue;
		int next=t?vecM[adj[cur][i]].cAn:vecM[adj[cur][i]].cBn;
		if(!bit.test(next)) DFS(vecM, adj, bitM, bit, next, t);
	}
}

void generateM(vector<machine> &vecM, 
				vector<vector<int> > &adjM, vector<vector<int> > &adjMt,
				bitset<BITNO> &bitM, int cN, int sum, int lvl)
{
	if(sum>=gmin) return;
	if(lvl==cN) {
		bitset<BITNO> bitC;
		DFS(vecM, adjM, bitM, bitC, 0, false);
		if(bitC.count()==cN) {
			bitset<BITNO> bitCt;
			DFS(vecM, adjMt, bitM, bitCt, 0, true);
			//		cout <<sum<<"@@"<<bitCt.to_ulong()<<endl;
			if(bitCt.count()==cN) {
				gmin=sum;
				gbitM=bitM;
				cout << gmin<<" "<< gbitM<<endl;
			}
		}
		return;
	}
	for(int i=0;i<adjM[lvl].size();i++) {
		bool ti=bitM.test(adjM[lvl][i]);
		int isum=ti?0:vecM[adjM[lvl][i]].price;
		if(isum+sum>=gmin) continue;
		bitM.set(adjM[lvl][i]);
//		generateM(vecM, adjM, adjMt, bitM, cN, sum+isum, lvl+1);
		for(int j=0;j<adjMt[lvl].size();j++) {
			bool tj=bitM.test(adjMt[lvl][j]);
			int jsum=tj?0:vecM[adjMt[lvl][j]].price;
			bitM.set(adjMt[lvl][j]);
			generateM(vecM, adjM, adjMt, bitM, cN, sum+isum+jsum, lvl+1);
			bitM.set(adjMt[lvl][j], tj);
		}
		bitM.set(adjM[lvl][i],ti);
	}
}


int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	vector<machine> vecM;
	map<string,int> mapC;

	string stmp;
	while(getline(fin, stmp)) {
		if(stmp.length()<1) break;
		istringstream sstr(stmp);
		machine mm;
		sstr>>mm.mname>>mm.cA>>mm.cB>>mm.price;
		if(mapC.find(mm.cA)==mapC.end()) {
			mm.cAn=mapC.size();
			mapC[mm.cA]=mm.cAn;
		} else mm.cAn=mapC[mm.cA];
		if(mapC.find(mm.cB)==mapC.end()) {
			mm.cBn=mapC.size();
			mapC[mm.cB]=mm.cBn;
		} else mm.cBn=mapC[mm.cB];
		vecM.push_back(mm);
	}
	sort(vecM.begin(), vecM.end(), mCmp);
	int cN=mapC.size();
	int mN=vecM.size();
	vector<vector<int> > adjM(cN, vector<int>());
	vector<vector<int> > adjMt(cN, vector<int>());
	for(int i=0;i<mN;i++) {
		adjM[vecM[i].cAn].push_back(i);
		adjMt[vecM[i].cBn].push_back(i);
	}
	bitset<BITNO> bitM(0);
	gmin=999999999;
	generateM(vecM, adjM, adjMt, bitM, cN, 0, 0);
	cout << gmin<<endl;
//	cout << gbitM<<endl;
	vector<int> outV;
	int otmp;
	for(int i=0;i<mN;i++) {
		if(gbitM.test(i)) {
			istringstream ss(vecM[i].mname.c_str()+1);
			ss>>otmp;
			outV.push_back(otmp);
		}
	}
	sort(outV.begin(), outV.end());
	if(outV.size()>0) cout << outV[0];
	for(int i=1;i<outV.size();i++) cout << " "<<outV[i];
	cout <<endl;
}
	
