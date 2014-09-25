#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(x,y) (x>y?x:y)

long long *tn;
long long *fn;
int *cn;
int *vn;
int *pn;
int *bn;
int *on;

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void besttree(int n) 
{
    memset(tn,0,sizeof(tn));
    memset(fn,0,sizeof(fn));
    //for(int i=n-1;i>=0;i--) {
    int bnc=1, onc=0;
    bn[0]=0;
    while(bnc>0) {
        int i=bn[bnc-1];
        if(onc==cn[i*n+1] || (cn[i*n+1]==-1 && (cn[i*n]==-1 || onc==cn[i*n]) ) ) {
            tn[i]=vn[i];
            fn[i]=0;
            for(int j=0;j<2;j++) {
                if(cn[i*n+j]!=-1) {
                    tn[i]+=fn[cn[i*n+j]];
                    if(tn[cn[i*n+j]]>fn[cn[i*n+j]]) {
                        fn[i]+=tn[cn[i*n+j]];
                        pn[i*n+j]=1;
                    } else {
                        fn[i]+=fn[cn[i*n+j]];
                        pn[i*n+j]=-1;
                    }
                }
            }
            bnc--;
        } else if(onc==cn[i*n+0]) {
            bn[bnc++]=cn[i*n+1];
        } else {
            bn[bnc++]=cn[i*n];
        }
        onc=i;
    }
    printf("%lld\n", MAX(tn[0], fn[0]));
    bnc=0; onc=0;
    if(tn[0]>fn[0]) { 
        for(int j=0;j<2;j++) if(cn[j]!=-1) bn[bnc++]=-1*cn[j];
        on[onc++]=0;
    } else {
        for(int j=0;j<2;j++) 
            if(cn[j]!=-1) bn[bnc++]=pn[j]*cn[j];
    }
    while(bnc>0) {
        int r=bn[--bnc];
        if(r>0) {
            for(int j=0;j<2;j++) if(cn[r*n+j]!=-1) bn[bnc++]=-1*cn[r*n+j];
            on[onc++]=r;
        } else {
            r=r*-1;
            for(int j=0;j<2;j++) if(cn[r*n+j]!=-1) bn[bnc++]=pn[r*n+j]*cn[r*n+j];
        }
    }
    qsort(on,onc,sizeof(int),compare);
    for(int i=0;i<onc;i++) printf("%d ", on[i]); printf("\n");
}

int main()
{
    int n,t;
    scanf("%d", &n);

    tn=(long long*)malloc(n*sizeof(long long));
    fn=(long long*)malloc(n*sizeof(long long));
    vn=(int*)malloc(n*sizeof(int));
    bn=(int*)malloc(n*sizeof(int));
    on=(int*)malloc(n*sizeof(int));
    cn=(int*)malloc(2*n*sizeof(int));
    pn=(int*)malloc(2*n*sizeof(int));

    scanf("%d", vn);
    for(int i=0;i<n;i++) {cn[i*n]=cn[i*n+1]=-1;}
    for(int i=1;i<n;i++) {
        scanf("%d %d", &t, vn+i);
        if(cn[t*n]==-1) cn[t*n]=i;
        else cn[t*n+1]=i;
    }
    besttree(n);
}
