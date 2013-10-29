#include <iostream>
#include <cmath>

using namespace std;


int main(void)
{
    long double p, n, k;
    long int result;

    while(cin >> n >> p)
    {
	cout.unsetf(ios::showpoint); 
	cout.setf(ios::fixed);
	cout.precision(0);
	cout << pow(p, 1/n) << endl;
    }

    return 0;
}
