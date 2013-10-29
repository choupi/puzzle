#include <iostream>
using namespace std;

int main(void)
{
    int start, ps1, ps2, ps3, degree;

    while(1)
    {
	cin >> start >> ps1 >> ps2 >> ps3;
	if(ps3==0 && ps2==0 && ps1==0 && start==0) break;
	
	degree = 120;
	degree += ((start-ps1>0) ? (start-ps1): (start-ps1+40));
//cout << degree;
	degree += ((ps2-ps1>0)   ? (ps2-ps1)  : (ps2-ps1+40));
//cout << degree;
	degree += ((ps2-ps3>0)   ? (ps2-ps3)  : (ps2-ps3+40));
	degree *=9;
	cout << degree << endl;
    }

    return 0;
}
