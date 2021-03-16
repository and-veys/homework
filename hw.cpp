#include <iostream>
#define EXERCISE_1(x, y) (((x) >= 0) && ((x) < (y)))
#define EXERCISE_2(a, n, m) (*(*((a)+(n))+(m)))
#define EXERCISE_3(a, t) (sizeof(a)/sizeof(t))
int main()
{
//Exercise #1
	double a = 3.45;
	double b = 4.54;
	std::cout << EXERCISE_1(a, b) << std::endl;
//Exercise #2
	int n = 4;
	int m = 5;	
	int ** arr = new int * [n];
	for(int i=0; i<n; i++)
		arr[i] = new int [m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
				EXERCISE_2(arr, i, j) = 100+i*10+j;	
	std::cout << EXERCISE_2(arr, 3, 2) << std::endl;
	for(int i=0; i<n; i++)
		delete[] arr[i];
	delete[] arr;
//Exercise #3
	double arr_2[] = {2.23, 45.5, -67.54, 34.9, -5.43, 76};
	for(int i=0; i<EXERCISE_3(arr_2, double); i++)
		std::cout << arr_2[i] << " ";
	return 0;
}