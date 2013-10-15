#include <stdio.h>

int checkBoard(char board[][5], char x)
{
	int i,j;
	int r=0;
	for(i=0;i<4;i++) {
		r=1;
		for(j=0;j<4;j++) {
			if(board[i][j]!=x && board[i][j]!='T') {
				r=0;
				break;
			}
		}
		if(r==1) return r;
	}
	for(i=0;i<4;i++) {
		r=1;
		for(j=0;j<4;j++) {
			if(board[j][i]!=x && board[j][i]!='T') {
				r=0;
				break;
			}
		}
		if(r==1) return r;
	}
	r=1;
	for(i=0;i<4;i++) 
		if(board[i][i]!=x && board[i][i]!='T') r=0;
	if(r==1) return r;
	r=1;
	for(i=0;i<4;i++) 
		if(board[i][3-i]!=x && board[i][3-i]!='T') r=0;
	return r;
}

int checkComplete(char board[][5], char x)
{
	int i, j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(board[i][j]==x) return 0;
	return 1;
}

int main()
{
	int T,t,i,j,k,l;
	char board[4][5];
	char tmp[5];
	
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		for(i=0;i<4;i++)
			scanf("%s", board[i]);
		//for(i=0;i<4;i++){ for(j=0;j<4;j++) printf("%c",board[i][j]); printf("\n"); } 
		printf("Case #%d: ", t+1);
		if(checkBoard(board, 'X')) 
			printf("X won");
		else if(checkBoard(board, 'O'))
			printf("O won");
		else if(checkComplete(board, '.'))
			printf("Draw");
		else printf("Game has not completed");
		printf("\n");
	}
	return 0;
}
