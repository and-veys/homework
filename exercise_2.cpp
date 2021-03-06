#include "hw.h"
void hw5::init_array(int * a, int n)
{
	for(int i=0; i<n; i++)
		*(a+i) = 1+3*i;
}