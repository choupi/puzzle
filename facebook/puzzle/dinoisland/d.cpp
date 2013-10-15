#include "Dinosaur.h" 

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

#include <pthread.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace std;

Direction dirA[8]={N,NE,E,SE,S,SW,W,NW};
EntityType entA[3]={PLANT,HERBIVORE,CARNIVORE};
EntityType cEAT=entA[0];
EntityType mTYPE=entA[1];
int mRANGE=pow(6,2);
queue<int64_t> que;

int distanceC(Coordinate& a, Coordinate& b)
{
	return (a.row-b.row)*(a.row-b.row)+(a.column-b.column)*(a.column-b.column);
}

void printDS(DinosaurState& disS)
{
	cout << "c: "<<disS.calories<<" s: "<<disS.size<<endl;
//	cout << "egg: "<<disS.eggCost <<" grow: "<<disS.growCost<<" look: "
//		<<disS.lookCost<<" move: "<<disS.moveCost<<endl;
}

bool checkLR(LookResults& lkR)
{
	int s=0;
	for(int i=0;i<lkR.thingsSeen.size();i++) {
//		if(lkR.thingsSeen[i].size <= lkR.myState.size 
		if(lkR.thingsSeen[i].type==cEAT) {
			int dis=pow(lkR.thingsSeen[i].coordinate.row, 2)+
					pow(lkR.thingsSeen[i].coordinate.column, 2);
			if(dis<mRANGE) {
				s++;
				cerr << dis<<" ";
			}
		}
	}
	cerr << "@@@"<<s<<endl;
	return s<1;
}

void printLR(LookResults& lkR)
{
	cout <<lkR.message<<endl;
	for(int i=0;i<5;i++) 
		cerr << lkR.thingsSeen[i].coordinate.row <<" "
				<<lkR.thingsSeen[i].coordinate.column<<endl;
	cerr<< "========="<<endl;
//	printDS(lkR.myState);
}

void LookAround(DinosaurClient& client, vector<vector<int> > &ftable)
{
	int frange=ftable.size();
	int mpos=frange/2;
	int count=0;
	for(int k=0;k<8;k+=2) {
		Direction dd=dirA[k];
		LookResults lkR;
		client.look(lkR, dd);
		for(int i=0;i<lkR.thingsSeen.size();i++) {
			if(lkR.thingsSeen[i].type!=cEAT) continue;
			int r=lkR.thingsSeen[i].coordinate.row;
			int c=lkR.thingsSeen[i].coordinate.column;
			if(r+mpos>=0 && r+mpos<frange && c+mpos>=0 && c+mpos<frange) {
				ftable[r+mpos][c+mpos]=lkR.thingsSeen[i].size;
				count++;
			}
		}
	}
	cout << "see "<<count<< " food"<<endl;
}

bool FindNearest(vector<vector<int> > &ftable, Coordinate& mpos, Coordinate& f)
{
	int dmin=9999;
	bool fl=false;
	for(int i=0;i<ftable.size();i++) {
		for(int j=0;j<ftable[i].size();j++) {
			if(ftable[i][j]==0) continue;
			Coordinate t; t.row=i; t.column=j;
			int dis=distanceC(mpos, t);
			if(ftable[i][j]<15) {
				dis-=ftable[i][j]/2;
				if(dis<1) dis=1;
			}
			if(dis<dmin && dis>0) {
				f.row=i; f.column=j; dmin=dis;
				fl=true;
			}
		}
	}
	if(!fl) cout <<"No food nearby"<<endl;
	else cout<<"Nearest distance "<<dmin<<endl;
	return fl;
}

int chooseD(Coordinate& mpos, Coordinate& f)
{
	int r=f.row-mpos.row;
	int c=f.column-mpos.column;
	if(r==0) {
		if(c==0) return -1;
		else if(c>0) return 2;
		else return 6;
	} else if(r>0) {
		if(c==0) return 4;
		else if(c>0) return 3;
		else return 5;
	} else {
		if(c==0) return 0;
		else if(c>0) return 1;
		else return 7;
	}
}

void updateMpos(Coordinate& mpos, int d)
{
	if(d==0) { mpos.row-=1; }
	else if(d==4) { mpos.row+=1; }
	else if(d==2) { mpos.column+=1; }
	else if(d==6) { mpos.column-=1; }
	else if(d==1) { mpos.row-=1; mpos.column+=1; }
	else if(d==3) { mpos.row+=1; mpos.column+=1; }
	else if(d==5) { mpos.row+=1; mpos.column-=1; }
	else if(d==7) { mpos.row-=1; mpos.column-=1; }
}

bool newEgg(DinosaurClient& client, int cal)
{
	if(cal>25000) {
	try {
		EggResults eggR;
		client.egg(eggR, dirA[4], 20000);
		que.push(eggR.eggID);
		cout <<eggR.message<<" "<<eggR.eggID<<endl;
		return true;
	} catch (YouAreDeadException yad) {
		cerr << yad.description<<endl;
		cout << yad.description<<endl;
	}
	}
	return false;
}

void* main_thread(void* arg) {
	int port=9033;
	boost::shared_ptr<TSocket> socket(new TSocket("thriftpuzzle.facebook.com", port));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	DinosaurClient client(protocol);
	transport->open();

	string email("chromosome460@gmail.com");
//	string email(argv[1]);
	int64_t args=*((int64_t*)arg);
	if(!args) {
		cout << email<<endl;
		RegisterClientResults regR;
		client.registerClient(regR, email, "choupi", mTYPE);
		cout << "registerClient"<<endl;
		cout << regR.message<<endl;
		args=regR.eggID;
		cout << regR.species << " "<<args<<endl;
	}
try {
	DinosaurState disS;
	client.hatch(disS, args);
	*((int64_t*)arg)=0;
	printDS(disS);
} catch (BadEggException bee) {
	cerr << bee.description<<endl;
	cout << bee.description<<endl;
	return 0;
}
try {
	GrowResults gR;
	client.grow(gR);
	client.grow(gR);
	while(1) {
		int ftn=80, cal;
		vector<vector<int> > ft(ftn, vector<int>(ftn, 0));
		Coordinate mpos; mpos.row=ftn/2; mpos.column=ftn/2;
		Coordinate opos; opos.row=ftn/2; opos.column=ftn/2;
		Coordinate food;
		cout << "look around"<<endl;
		LookAround(client, ft);
		while(FindNearest(ft, mpos, food)) {
			int ms;
			while(mpos!=food) {
				int dd=chooseD(mpos, food);
				MoveResults mr;
				client.move(mr, dirA[dd]);
				cout << "choose "<<dirA[dd]<<endl;
				updateMpos(mpos, dd);
				cout << mr.message<<" "<<mpos.row<<","<<mpos.column<<endl;
				printDS(mr.myState);
				cal=mr.myState.calories;
				ms=mr.myState.size;
			}
			ft[food.row][food.column]=0;
//			newEgg(client, cal);
			if(ms<7 && cal>2000) {
				GrowResults gR;
				client.grow(gR);
			}
			if(distanceC(opos, mpos)>900) break;
		}
	}
} catch (YouAreDeadException yad) {
	cerr << yad.description<<endl;
	cout << yad.description<<endl;
	return 0;
} catch (GameOverException goe) {
	cerr << goe.message<<endl;
	cout << goe.message<<endl;
	cerr <<goe.score<<" Win?"<<goe.wonGame<<endl;
	cout <<goe.score<<" Win?"<<goe.wonGame<<endl;
}

	transport->close();

	return 0;
}

int main(int argc, char **argv)
{
	pthread_t pid;
	srand(time(NULL));
	int64_t egg=0;
	void* thread_result;
	pthread_create(&pid, NULL, main_thread, (void*)(&egg));
	while(1) {
		pthread_join(pid, &thread_result); 
		if(!que.empty()) { egg=que.front(); que.pop(); }
		else egg=0;
		pthread_create(&pid, NULL, main_thread, (void*)(&egg));
	}
			
	return 0;
}
