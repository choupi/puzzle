#include <math.h>
#include <stdio.h>

int main(void)
{
    double x, y, r;
    double x1, y1, x2, y2, x3, y3;

    while(scanf("%lf %lf %lf %lf %lf %lf\n",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
	x=y1*(x3*x3-x2*x2)+y2*(x1*x1-x3*x3)+y3*(x2*x2-x1*x1);
	x+=y1*y2*(y1-y2)+y1*y3*(y3-y1)+y3*y2*(y2-y3);
	x/=2*(y1*(x3-x2)+y2*(x1-x3)+y3*(x2-x1));
	y=x1*(y3*y3-y2*y2)+x2*(y1*y1-y3*y3)+x3*(y2*y2-y1*y1);
	y+=x1*x2*(x1-x2)+x1*x3*(x3-x1)+x3*x2*(x2-x3);
	y/=2*(x1*(y3-y2)+x2*(y1-y3)+x3*(y2-y1));
	r=pow(((x-x1)*(x-x1)+(y-y1)*(y-y1)), 0.5);
	printf("(x %c %.3f)^2 + ",(x<0?'+':'-'),(x<0?-1.0*x:x));
	printf("(y %c %.3f)^2 = %.3f^2\n",(y<0?'+':'-'),(y<0?-1.0*y:y),r);

	printf("x^2 + y^2 %c %.3fx ",(x<0?'+':'-'),2.0*(x<0?-1.0*x:x));
	printf("%c %.3fy ",(y<0?'+':'-'),2.0*(y<0?-1.0*y:y));
	r=r*r-x*x-y*y;
	printf("%c %.3f = 0\n\n",(r<0?'+':'-'),(r<0?-1.0*r:r));
    }

    return 0;
}
