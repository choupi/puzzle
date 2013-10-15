#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>
#include <stdlib.h>
using namespace std;

#define min(x, y) (x<y?x:y)
#define min3(x, y, z) (min(x,min(y,z)))

struct trieN {
	char alpha;
	list<trieN*> child;
};

int tmin;

trieN* findTrie(list<trieN*> &mlist, char a)
{
	for(list<trieN*>::iterator it=mlist.begin();it!=mlist.end();it++) {
		if((*it)->alpha==a) return *it;
	}
	return NULL;
}

void insertTrie(trieN *mtrie, string w)
{
	int i;
	trieN *curr=mtrie;
	for(int i=0;i<w.length();i++) {
		trieN* next=findTrie(curr->child, w[i]);
		if(next!=NULL) curr=next;
		else {
			trieN *newN=new trieN;
			newN->alpha=w[i];
			curr->child.push_back(newN);
			curr=curr->child.back();
		}
	}
	trieN *newN=new trieN;
	newN->alpha='\0';
	curr->child.push_front(newN);
}

void lcs(string w, trieN *curr, int* plt, int lvl)
{
	int ltab[150];
	int lmin=65535;
	if(curr->alpha=='@') {
		for(int i=0;i<w.length();i++) 
			ltab[i]=i+1;
		lmin=0;
	} else if(curr->alpha=='\0') {
		if(plt[w.length()-1]<tmin) tmin=plt[w.length()-1];
		return;
	} else {
		for(int i=0;i<w.length();i++) {
			if(i>0) {
				if(w[i]==curr->alpha) ltab[i]=plt[i-1];
				else ltab[i]= min3(plt[i], plt[i-1], ltab[i-1])+1;
			} else {
				if(w[i]==curr->alpha) ltab[i]=lvl;
				else ltab[i]=min(plt[i], lvl)+1;
			}
			if(ltab[i]<lmin) lmin=ltab[i];
		}
	}
/*for(int i=0;i<w.length();i++) 
		cout << plt[i];
	cout << endl;*/

	if(lmin <tmin) {
		for(list<trieN*>::iterator iter=curr->child.begin();
									iter!=curr->child.end();iter++) 
			lcs(w, *iter, ltab, lvl+1);
	}
}

int main(int argc, char* argv[])
{
	trieN mtrie;
	ifstream fin(argv[1]);
	int sum=0;
	int tmp;
	vector<string> wlist;
//	ifstream words("twl06.txt");
	ifstream words("/var/tmp/twl06.txt");
	mtrie.alpha='@';
	while(!words.eof()) {
		string w;
		words>>w;
		if(w.length() < 1) continue;
		for(int i=0;i<w.length();i++)
			if(w[i]<97) w[i]+=32;
		insertTrie(&mtrie, w);
	}
	words.close();

	while(!fin.eof()) {
		string inw;
		fin >> inw;
		if(inw.length()<1) continue;
//		cout << inw << endl;
		tmin=65535;
		lcs(inw, &mtrie, NULL, -1);
//		cout << tmin << endl;
		sum+=tmin;
	}
	cout << sum << endl;
}
