#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	char board[50][50];
	int T, K, N;

	cin >> T;

	for(int tt=0;tt<T;tt++) {
		cin >> N >>K;
		char tc;
		vector<list<char> > lb(N);
		for(int i=N-1;i>=0;i--) {
			for(int j=0;j<N;j++) {
				cin >> tc;
				if(tc=='.') continue;
				lb[i].push_back(tc);
			}
		}

		for(int i=0;i<N;i++) {
			int j=0;
			while(!lb[i].empty()) {
				board[i][j]=lb[i].back();
				lb[i].pop_back();
				j++;
			}
			for(;j<N;j++) board[i][j]='.';
		}
		bool m[2]={0,0};
		char last;
		int tm=0;
		for(int i=0;i<N;i++) {
			last=board[i][0];
			tm=0;
			for(int j=1;j<N;j++) {
			//cout << tm << " ";
				if(board[i][j]==last) tm++;
				else {
					tm=0;
					last=board[i][j];
				}
				if(last!='.' && tm==K-1) m[(last=='R')?0:1]=true;
			}
		}
		//cout <<endl;
		for(int i=0;i<N;i++) {
			//cout << tm << " ";
			last=board[0][i];
			tm=0;
			for(int j=1;j<N;j++) {
				if(board[j][i]==last) tm++;
				else {
					tm=0;
					last=board[j][i];
				}
				if(last!='.' && tm==K-1) m[(last=='R')?0:1]=true;
			}
		}
		//cout <<endl;
		for(int i=0;i<N;i++) {
			last=board[0][i];
			tm=0;
			for(int j=1;j+i<N;j++) {
			//cout << tm << " ";
				if(board[j][j+i]==last) tm++;
				else {
					tm=0;
					last=board[j][j+i];
				}
				if(last!='.' && tm==K-1) m[(last=='R')?0:1]=true;
			}
		}
		//cout <<endl;
		for(int i=0;i<N;i++) {
			last=board[i][0];
			tm=0;
			for(int j=1;j+i<N;j++) {
			//cout << tm << " ";
				if(board[j+i][j]==last) tm++;
				else {
					tm=0;
					last=board[j+i][j];
				}
				if(last!='.' && tm==K-1) m[(last=='R')?0:1]=true;
			}
		}
		//cout <<endl;
		for(int i=0;i<N;i++) {
			last=board[0][i];
			tm=0;
			for(int j=1;i-j>=0;j++) {
			//cout << tm << " ";
				if(board[j][i-j]==last) tm++;
				else {
					tm=0;
					last=board[j][i-j];
				}
				if(last!='.' && tm==K-1) m[(last=='R')?0:1]=true;
			}
		}
		cout <<endl;
		for(int i=0;i<N;i++) {
			last=board[i][N-1];
			tm=0;
			for(int j=1;i-j>=0;j++) {
			cout << tm << " ";
				if(board[i+j][N-j-1]==last) tm++;
				else {
					tm=0;
					last=board[i-j][j];
				}
				if(last!='.' && tm==K-1) m[(last=='R')?0:1]=true;
			}
		}
		cout <<endl;
		/*
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(board[i][j]=='R') cout << board[i][j];
				else cout << '.';
			}
			cout << endl;
		}
			cout << endl;
			*/
		cout << "Case #" <<tt+1<<": ";
		if(m[0] && m[1]) cout <<"Both";
		else if(m[0]) cout <<"Red";
		else if(m[1]) cout <<"Blue";
		else cout << "Neither";
		cout <<endl;
	}
}
