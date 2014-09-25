#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 1000, MW = 100000, FSCALE=1000;
int cost[N], weight[N], id[N];
int c[MW + 1];
bool p[N][MW + 1]; 
int ca[N];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void knapsack(int n, int w)
{
    memset(c, 0, sizeof(c));
    memset(p, false, sizeof(p)); 
 
    for (int i = 0; i < n; ++i)
        for (int j = w; j >= weight[i]; --j)
            if (c[j - weight[i]] + cost[i] > c[j])
            {
                c[j] = c[j - weight[i]] + cost[i];
                p[i][j] = true; 
            }
 
    printf("%d\n",c[w]);
 
    int cn=0;
    for (int i = n-1, j = w; i >= 0; --i)
        if (p[i][j])
        {
            //printf("%d ", i);
            ca[cn++]=id[i];
            j -= weight[i];
        }
    qsort(ca,cn,sizeof(int),compare);
    for(int i=0;i<cn;i++) printf("%d ", ca[i]);printf("\n");
}

int main()
{
    int w, n;
    float iw;
    scanf("%f %d", &iw, &n);
    w=(int)(iw*FSCALE);
    for(int i=0;i<n;i++) {
        scanf("%d %f %d", id+i, &iw, cost+i);
        weight[i]=(int)(iw*FSCALE);
    }
    knapsack(n,w);
}


