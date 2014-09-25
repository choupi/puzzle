#include <stdio.h>

const int MN=10, M=5;
char box[MN*MN];
char direct[MN*MN][2];
int pos[MN*MN][4];
int n,mx,my;
bool ppx[MN];
bool ppy[MN];
int tpx[MN];
int tpy[MN];

int checkMirror()
{
    for(int i=0;i<n;i++) {
        char d=direct[i][0];
        int px=pos[i][0], py=pos[i][1];
        bool run=true;
        while(run) {
            //printf("%d %d %c %c\n", px, py, d, box[px*MN+py]);
            if(box[px*MN+py]=='/') {
                switch(d) {
                    case 'n': d='e'; break;
                    case 's': d='w'; break;
                    case 'e': d='n'; break;
                    case 'w': d='s'; break;
                }
            } else if(box[px*MN+py]=='\\') {
                switch(d) {
                    case 'n': d='w'; break;
                    case 's': d='e'; break;
                    case 'e': d='s'; break;
                    case 'w': d='n'; break;
                }
            }
            switch(d) {
                case 'n': px-=1; break;
                case 's': px+=1; break;
                case 'e': py+=1; break;
                case 'w': py-=1; break;
            }
            if(px==MN) { px-=1; run=false; }
            else if(px==-1) { px+=1; run=false; }
            else if(py==MN) { py-=1; run=false; }
            else if(py==-1) { py+=1; run=false; }
        }
        if(px!=pos[i][2] || py!=pos[i][3] || d!=direct[i][1]) 
            return 0;
    }
    return 1;
}

int findMirror(int si, int sj, int mn)
{
    if(mn==M) return checkMirror();
    //if(mn==M) {
        //for(int ii=0;ii<MN*MN;ii++) printf("%c ",box[ii]);
        //return 0; }
    //for(int ii=st;ii<MN*MN;ii++) {
    for(int i=si; i<mx;i++) {
      for(int j=sj;j<my;j++) {
        if(findMirror(i, j+1, mn)) return 1;
        int ii=tpx[i]*MN+tpy[j];
        box[ii]='/';
        if(findMirror(i, j+1, mn+1)) return 1;
        box[ii]='\\';
        if(findMirror(i, j+1, mn+1)) return 1;
        box[ii]='-';
      }
      sj=0;
    }
    return 0;
}

int main()
{
    n=0;
    while(scanf("%d %d %c %d %d %c", &pos[n][0], &pos[n][1], &direct[n][0], 
            &pos[n][2], &pos[n][3], &direct[n][1])!=EOF) n++;
    //for(int i=0;i<n;i++) printf("%d %d %c %d %d %c\n", pos[i][0],pos[i][1],direct[i][0],pos[i][2],pos[i][3],direct[i][1]);
    for(int i=0;i<MN*MN;i++) box[i]='-';
    for(int i=0;i<MN;i++) { ppx[i]=false; ppy[i]=false; }
    for(int i=0;i<n;i++) {
        if(direct[i][0]=='e' || direct[i][0]=='w') ppx[pos[i][0]]=true; 
        if(direct[i][1]=='e' || direct[i][1]=='w') ppx[pos[i][2]]=true;
        if(direct[i][0]=='n' || direct[i][0]=='s') ppy[pos[i][1]]=true; 
        if(direct[i][1]=='n' || direct[i][1]=='s') ppy[pos[i][3]]=true;
    }
    mx=0;my=0;
    for(int i=0;i<MN;i++) {
        if(ppx[i]) tpx[mx++]=i;
        if(ppy[i]) tpy[my++]=i;
    }
    if(findMirror(0,0,0)) {
        for(int ii=0;ii<MN*MN;ii++) 
            if(box[ii]!='-') printf("%d %d %c\n",ii/MN, ii%MN, box[ii]);
    }

    //box[4*MN+3]='/';
    /*box[2*MN+6]='/';
    box[3*MN+1]='/';
    box[6*MN+6]='/';
    box[9*MN+7]='\\';
    box[9*MN+9]='/';
    if(checkMirror()) printf("@@\n");
    */
}
