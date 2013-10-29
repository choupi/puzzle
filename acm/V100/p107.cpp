#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    unsigned long int height,work,h,w,temp,count,total,mall,sq,alltemp;
    
    while(1)
    {
	cin >> height >> work;
	if(height==0&&work==0) break;

	if(height>1&&height-work==1) cout << "1 " << height+work << endl;
	else if(height==1) cout << "0 " << work << endl;
	else if(height>2)
	{
	    sq=(unsigned long)sqrt(height);
	    for(unsigned long int i=1;i<sq;i++)
	    {
		count=0;
		h=1;
		while(h<height)
		{
		    h*=i+1;
		    count+=1; 
		}
		if(h==height)
		{
	//cout << count << " " << i << endl << flush;
		    w=1;
		    for(unsigned int j=0;j<count;j++)
		    {
			w*=i;
		    }
		    if(w==work)
		    {
			alltemp=1;
			mall=alltemp;
			temp=height;
			total=temp;
			for(unsigned long int k=0;k<count;k++)
			{
			    temp=(temp/(i+1))*i;
	//cout << mall << " ";
			    total+=temp;
			    alltemp *=i;
			    mall+=alltemp;
			}
			cout << mall-work <<" " << total << endl;
			break;
		     }
		}
	    }
	}
    }

    return 0;
}
