#include <math.h>
#include <stdio.h>

#define MAXRT (10000.0)
#define equal(x,y) (fabs((x)-(y))<1e-8)

double mx,my;
int H,W;
char hmap[35][35];

double ref_x(double k)
{
	return tan(-1*atan(k));
}
double ref_y(double k)
{
	return tan(M_PI-atan(k));
}

void intersect(double x0, double y0, double k0, double x1, double y1, double k1, double *x, double *y)
{
	if(k0!=k1) *x=(k0*x0+k1*x1+y0-y1)/(k0-k1);
	*y=k0*(*x-x0)+y0;
}

double intersect_x(double x0, double y0, double k0, double x)
{
	return k0*(x-x0)+y0;
}
double intersect_y(double x0, double y0, double k0, double y)
{
	return (y-y0+k0*x0)/k0;
}

double distance(double x0, double y0, double x1, double y1)
{
	double x=x1-x0, y=y1-y0;
	return sqrt(x*x+y*y);
}

int ray_trace_x(int h,int w,double x0, double y0, int p, double D)
{
	int i;
	double d;
	for(i=h+p;i<H && i>=0 && hmap[i][w]!='#';i+=p);
	if(p>0) d=(double)i-x0;
	else d=x0-(double)i-1.0;
//printf("%d %d %.4lf %.4lf %.4lf\n", i,w,x0,y0,d);
	if(2*d<D || equal(2*d,D)) return 1;
	else return 0;
}
int ray_trace_y(int h,int w,double x0, double y0, int p, double D)
{
	int i;
	double d;
	for(i=w+p;i<W && i>=0 && hmap[h][i]!='#';i+=p);
	if(p>0) d=(double)i-y0;
	else d=y0-(double)i-1.0;
//printf("%d %d %.4lf %.4lf %.4lf\n", h,i,x0,y0,d);
	if(2*d<D || equal(2*d,D)) return 1;
	else return 0;
}

int ray_trace(int h,int w,double x0, double y0, double k0, int p, double D)
{
	int px,py,pp=(p*k0>0?1:-1);
	double nx0,ny0,nx1,ny1,nx,ny,d0,d1;
	printf("%d %d %.4lf %.4lf %.6lf %d %.4lf\n", h,w,x0,y0,k0,p,D);
	if(D<=0) return 0;
	if(hmap[h][w]=='X' && x0!=mx && y0!=my && equal(my,k0*(mx-x0)+y0)) {
		d0=distance(x0,y0,mx,my);
	printf("@@@%.4lf %.4lf\n",D,d0);
		if(d0<D || equal(d0,D)) return 1;
		else return 0;
	}
//	printf(">%c %.4lf s:%.7lf\n",hmap[h][w],d0,fabs(my-k0*(mx-x0)-y0));

	if(p>0) nx0=floor(x0+1);
	else nx0=ceil(x0-1);
	if(pp>0) ny1=floor(y0+1);
	else ny1=ceil(y0-1);
	ny0=intersect_x(x0,y0,k0,nx0); nx1=intersect_y(x0,y0,k0,ny1);
	d0=distance(x0,y0,nx0,ny0); d1=distance(x0,y0,nx1,ny1);
//	printf("n0: %.4lf %.4lf %.4lf ", nx0, ny0, d0);
//	printf("n1: %.4lf %.4lf %.4lf\n", nx1, ny1,d1);
	if(equal(d0,d1)) {
		if(hmap[h+p][w+pp]=='#') {
			if(hmap[h+p][w]=='#' && hmap[h][w+pp]=='#')
				return ray_trace(h,w,nx0,ny0,k0,-1*p,D-d0);
			else if(hmap[h+p][w]=='#') 
				return ray_trace(h+p,w,nx0,ny0,ref_x(k0),p,D-d0);
			else if(hmap[h][w+pp]=='#')
				return ray_trace(h,w+pp,nx0,ny0,ref_y(k0),-1*p,D-d0);
			else return 0;
		} else return ray_trace(h+p,w+pp,nx0,ny0,k0,p,D-d0);
	}	
	if(d0<d1) {
		if(hmap[h+p][w]=='#') 
			return ray_trace(h,w,nx0,ny0,ref_x(k0),p,D-d0);
		else return ray_trace(h+p,w,nx0,ny0,k0,p,D-d0);
	} else {
		if(hmap[h][w+pp]=='#') 
			return ray_trace(h,w,nx1,ny1,ref_y(k0),-1*p,D-d1);
		else return ray_trace(h,w+pp,nx1,ny1,k0,p,D-d1);
	}
}


int main()
{
	int t,T,D,i,j,c;
	double k,d,di,dj;
	scanf("%d",&T);
	for(t=0;t<T;t++) {
		c=0;
		scanf("%d %d %d\n", &H,&W,&D);
		for(i=0;i<H;i++) {
			scanf("%s", hmap[i]);
			for(j=0;j<W;j++) if(hmap[i][j]=='X') { my=j+0.5; mx=i+0.5; }
		}
		for(i=0;i<H;i++) { for(j=0;j<W;j++) printf("%c", hmap[i][j]); printf("\n"); }
		printf("%lf %lf\n",mx,my); fflush(stdout);
		for(di=mx-D;di<mx;di+=1.0) {
			for(dj=my-D;dj<my;dj+=1.0) {
				k=(dj-my)/(di-mx);
				printf("%.2lf %.2lf start k=%.4lf\n",di,dj,k);
				if(k>-1e6 && k<1e6 && !equal(k,0)) { 
					c+=ray_trace((int)mx,(int)my,mx,my,k,1,D);
					c+=ray_trace((int)mx,(int)my,mx,my,k,-1,D);
				}
				k=-1*k;
				if(k>-1e6 && k<1e6 && !equal(k,0)) { 
					c+=ray_trace((int)mx,(int)my,mx,my,k,1,D);
					c+=ray_trace((int)mx,(int)my,mx,my,k,-1,D);
				}
			}
		}
		printf("%d\n",c);
		c+=ray_trace_x((int)mx,(int)my,mx,my,1,D);
		c+=ray_trace_x((int)mx,(int)my,mx,my,-1,D);
		c+=ray_trace_y((int)mx,(int)my,mx,my,1,D);
		c+=ray_trace_y((int)mx,(int)my,mx,my,-1,D);
		printf("Case #%d: %d\n",t+1,c);
	}
}
