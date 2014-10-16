#include <stdio.h>

int prizes[7]={2000000, 200000, 40000, 10000, 4000, 1000, 200};
int mask[7]={-1, -1, 10000000, 1000000, 100000, 10000, 1000};

int prize(int specialPrizeNumbers[3], int firstPrizeNumbers[3], int myNumber)
{
	int i, j;
	for(i=0;i<3;i++) 
		if(specialPrizeNumbers[i]==myNumber) return prizes[0];
	for(i=0;i<3;i++)
		if(firstPrizeNumbers[i]==myNumber) return prizes[1];
	for(j=2;j<7;j++) {
		for(i=0;i<3;i++)
			if(firstPrizeNumbers[i]%mask[j]==myNumber%mask[j]) 
				return prizes[j];
	}
	return 0;
}

int main()
{
  int i;
  int specialPrizeNumbers[3];
  int firstPrizeNumbers[3];
  int myNumber;
  int totalPrize = 0;

  for (i = 0; i < 3; i++)
    scanf("%d", &(specialPrizeNumbers[i]));
  for (i = 0; i < 3; i++)
    scanf("%d", &(firstPrizeNumbers[i]));

  while (scanf("%d", &myNumber) != EOF)
    totalPrize += prize(specialPrizeNumbers, firstPrizeNumbers, myNumber);

  printf("%d\n", totalPrize);
  return 0;
}
