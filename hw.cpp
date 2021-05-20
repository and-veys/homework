#include <iostream>
#include <math.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printArray(int* arr, int len, int offset)
{
	char str[5];
	sprintf(str, "%%%dd", offset);
	for(int i=0; i<len; i++)
		printf(str, *(arr + i));
	printf("\n");
}
void print2Array(int * arr, int row, int col, int offset)
{
		for(int i=0; i<row; i++)			
			printArray(arr+i*col, col, offset);
		printf("\n");		
}
void bubbleSort(int* arr, int len)	//kazhetsya tak bystree, chem v uroke
{
	for(int j=len-1; j>0; j--)	
	{
		for(int i=0; i<j; i++)		//ne nuzhno proveryat' uzhe ustanovlennye elementy	
		{
			if(*(arr+i) > *(arr+i+1)) 
				swap(arr+i, arr+i+1);
		}
	}
}
void reverseArray(int * arr, int len)
{
	int * p = arr+len-1;
	for(int i=0; i< len/2; i++)
		swap(arr+i, p-i);
}
double fun(int x)
{
	return sqrt(fabs(x))+5*pow(x,3);
}
int main()
{
//Exercise #1
	const int SIZE_R=3;
	const int SIZE_C=3;
	int array[SIZE_R][SIZE_C] = {{1,9,2}, {5,7,6}, {4,3,8}};
	print2Array((int *)array, SIZE_R, SIZE_C, 3); 
	bubbleSort((int *)array, SIZE_R*SIZE_C);
	print2Array((int *)array, SIZE_R, SIZE_C, 3); 
//Exercise #2	
	const int SIZE = 11;
	int array_2[SIZE] = {-4, 4, 55, 8, 7, -2, 0, 5, 4, 6, -11};		//dlya uproshcheniya celye chisla	
	double temp;
	printArray(array_2, SIZE, 4);
	reverseArray(array_2, SIZE);
	printArray(array_2, SIZE, 4);
	for(int i=0; i<SIZE; i++)
	{
		temp = fun(array_2[i]);
		printf("#%2d: fun(%3d) = %10.3f%s\n", i, array_2[i], temp, ((temp > 400)?" >400!!":""));		
	}
	return 0;
}