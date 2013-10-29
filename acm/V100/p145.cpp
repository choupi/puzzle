#include <stdio.h>

int main()
{
    char step;
    char s;
    int hs, he, ms, me;
    int day, even, night;
    double money;

    while(1)
    {
	step=getchar();
        if(step=='#') break;
	getchar();
	printf("  ");
	for(int i=0;i<9;i++) printf("%c", getchar());
	hs=(getchar()-'0')*10+(getchar()-'0');
	getchar();
	ms=(getchar()-'0')*10+(getchar()-'0');
	getchar();
        he=(getchar()-'0')*10+(getchar()-'0');
	getchar();
        me=(getchar()-'0')*10+(getchar()-'0');
	getchar();
        day=0;
        even=0;
        night=0;
	while(1)
	{
	    if(hs>=8 && hs<18)
	    {
		if((he>hs || (hs==he && me>=ms)) && he>=8 && he<18)
		{
		    day+=(he-hs)*60+(me-ms); 
		    break;
		}
		else 
		{
		    day+=(18-hs)*60-ms;
		    hs=18;
		    ms=00;
		}
	    } 
	    else if(hs>=18 && hs<22)
	    {
		if((he>hs || (hs==he && me>=ms)) && he>=18 && he<22)
                {
                    even+=(he-hs)*60+(me-ms);
                    break;
                }
                else
                {
                    even+=(22-hs)*60-ms;
                    hs=22;
                    ms=00;
                }
	    }
	    else if(hs>=22)
	    {
		if(he>=22 && (he>hs || (hs==he && me>=ms)))
                {
                    night+=(he-hs)*60+(me-ms);
                    break;
                }
                else
                {
                    night+=(24-hs)*60-ms;
                    hs=00;
                    ms=00;
                }
	    }
	    else if(hs<8)
	    {
		if(he<8 && (he>hs || (hs==he && me>=ms)))
                {
                    night+=(he-hs)*60+(me-ms);
                    break;
                }
                else
                {
                    night+=(8-hs)*60-ms;
                    hs=8;
                    ms=00;
                }
	    }
	}
	if(day==0 && even==0 && night==0)
	{
	    day=600;
	    even=240;
	    night=600;
	}
	printf("%5i%6i%6i%3c", day, even, night, step);
	switch(step)
	{
	    case 'A':
		printf("%8.2f\n", day*0.10+even*0.06+night*0.02);
		break;
            case 'B':
                printf("%8.2f\n", day*0.25+even*0.15+night*0.05);
                break;
            case 'C':
                printf("%8.2f\n", day*0.53+even*0.33+night*0.13);
                break;
            case 'D':
                printf("%8.2f\n", day*0.87+even*0.47+night*0.17);
                break;
            case 'E':
                printf("%8.2f\n", day*1.44+even*0.80+night*0.30);
                break;
	    default:
		break;
	}
    }
    return 0;
}
