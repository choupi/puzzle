#include <stdio.h>
#include <stack>

using namespace std;

int test(char* s, int len)
{
	stack<char> ss;
	for(int i=0;i<len;i++) {
		switch(s[i]) {
		case '(':
			ss.push(s[i]);
			break;
		case ')':
			if(!ss.empty()) ss.pop();
			else return 1;
			break;
		default:
			break;
		}
	}
	if(ss.empty()) return 0;
	else return 1;
}
	
int rec(char* s, int st, int et)
{
	int i=st;
	while(i<et && !(s[i-1]==':' && (s[i]=='(' || s[i]==')'))) i++;
	if(i==et) return test(s, et);
	char c=s[i];
	s[i]=' ';
	int r=rec(s, i+1, et);
	s[i]=c;
	if(r!=0) r=rec(s,i+1, et);
	return r;
}

int main()
{
	int T;
	size_t sl;
	char *s;
	scanf("%d", &T);
	getline(&s, &sl, stdin);
	for(int t=0;t<T;t++) {
		int rr=getline(&s, &sl, stdin);
		int r=rec(s, 1, rr-1);
		printf("Case #%d: %s\n", t+1, r!=0?"NO":"YES");
	}
}

