#include <iostream>
#include <locale>				
#include "file.h"
extern int a2, b2, c2, d2;
double fun_1(int a, int b, int c, int d);
void init_numbers();
void init_array(int * a);
int main()
{
	setlocale(LC_CTYPE, "Russian");	
//Exercise #1
	const int a=10;
	const int b=15;
	const int c=71;
	const int d=11;
	std::cout << fun_1(a, b, c, d) << std::endl;
//Exercise #2
	int m=19;
	std::cout << ((m>21) ? (m-21)*2 : (m-21)) << std::endl;
//Exercise #3
	std::cout << fun_1(a1, b1, c1, d1) << std::endl; 	//3A - from file.h
	init_numbers();
	std::cout << fun_1(a2, b2, c2, d2) << std::endl; 	//3B - from file.cpp
//Exercise #4
	int arr[3][3][3];
	int * p_arr = (int *) arr;
	init_array(p_arr);
	std::cout << *(p_arr + 13) << std::endl;
	return 0;
}
double fun_1(int a, int b, int c, int d)
{
//	return (a*(b+(double)c/d));
	return (a*(b+(static_cast<double>(c)/d)));	
}
void init_array(int * a)
{
	int i, j, n;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			for(n=0; n<3; n++)
				*(a + i*9+j*3+n) = 100*(i+1)+10*(j+1)+n+1;
}