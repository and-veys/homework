#include <iostream>
#include <string.h>
#define SZ 256
#define RANK_START 'a'						//dlya hraneniya dliny stroki v bukvennom predstavlenii
#define RANK_END 'z'
#define RANK_SZ 4
#define RANK (RANK_END - RANK_START + 1)
#define TRUE 1==1
#define FALSE 1==2
typedef int boolean;
int getInt(char * ch)
{
	int sum=0;
	int k = 1;
	for(int i=RANK_SZ-1; i>=0; i--)
	{
		sum+=(ch[i] - RANK_START) * k;
		k*=RANK;	
	}
	return sum;
}
void getChar(int n, char * ch)
{
	for(int i=RANK_SZ-1; i>=0; i--)
	{
		ch[i] = RANK_START + n % RANK;
		n/=RANK;
	}
}
void coding_B(char* ar, char* tmp, int col, int row)
{
	int ch;	
	int k=0;
	for(int i=0; i<col; i++)
	{
		for(int j=0; j<row; j++)
		{			
			ch = ar[i+j*col];
			if(ch =='\0')
				tmp[k]='x';				
			else
				tmp[k]=ch;
			k++;
		}
	}
}
boolean coding_2(char* ar, char key)
{
	int k = strlen(ar);
	if(k < key || key < 1) return FALSE;
	int row = k/key;
	int col = key;
	if(k%key != 0) row++;
	if((row*col + RANK_SZ) >= SZ) return FALSE;		//RANK_SZ chtoby potom ubrat' pustye simvoly	
	char * tmp = (char *)calloc(SZ, 1);	
	if(tmp == NULL) return FALSE;	
	getChar(k, tmp);
	coding_B(ar, tmp+RANK_SZ, col, row);
	k = strlen(tmp);
	for(int i=0; i<k; i++)
		ar[i] = tmp[i];
	return TRUE;
}
boolean decoding_2(char* ar, char key)
{
	int k = strlen(ar) - RANK_SZ;
	if(k < key || key < 1 || k >= SZ) return FALSE;
	int row = k/key;
	int col = key;
	char * tmp = (char *)calloc(SZ, 1);	
	if(tmp == NULL) return FALSE;
	coding_B(ar+RANK_SZ, tmp, row, col);
	k = getInt(ar);
	for(int i=0; i<k; i++)
		ar[i] = tmp[i];
	ar[k] = '\0';
	return TRUE;
}
void coding_A(int len, char * ar, int key)
{	
	int ch;
	for(int i=0; i<len; i++)
	{
		ch = ar[i]+key;
		if(ch > 255) ch-=256;
		else if(ch < 0) ch+=256;		
		ar[i] = (char)ch;
	}
}
boolean coding_1(char* ar, char key)
{
	int k = strlen(ar);								
	if(k+RANK_SZ >= SZ) return FALSE;	//RANK_SZ chtoby korrektno obrabatyvat' nulevoj simvol	
	coding_A(k, ar, key);
	for(int i=k-1; i>=0; i--)
		ar[i+RANK_SZ] = ar[i];	
	getChar(k, ar);
	return TRUE;
}
boolean decoding_1(char* ar, char key)
{
	int k = strlen(ar);
	if(k <= RANK_SZ) return FALSE;
	k = getInt(ar);
	if(k+RANK_SZ >= SZ) return FALSE;
	coding_A(k, ar+RANK_SZ, -1*key);
	for(int i=0; i<k; i++)
		ar[i] = ar[i+RANK_SZ];	
	ar[k] = '\0';	
	return TRUE;
}
int main()
{
	char array[SZ] = "This Is A Secret Message!!";
	char key = 11;
	printf("Original: %s\n", array);
// Exercise #1
	if(coding_1(array, key))
	{
		printf("Code: %s\n", array);
		if(decoding_1(array, key)) 
			printf("Decode: %s\n", array);
		else printf("ERROR");				
	}
// Exercise #2
	if(coding_2(array, key))
	{
		printf("Code: %s\n", array);
		if(decoding_2(array, key)) 
			printf("Decode: %s\n", array);
		else printf("ERROR");				
	}
	else printf("ERROR");
	return 0;
}