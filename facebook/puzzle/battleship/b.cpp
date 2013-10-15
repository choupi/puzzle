#include "Battleship2.h" 

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace std;

int main(int argc, char **argv) {
	int port=9031;
	boost::shared_ptr<TSocket> socket(new TSocket("thriftpuzzle.facebook.com", port));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	Battleship2Client client(protocol);
	transport->open();

//	string email("chromosome460@gmail.com");
	srand(time(NULL));
	string email(argv[1]);
	cout << email<<endl;
	if(argc<3) {
		int gID=client.registerClient(email);
		cout << "registerClient at "<<gID<<endl;
	} else {
		int gID=atoi(argv[2]);
		client.join(gID, email);
		cout <<"join "<<gID<<endl;
	}
	for(int i=1;i<6;i++) {
		Coordinate c;
		bool fl;
		do {
			c.row=rand()%10;
			c.column=rand()%10;
			fl=rand()%2;
		} while(!client.placePiece(i, c, fl)); 
		cout << "placePiece"<<i<<" at "<<c.row<<" "<<c.column<<endl;
	}
	vector<vector<bool> > taken(10, vector<bool>(10, false));
	queue<Coordinate> qq;
	while(1) {
	try {
		client.isMyTurn();
	//	cout << "isMyTurn"<<endl;
		Coordinate c;
		do {
			if(qq.empty()) {
				c.row=rand()%10;
				c.column=rand()%10;
			} else {
				c=qq.front();
				qq.pop();
	//			cout << "pop "<<c.row<<" "<<c.column<<endl;
			} 
		} while(taken[c.row][c.column]);
		taken[c.row][c.column]=true;
		AttackResult ar=client.attack(c);
		cout << "att: "<<c.row<<" "<<c.column<<" re:"<<ar<<endl;
		if(ar==HIT) {
			Coordinate d;
			if(c.row-1>=0) { d.column=c.column; d.row=c.row-1; qq.push(d); }
			if(c.row+1<10) { d.column=c.column; d.row=c.row+1; qq.push(d); }
			if(c.column-1>=0) { d.row=c.row; d.column=c.column-1; qq.push(d); }
			if(c.column+1<10) { d.row=c.row; d.column=c.column+1; qq.push(d); }
		}
//		client.getOpponentsLastAttack(c);
//		cout <<c.row<<" "<<c.column<<endl; 
	} catch (GameOverException goe) {
		break;
	}
	}

	string rs;
	client.winGame(rs);
	cout <<rs <<endl;

	transport->close();

	return 0;
}
