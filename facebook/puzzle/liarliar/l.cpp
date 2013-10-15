#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
	int n, m;
	string name;
	ifstream fin(argv[1]);

	fin >> n;
	map<string, int> name_map;
	vector< vector<int> > nlist(n);
	for(int i=0;i<n;i++) {
		fin >> name >> m;
		map<string, int>::iterator iter=name_map.find(name);
		int idx;
		if(iter==name_map.end()) {
			idx=name_map.size();
			name_map[name]=idx;
		} else idx=name_map[name];
		for(int j=0;j<m;j++) {
			fin >> name;
			iter=name_map.find(name);
			int idx2;
			if(iter==name_map.end()) {
				idx2=name_map.size();
				name_map[name]=idx2;
			} else idx2=name_map[name];
			nlist[idx].push_back(idx2);
			nlist[idx2].push_back(idx);
		}
	}
	queue<int> nque;
	vector<bool> nnum(n, false);
	vector<bool> nvit(n, false);
	nque.push(0);
	nvit[0]=true;
	while(!nque.empty()) {
		int i=nque.front();
		nque.pop();
		for(int j=0;j<nlist[i].size();j++) {
			if(!nvit[nlist[i][j]]) {
				nnum[nlist[i][j]]=!nnum[i];
				nque.push(nlist[i][j]);
				nvit[nlist[i][j]]=true;
			}
		}
	}
	int c=0;
/*	for(int i=0;i<n;i++) 
		cout << nnum[i] << " ";
	cout << endl; */
	for(int i=0;i<n;i++) 
		if(nnum[i]) c++;
	int cn=n-c;
	if(c>cn)
		cout << c << " " << cn << endl;
	else cout << cn << " " << c << endl;
}

