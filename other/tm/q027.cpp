#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(x,y) (x>y?x:y)

const int MN=1000;
int tn[MN];
int fn[MN];
int cn[MN][2];
int vn[MN];
int pn[MN][2];
int bn[MN];
int on[MN];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void besttree(int n) 
{
    memset(tn,0,sizeof(tn));
    memset(fn,0,sizeof(fn));
    for(int i=n-1;i>=0;i--) {
        tn[i]=vn[i];
        fn[i]=0;
        for(int j=0;j<2;j++) {
            if(cn[i][j]!=-1) {
                tn[i]+=fn[cn[i][j]];
                if(tn[cn[i][j]]>fn[cn[i][j]]) {
                    fn[i]+=tn[cn[i][j]];
                    pn[i][j]=1;
                } else {
                    fn[i]+=fn[cn[i][j]];
                    pn[i][j]=-1;
                }
            }
        }
    }
    printf("%d\n", MAX(tn[0], fn[0]));
    int bnc=0,onc=0;
    if(tn[0]>fn[0]) { 
        for(int j=0;j<2;j++) if(cn[0][j]!=-1) bn[bnc++]=-1*cn[0][j];
        on[onc++]=0;
    } else {
        for(int j=0;j<2;j++) 
            if(cn[0][j]!=-1) bn[bnc++]=pn[0][j]*cn[0][j];
    }
    while(bnc>0) {
        int r=bn[--bnc];
        if(r>0) {
            for(int j=0;j<2;j++) if(cn[r][j]!=-1) bn[bnc++]=-1*cn[r][j];
            on[onc++]=r;
        } else {
            r=r*-1;
            for(int j=0;j<2;j++) if(cn[r][j]!=-1) bn[bnc++]=pn[r][j]*cn[r][j];
        }
    }
    qsort(on,onc,sizeof(int),compare);
    for(int i=0;i<onc;i++) printf("%d ", on[i]); printf("\n");
}
int main()
{
    int n,t;
    scanf("%d %d", &n, vn);
    for(int i=0;i<n;i++) {cn[i][0]=cn[i][1]=-1;}
    for(int i=1;i<n;i++) {
        scanf("%d %d", &t, vn+i);
        if(cn[t][0]==-1) cn[t][0]=i;
        else cn[t][1]=i;
    }
    besttree(n);
}
