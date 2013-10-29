#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

long long gmin;
bitset<32> gbitM;
struct machine {
	string mname;
	string cA;
	string cB;
	int cAn;
	int cBn;
	long long price;
};

void DFS(vector<vector<bool> > &adj, bitset<32> &bit, int cur)
{
	bit.set(cur);
	for(int i=0;i<adj.size();i++) {
		if(bit.test(i) || !adj[cur][i]) continue;
		DFS(adj, bit, i);
	}
}

void generateC(vector<machine> &vecM, bitset<32> &bitM, int cN, int k, 
								int prev, int lvl)
{
	if(lvl==k) {
		vector<vector<bool> > adjC(cN, vector<bool>(cN, false));
		vector<vector<bool> > adjCt(cN, vector<bool>(cN, false));
		long long sum=0;
		for(int i=0;i<vecM.size();i++) {
			if(!bitM.test(i)) continue;
			sum+=vecM[i].price;
			adjC[vecM[i].cAn][vecM[i].cBn]=true;
			adjCt[vecM[i].cBn][vecM[i].cAn]=true;
		}
		/*
		for(int i=0;i<adjC.size();i++) {
			for(int j=0;j<adjC[i].size();j++)
				cout << adjC[i][j];
			cout <<endl;
		}
		for(int i=0;i<adjCt.size();i++) {
			for(int j=0;j<adjCt[i].size();j++)
				cout << adjCt[i][j];
			cout <<endl;
		}
		*/
		if(sum<gmin) {
			bitset<32> bitC;
			DFS(adjC, bitC, 0);
			if(bitC.count()==cN) {
				bitset<32> bitCt;
				DFS(adjCt, bitCt, 0);
//		cout <<sum<<"@@"<<bitCt.to_ulong()<<endl;
				if(bitCt.count()==cN) {
					gmin=sum;
					gbitM=bitM;
				}
			}
		}
		return;
	}
	for(int i=prev+1;i<vecM.size();i++) {
		bitM.set(i);
		generateC(vecM, bitM, cN, k, i, lvl+1);
		bitM.reset(i);
	}
	return;
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
	int cN=mapC.size();
	int mN=vecM.size();
	bitset<32> bitM(0);
	gmin=999999999;
	for(int k=cN;k<cN*2;k++)
		generateC(vecM, bitM, cN, k, 0, 0);
	cout << gmin<<endl;
}
	
