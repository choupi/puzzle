#include <stdio.h>
#include <string.h>

#define MAXVARN (100)
#define MAXVARL (20)
#define MAXCODEN (100)
#define MAXCODEL (256)

char varname[MAXVARN][MAXVARL];
int varvalue[MAXVARN];
char codes[MAXCODEN][MAXCODEL];
char buf[MAXCODEL];

int findVar(char* v)
{
	int i;
	for(i=0;i<MAXVARN;i++)
		if(strcmp(v, varname[i])==0) return i;
}

int getVar(char* v)
{
	return varvalue[findVar(v)];
}

void setVar(char* v, int val)
{
	varvalue[findVar(v)]=val;
}

int initVar(char* v)
{
	int st=0;
	char* END="END";
	char* vp=strtok(v," =");
	char* vv;
	while(vp) {
		if(st) vp=strtok(NULL," =");
		if(strcmp(vp, END)==0) break;
		vv=strtok(NULL, " =");
		strcpy(varname[st], vp);
		varvalue[st]=atoi(vv);
		st+=1;
	}
	return st;
}

int execCond(int b, int c, char* op)
{
	if(strcmp(op, "==")==0) return b==c;
	else if(strcmp(op, "!=")==0) return b!=c;
	else if(strcmp(op, ">")==0) return b>c;
	else if(strcmp(op, "<")==0) return b<c;
	else if(strcmp(op, ">=")==0) return b>=c;
	else if(strcmp(op, "<=")==0) return b<=c;
	return 0;
}

int execOp(int b, int c, char* op)
{
	if(strcmp(op, "+")==0) return b+c;
	else if(strcmp(op, "-")==0) return b-c;
	else if(strcmp(op, "*")==0) return b*c;
	else if(strcmp(op, "/")==0) return b/c;
	else if(strcmp(op, "%")==0) return b%c;
	return 0;
}

int execCode(int line)
{
	char* vp;
	char* avar;
	char* bvar;
	char* cvar;
	char* op;
	strcpy(buf, codes[line]);
	vp=strtok(buf, " ");
	if(strcmp(vp, "IF")==0) {
		bvar=strtok(NULL, " ");
		op=strtok(NULL, " ");
		cvar=strtok(NULL, " ");
		//printf("%s %s %s: %d\n", bvar, op, cvar, execCond(getVar(bvar), getVar(cvar), op));
		if(execCond(getVar(bvar), getVar(cvar), op)==0) return 0;
		vp=strtok(NULL, " ");
		vp=strtok(NULL, " ");
		return atoi(vp);
	} else if(strcmp(vp, "GOTO")==0) {
		vp=strtok(NULL, " ");
		return atoi(vp);
	} else if(strcmp(vp, "PRINT")==0) {
		vp=strtok(NULL, " ");
		//printf("%s=%d\n", vp, getVar(vp));
		printf("%d ", getVar(vp));
		return 0;
	} else if(strcmp(vp, "STOP")==0) {
		return -1;
	} else {
		avar=vp;
		strtok(NULL, " ");
		bvar=strtok(NULL, " ");
		op=strtok(NULL, " ");
		cvar=strtok(NULL, " ");
		setVar(avar, execOp(getVar(bvar), getVar(cvar), op));
		return 0;
	}
	return -1;
}

int main()
{
	int i, cl=0, vl=0, execline, ret;
	while(gets(codes[cl])) cl++;
	//printf("%s\n", codes[1]);
	strcpy(buf, codes[0]);
	vl=initVar(buf);
	//printf("%s\n", codes[0]);
	//for(i=0;i<vl;i++) printf("%s %d %d\n", varname[i], varvalue[i], findVar(varname[i]));
	execline=1;
	while(1) {
		ret=execCode(execline);
		if(ret==0) execline+=1;
		else if(ret<0) break;
		else execline=ret;
		//printf("line: %d\n", execline);
	}
}
