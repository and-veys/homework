#include "hw.h"
#include <iostream>
#include <stdarg.h>
void hw5::change_array_5(int n, ...)
{
	va_list lst;
	va_start(lst, n);
	for(int i=0; i<n; i++)
		std::cout << (!va_arg(lst, int)) << " ";
	std::cout << std::endl;		
}