#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	ifstream fin(argv[1]);
	fin >> n;
	for(int i=1;i<n+1;i++) {
		if(i%15==0) cout << "Hop" << endl;
		else if(i%3==0) cout << "Hoppity" << endl;
		else if(i%5==0) cout << "Hophop" << endl;
	}
}
