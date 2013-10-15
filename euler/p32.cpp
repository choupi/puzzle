#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<int,int> table;
    char number[10]={'1','2','3','4','5','6','7','8','9','\0'};
    char tmp;
    long long prod, m1, m2, sum=0;
    int bb;
    do {
	for(int i=5;i<6;i++) {
	    bb=0;
	    prod=atoi(number+i);
	    for(int j=3;j<i;j++) {
		tmp=number[j];
		number[j]='\0';
		m1=atoi(number);
		number[j]=tmp;
		tmp=number[i];
		number[i]='\0';
		m2=atoi(number+j);
		number[i]=tmp;
		if(m1*m2==prod) { bb=1; break; }
	    }
	    if(bb && !(table[prod])) {
		printf("%d=%dx%d\n", prod, m1, m2);
		sum+=prod; table[prod]=1;}
	}
    } while(next_permutation(number, number+9));
    printf("%lld\n", sum);
}
