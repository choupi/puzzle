#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);

	map<string, int> sIno;
	map<string, int> sOut;
	vector<string> mails;
	vector<list<int> > nblist;
	string stmp;
	while(getline(fin, stmp)) {
		stringstream ss(stmp);
		string s1, s2;
		for(int i=0;i<6;i++) ss>>s1;
		ss>>s1; ss>>s2;
		if(sIno.find(s1)==sIno.end()) {
			sIno[s1]=sIno.size()-1;
			sOut[s1]=-1;
			mails.push_back(s1);
			list<int> nl;
			nblist.push_back(nl);
		}
		if(sIno.find(s2)==sIno.end()) {
			sIno[s2]=sIno.size()-1;
			sOut[s2]=-1;
			mails.push_back(s2);
			list<int> nl;
			nblist.push_back(nl);
		}
		int is1=sIno[s1];
		int is2=sIno[s2];
		nblist[is1].push_back(is2);
	}
	int ixxx=0;
	for(map<string,int>::iterator it=sOut.begin();it!=sOut.end();it++) {
		it->second=ixxx++;
		//cout << it->first<<it->second<<endl;
	}
	int n=ixxx;
	//cout<<n<<endl;
	vector<vector<bool> > adj(n, vector<bool>(n, false));
	for(int i=0;i<nblist.size();i++) {
		int is1=sOut[mails[i]];
		for(list<int>::iterator it=nblist[i].begin();it!=nblist[i].end();it++) {
			int is2=sOut[mails[*it]];
			adj[is1][is2]=true;
		}
	}
	
	vector<list<int> > clist[2];
	list<int> ltmp; ltmp.push_back(0);
	clist[0].push_back(ltmp);
	for(int i=1;i<n;i++) {
		int now=i%2;
		int old=1-now;
		bool flag=true;
		for(vector<list<int> >::iterator it=clist[old].begin();
										it!=clist[old].end();it++) {
			list<int> mlist;
			for(list<int>::iterator iit=it->begin();iit!=it->end();iit++) {
				if(adj[i][*iit] && adj[*iit][i]) mlist.push_back(*iit);
			}
			mlist.push_back(i);
			if(mlist.size()<=it->size()) clist[now].push_back(*it);
			if(mlist.size()>1) {
				clist[now].push_back(mlist);
				flag=false;
			}
		}
		if(flag) {
			list<int> mlist; mlist.push_back(i); clist[now].push_back(mlist);
		}
		//clist[now].sort();
		//clist[now].unique();
		clist[old].clear();
	}
	sort(clist[(n-1)%2].begin(), clist[(n-1)%2].end());
	for(map<string,int>::iterator it=sOut.begin();it!=sOut.end();it++) {
		mails[it->second]=it->first;
	}
	for(vector<list<int> >::iterator it=clist[(n-1)%2].begin();
									it!=clist[(n-1)%2].end();it++) {
		if(it->size()<3) continue;
		bool setinc=false;
		for(vector<list<int> >::iterator iit=clist[(n-1)%2].begin();
									iit!=it;iit++) {
			if(includes(iit->begin(), iit->end(), it->begin(), it->end())) {
				setinc=true;
				break;
			}
		}
		if(setinc) continue;
		list<int>::iterator iit=it->begin();
		for(int i=0;i<it->size()-1;i++) {
			cout << mails[*iit]<<", ";
			iit++;
		}
		cout <<mails[*iit]<<endl;
	}
}

