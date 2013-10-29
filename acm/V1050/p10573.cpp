#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PI (3.141592653589793238)

int main()
{
    char tmp[8];
    char *tmpPtr;
    int count, r1, r2;
    scanf("%i\n", &count);
    for(;count>0;count--)
    {
	gets(tmp);
	tmpPtr=strtok(tmp, " ");
	r1=atoi(tmpPtr);
	tmpPtr=strtok(NULL, "\0");
	if(tmpPtr != NULL)
	{
	    r2=atoi(tmpPtr);
	    printf("%.4f\n", 2.0*r1*r2*PI);
	}
	else
	{
	    printf("%.4f\n", r1*r1*PI/8.0);
	}
    }

    return 0;
}
