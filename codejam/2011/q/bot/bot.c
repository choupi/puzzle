#include <stdio.h>

int main()
{
    int T,t,N,n;
    int p[2];
    int wait, dist, time;
    int butt;
    int cur, last;
    char a;

    scanf("%d", &T);
    for(t=0;t<T;t++) {
        scanf("%d", &N);
        wait=0; time=0; last=-1;
        p[0]=1; p[1]=1;
        for(n=0;n<N;n++) {
            scanf(" %c %d", &a, &butt);
            if(a!='O') cur=1;
            else cur=0;
            dist=abs(butt-p[cur]);
            p[cur]=butt;
//printf("%c %d %d %d\n", a, cur, p[cur], dist);
            if(cur==last) {
                time+=dist+1;
                wait+=dist+1;
            } else {
                if(dist<=wait) dist=0;
                else dist-=wait;
                time+=dist+1;
                wait=dist+1;
                last=cur;
            }
//printf("%d %d %d %d\n", dist, last, time, wait);
        }
        printf("Case #%d: %d\n", t+1, time);
    }
    return 0;
}
