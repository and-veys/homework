#include <iostream>
#include "hw.h"

void print_array(int * a, int n)
{
	for(int i=0; i<n; i++)
		std::cout << *(a+i) << " ";
	std::cout << std::endl;
}
int main()
{
//exercise #6
	void (*ex_1)(int *, int);
	ex_1 = hw5::change_array;
	void (*ex_2)(int *, int);
	ex_2 = hw5::init_array;
	bool (*ex_3)(int *, int);
	ex_3 = hw5::check_array;
	void (*ex_4)(int *, int, int);
	ex_4 = hw5::offset_array;
	void (*ex_5)(int, ...);
	ex_5 = hw5::change_array_5;
//exercise #1
	int arr_1[] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
	int n = sizeof(arr_1)/sizeof(int);
	(*ex_1)(arr_1, n);
	print_array(arr_1, n);
//exercise #2
	int arr_2[8];
	n = sizeof(arr_2)/sizeof(int);
	(*ex_2)(arr_2, n);
	print_array(arr_2, n);
//exercise #3
	int arr_3[] = {10, 1, 2, 3, 4};
	n = sizeof(arr_3)/sizeof(int);
	std::cout << ((*ex_3)(arr_3, n)?"TRUE":"FALSE") << std::endl;
//exercise #4
	int arr_4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	n = sizeof(arr_4)/sizeof(int);
	(*ex_4)(arr_4, n, 33);
	print_array(arr_4, n);
//exercise #5;
	(*ex_5)(10, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0);
	return 0;
}