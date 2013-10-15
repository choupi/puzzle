#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
	int id;
	double x;
	double y;
};

struct distP {
	int id;
	double dist;
};

struct kdNode {
	struct kdNode *ln;
	struct kdNode *rn;
	int id;
	int ax;
};

bool cmp(const struct distP &a, const struct distP &b)
{
	return a.dist < b.dist;
}

bool cmpX(const struct point &a, const struct point &b)
{
	return a.x < b.x;
}

bool cmpY(const struct point &a, const struct point &b)
{
	return a.y < b.y;
}

double distNN(vector<point> &fri, int i, int j)
{
	return (fri[i].x-fri[j].x)*(fri[i].x-fri[j].x)
				+(fri[i].y-fri[j].y)*(fri[i].y-fri[j].y);
}

struct kdNode* buildKDTree(vector<point> &vp, int st, int en, int dep)
{
	if(st>en) return NULL;
	vector<point>::iterator it=vp.begin();
	int median=(st+en)/2;
	nth_element(it+st, it+median, it+en+1, dep%2?cmpX:cmpY);
	struct kdNode *kdn= new struct kdNode;
	kdn->id=median;
	kdn->ax=dep%2;
	kdn->ln=buildKDTree(vp, st, median-1, dep+1);
	kdn->rn=buildKDTree(vp, median+1, en, dep+1);
	return kdn;
}

bool nearN(kdNode *here, int fid, vector<point> &fri)
{
	if(here->ax) 
		return fri[here->id].x-fri[fid].x>0;
	else return fri[here->id].y-fri[fid].y>0;
}

void tKDT(kdNode *here, vector<point> &fri)
{
	if(here==NULL) return;
	cout << fri[here->id].id <<"(";
	tKDT(here->ln, fri);
	cout <<",";
	tKDT(here->rn, fri);
	cout << ")";
}

void searchKDTree(kdNode *here, int fid, vector<point> &fri, vector<distP> &nl)
{
	if(here==NULL) return;
	//cerr<<fri[here->id].id;
	if(fid!=here->id) {
		double distH=distNN(fri, fid, here->id);
		if(distH<nl.back().dist) {
		//cerr<<" "<<fri[fid].id<<" "<<distH;
			nl.back().id=here->id;
			nl.back().dist=distH;
			sort(nl.begin(), nl.end(), cmp);
		}
	}
	//cerr<<endl;
	kdNode *ch_near;
	kdNode *ch_far;
	if(nearN(here, fid, fri)) {
		ch_near=here->ln;
		ch_far=here->rn;
	} else {
		ch_near=here->rn;
		ch_far=here->ln;
	}
	if(ch_near!=NULL) {
		searchKDTree(ch_near, fid, fri, nl);
	}
	if(ch_far!=NULL) {
		double ad;
		if(here->ax) 
			ad=(fri[here->id].x-fri[fid].x)*(fri[here->id].x-fri[fid].x);
		else ad=(fri[here->id].y-fri[fid].y)*(fri[here->id].y-fri[fid].y);
		//cerr <<"axis: "<<ad<<" "<<fri[here->id].id<<" "<<fri[fid].id<<endl;
		if(ad<nl.back().dist) searchKDTree(ch_far, fid, fri, nl);
	}
}

int main(int argc, char* argv[])
{
	ifstream fin(argv[1]);
	string mstr;
	vector<point> fri;
	vector<int> od;
	map<int, int> vid;
	point ff;
	double xs, ys, gs;
	int n, ns;

	while(getline(fin, mstr)) {
		if(mstr.size()==0) break;
		istringstream sstr(mstr);
		sstr >> ff.id >> ff.x >> ff.y;
		fri.push_back(ff);
		od.push_back(ff.id);
	}
	struct kdNode *kdt=buildKDTree(fri, 0, fri.size()-1, 0);
	//tKDT(kdt, fri);
	//cout << endl;
	for(int i=0;i<fri.size();i++) {
		vid[fri[i].id]=i;
	}
	for(int i=0;i<od.size();i++) {
//	for(int i=30;i<31;i++) {
		vector<distP> nlist;
		int id=vid[od[i]];
		struct distP dp; dp.dist=1E+37; dp.id=999999;
		nlist.push_back(dp); nlist.push_back(dp); nlist.push_back(dp);
		searchKDTree(kdt, id, fri, nlist);
		cout << fri[id].id << " ";
		cout << fri[nlist[0].id].id << ",";
		cout << fri[nlist[1].id].id << ",";
		cout << fri[nlist[2].id].id <<endl;
		/*
		cout << fri[nlist[0].id].id << "@@"<<nlist[0].dist<<",";
		cout << fri[nlist[1].id].id << "@@"<<nlist[1].dist<<",";
		cout << fri[nlist[2].id].id << "@@"<<nlist[2].dist<<endl;
		*/
	}
}
