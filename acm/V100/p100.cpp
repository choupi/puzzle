#include <iostream>

using namespace std;

int main(void)
{
    unsigned long maxt, a, b, times, now, tempa, tempb, temp;

    while(cin >> a >> b)
    {
	tempa=a;
	tempb=b;
	maxt=0;
	if(a>b) 
	{
	    temp=a;
	    a=b;
	    b=temp;
	}
	for(unsigned long i=a; i<b+1;i++)
	{
	    now=i;
	    times=1;
	    while(now!=1)
	    {
		if(now%2==0)
		{
		    now=now/2;
		}
		else
		{
		    now=now*3+1;
		}
		times+=1;
	    }
	    if(times>maxt) maxt=times;
	}
	cout << tempa <<" " <<tempb <<" " << maxt << endl;
    }

    return 0;
}
