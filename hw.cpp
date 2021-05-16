#include <iostream>
#include <locale>			

char rez[64];
char chess[5][5];
int DecToBin(int a, int n)
{
	if(a == 0) return n;
	rez[n] = a%2 + 48;
	return DecToBin(a/2, n-1);	
}
int NumberToPower(int a, int n)
{
	if(n == 0) return 1;
	if(n == 1) return a;
	return a * NumberToPower(a, n-1);	
}
int NumberToPower_2(int a, int n)
{
	return NumberToPower(a*a, n/2) * NumberToPower(a, n%2);
}
int routes_2(int x, int y)
{
	if(chess[x][y] == 1) return 0;
	if(x == 0 && y == 0) 
		return 0;
	else if (x == 0 || y == 0)
		return 1;
	else 
		return routes_2(x, y-1) + routes_2(x-1, y);
}
int main()
{
	setlocale(LC_CTYPE, "Russian");		
// Exercise #1
	rez[63] = '\0';
	printf("%s\n", DecToBin(12345, sizeof(rez)-2) + rez + 1);
// Exercise #3
	printf("%d\n", NumberToPower(5, 7));
// Exercise #4
	printf("%d\n", NumberToPower_2(5, 7));
// Exercise #5
	int nX = sizeof(chess)/sizeof(chess[0]);
	int nY = sizeof(chess[0]);
	for(int y=0; y<nY; y++)
		for(int x=0; x<nX; x++)
			chess[x][y] = 0;
	chess[3][2] = 1;	
	for(int y=0; y<nY; y++)
	{
		for(int x=0; x<nX; x++)
			printf("%5d", routes_2(x, y));
		printf("\n");
	}	
	return 0;
}