#include <iostream>
void quickSortImproved(int* arr, int first, int last);
void printArray(int* arr, int len, int offset)
{
	char str[5];
	sprintf(str, "%%%dd", offset);
	for(int i=0; i<len; i++)
		printf(str, *(arr + i));
	printf("\n");
}
void fillRandomArray(int* arr, int len, int border)
{
	for(int i=0; i<len; i++)
		arr[i] = rand()%border;
}
void controlSortArray(int* arr, int len)
{
	int a = arr[0];
	for(int i=1; i<len; i++)
	{
		if(arr[i] < a)
		{
			printf("Sort is incorrect\n");
			return;
		}
	}
	printf("Sort is OK\n");
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void insertSort(int* arr, int first, int last)			//a chto zdes' luchshe ispol'zovat' WHILE ili FOR
{
	int temp;
	int j;
	for(int i=first+1; i<=last; i++)
	{
		temp = arr[i];
		for(j = i-1; j >= 0; j--)
		{
			if(arr[j] > temp)
				arr[j+1] = arr[j];
			else 
				break;
		}
		arr[j+1] =temp;	
	}
}
void setMedianElement(int* arr, int first, int last)
{
	int m = (first+last)/2;
	int a[] = {arr[first], arr[last], arr[m]};
	insertSort(a, 0, 2);
	if(a[1] == arr[first]) swap(&arr[first], &arr[m]);
	else if(a[1] == arr[last]) swap(&arr[last], &arr[m]);
}
void quickSort(int* arr, int first, int last)
{
	int i=first;
	int j=last;
	int x=arr[(first+last)/2];		
	do
	{
		while(arr[i] < x) i++;
		while(arr[j] > x) j--;
		if(i <= j)	
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}		
	} while(i <= j);
	if(i < last) quickSortImproved(arr, i, last);
	if(j > first) quickSortImproved(arr, first, j);	
}
void quickSortImproved(int* arr, int first, int last)
{
	if(last-first <= 9)
		insertSort(arr, first, last);
	else
	{
		setMedianElement(arr, first, last);
		quickSort(arr, first, last);
	}
}
void exercise2Sort(int* arr, const int len)
{	
	int b[len];	 	//tak kak nechetnye chisla ne nado sortirovat', to dostatochno odnoj korziny	
	int n=0;		//schetchik vynes v otdel'nuyu peremennuyu
	for(int i=0; i<len; i++)
	{
		if(arr[i]%2 == 0) b[n++] = arr[i];				
	}
	quickSortImproved(b, 0, n-1);
	n=0;
	for(int i=0; i<len; i++)
	{
		if(arr[i]%2 == 0) arr[i] = b[n++];				
	}	
}
int main()
{
// Exercise #1
	const int SIZE = 1000;
	int array[SIZE];
	fillRandomArray(array, SIZE, 100);
	quickSortImproved(array, 0, SIZE-1);
	controlSortArray(array, SIZE); 					//dlya proverki sortirovki
// Exercise #2
	int array_2[] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
	int sz = sizeof(array_2)/sizeof(array_2[0]);
	printArray(array_2, sz, 2);
	exercise2Sort(array_2, sz);
	printArray(array_2, sz, 2);
	return 0;
}