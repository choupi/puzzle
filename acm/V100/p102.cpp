#include <iostream>
using namespace std;

int main(void)
{
    char bin[3]={'B', 'C', 'G'};
    char bint[3];
    long long int b[3], g[3], c[3];
    long long int min=0, mint=0, all, temp;

    while(cin >>b[0]>>g[0]>>c[0]>>b[1]>>g[1]>>c[1]>>b[2]>>g[2]>>c[2])
    {
	mint=0;
	all = b[0]+g[0]+c[0]+b[1]+g[1]+c[1]+b[2]+g[2]+c[2];
	//cout << all << endl;
	for(int h=0;h<3;h++) bint[h]=bin[h];
	for(int m=0;m<3;m++)
	{
	    temp=bin[0];
	    bin[0]=bin[m];
	    if(m==2)
	    {
		bin[m]=bin[1];
		bin[1]=temp;
	    }
	    else bin[m]=temp;
	    for(int n=1;n<3;n++)
	    {
		temp=bin[1];
		bin[1]=bin[n];
		bin[n]=temp;
		min=0;
		for(int i=0;i<3;i++)
		{
		    switch (bin[i])
		    {
		    case 'B':
			min+=b[i];
			break;
		    case 'G':
			min+=g[i];
			break;
		    case 'C':
			min+=c[i];
			break;
		    defualt:
			break;
		    }
		}
		//cout << bin[0] << bin[1] << bin[2] <<" " <<min <<endl;
		if(min>mint) 
		{
		    mint=min;
		    for(int k=0;k<3;k++)
			bint[k]=bin[k];
		}
		temp=bin[1];
                bin[1]=bin[n];
                bin[n]=temp;
	    }
	    temp=bin[0];
	    if(m==2)
	    {
		bin[0]=bin[1];
		bin[1]=bin[2];
		bin[2]=temp;
	    } else {
        	bin[0]=bin[m];
       		bin[m]=temp;
	    }
	}
	cout << bint[0] << bint[1] << bint[2] << " " << all-mint << endl;
    }

    return 0;
}


