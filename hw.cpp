#include <iostream>
#define TRUE 1==1
#define FALSE 1==2
typedef int boolean;
int sumMoney(int SZ, int* coins, int* cur)
{
	int sum = 0;
	for(int i=0; i<SZ; i++)
		sum+=(coins[i]*cur[i]);
	return sum;
}
int sumCoins(int SZ, int* cur)
{
	int sum = 0;
	for(int i=0; i<SZ; i++)
		sum+=cur[i];
	return sum;
}
void printCoins(int SZ, int* coins, int* cur)
{
	for(int i=0; i<SZ; i++)
		printf("%dX[%d] ", cur[i], coins[i]);
	printf("\n");
}
void copyArray(int SZ, int* out, int* in)
{
	for(int i=0; i<SZ; i++)
		in[i] = out[i];
}
boolean nextValue(int SUM, int SZ, int* coins, int* cur)
{
	int i;
	cur[0]++;
	for(i=0; i<SZ-1; i++)
	{
		if(sumMoney(SZ, coins, cur) > SUM)
		{
			for(int j=0; j<=i; j++)
				cur[j]=0;
			cur[i+1]++;
		}			
	}
	return ((cur[i]*coins[i]) <= SUM);
}
int * minimumCoins(int SUM, int SZ, int* coins)
{	
	if(SZ == 0) return NULL;
	int tmp;
	int * rez = (int *)calloc(SZ, sizeof(int));
	int * cur = (int *)calloc(SZ, sizeof(int));
	if(cur == NULL || rez == NULL)
	{
		printf("Out of Memory\n");
		free(rez);
		free(cur);		
		return NULL;		
	}
	rez[0] = -1;
	int minCount = SUM/coins[0]+10;								//nachal'nyj minimum
	do
	{
		if(sumMoney(SZ, coins, cur) == SUM)
		{
			//printCoins(SZ, coins, cur);							//dlya testirovaniya
			tmp = sumCoins(SZ, cur);
			if(tmp < minCount)
			{
				copyArray(SZ, cur, rez);
				minCount = tmp;
			}
		}
	} while(nextValue(SUM, SZ, coins, cur));
	free(cur);
	if(rez[0] == -1)
	{
		free(rez);
		return NULL;
	}
	return rez;
}
boolean getHash(char * ar, char * h)
{
	unsigned int sum = 0;
	int i=0;
	while(ar[i] != '\0')
	{
		sum+=ar[i];
		if(sum > 0xFFFFFF00) return FALSE;
		i++;
	}
	sprintf(h, "%08X", sum); 
	return TRUE;
}
int main()
{
//Exercise #1
	char array[256] = "Hello World";
	char hash[sizeof(unsigned int)+1];
	if(getHash(array, hash))
		printf("HashCode: %s\n", hash);
	else
		printf("Out of Memory\n");
//Exercise #2
	int SUM = 98;
	int coins[] = {1, 2, 5, 10, 50};					//otsortirovano po vozrastaniyu
	//int coins[] = {13, 15, 17, 20};					//dlya testirovaniya
	int SZ = sizeof(coins)/sizeof(coins[0]);
	int * minCoins = minimumCoins(SUM, SZ, coins);
	if(minCoins == NULL)
		printf("No solution\n");
	else
	{
		printf("Minimum coins: ");
		printCoins(SZ, coins, minCoins);
	}
	free(minCoins);
	return 0;
}