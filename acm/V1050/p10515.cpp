#include <iostream>
using namespace std;

int main(void)
{
    char *tmp= new char[102];
    int m, n,sl, m0=0;
    int table[10][4]= {	{0,0,0,0},
			{1,1,1,1},
			{2,4,8,6},
			{3,9,7,1},
			{4,6,4,6},
			{5,5,5,5},
			{6,6,6,6},
			{7,9,3,1},
			{8,4,2,6},
			{9,1,9,1}};

    while(1)
    {
	m0=0;
	cin.getline(tmp, 101, ' ');
	sl=strlen(tmp);
	m=tmp[sl-1]-'0';
	if(sl==1 && m==0) m0=1;
	cin.getline(tmp, 101, '\n');
	sl=strlen(tmp);
	if(sl>1)
	    n=(tmp[sl-2]-'0')*10+(tmp[sl-1]-'0');
	else n=(tmp[sl-1]-'0');
	if(sl==1 && n==0) 
	{
	    if(m0==1) return 0;
	    else cout << "1" << endl;
	}
	else
	{
	    if(n==0 && sl>2) n=100;
	    n= (n-1)%4;
	    //cout << n <<"\t";
	    switch(m)
	    {
	      case 1:
	      case 5:
	      case 6:
	      case 0:
	        cout << m << endl;
	        break;
	      case 2:
	      case 3:
	      case 4:
	      case 7:
	      case 8:
	      case 9:
	        cout << table[m][n] << endl;
	        break;
	      default:
	        break;    
	    }
	}
    }

    return 0;
}
