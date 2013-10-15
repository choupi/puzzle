#include "RushHour.h" 

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

#include <iostream>
#include <vector>
#include <string>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace std;

map<string, int> intmap;
RoadMap rmap;
vector<Road> mpath;
vector<Road> tmppath;
double minTime=1E+37;

void RoadDFS(int curInt, vector<bool> &visited, double ctime)
{
	if(rmap.Intersections[curInt].Name=="I-FINISH") {
		if(minTime>ctime) {
			minTime=ctime;
			mpath=tmppath;
		}
		return;
	}

	for(int i=0;i<rmap.Intersections[curInt].ConnectedRoads.size();i++) {
		string intname=rmap.Intersections[curInt].ConnectedRoads[i].StartIntersection;
		if(intname==rmap.Intersections[curInt].Name) 
			intname=rmap.Intersections[curInt].ConnectedRoads[i].EndIntersection;
		int next=intmap[intname];
		if(visited[next]) continue;
		visited[next]=true;
		tmppath.push_back(rmap.Intersections[curInt].ConnectedRoads[i]);
		double ttime= rmap.Intersections[curInt].ConnectedRoads[i].Distance /
						rmap.Intersections[curInt].ConnectedRoads[i].CurrentSpeed;
		RoadDFS(next, visited, ctime+ttime);
		visited[next]=false;
		tmppath.pop_back();
	}
}
int main(int argc, char **argv) {
	int port=9032;
	boost::shared_ptr<TSocket> socket(new TSocket("thriftpuzzle.facebook.com", port));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	RushHourClient client(protocol);
	transport->open();

	string email("chromosome460@gmail.com");
	string mname("choupi");
	cout << email<<endl;
	client.registerClient(email, mname);
	cout << "registerClient"<<endl;
	client.getRoadConditions(rmap);
	cout <<"getRoadConditions"<<endl;
	for(int i=0;i<rmap.Intersections.size();i++) 
		intmap[rmap.Intersections[i].Name]=i;
	vector<bool> visited(rmap.Intersections.size(), false);
	cout << "RoadDFS start"<<endl;
	RoadDFS(intmap["I_START"], visited, 0);
	cout << "RoadDFS end"<<endl;
	for(int i=0;i<mpath.size();i++) 
		cout << mpath[i].Name<<endl;
	for(int i=0;i<mpath.size();i++) {
		cout << client.getTime()<<endl;
		while(!client.canMove());
		cout <<"canMove"<<endl;
		client.takeRoad(mpath[i], mpath[i].CurrentSpeed);
		cout << "takeRoad"<<endl;
	}
	cout << client.getTime()<<endl;


	string rs;
	client.winGame(rs);
	cout <<rs <<endl;
	

	transport->close();

	return 0;
}
