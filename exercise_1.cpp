#include "hw.h"
void hw5::change_array(int * a, int n)
{
		for(int i=0; i<n; i++)
			*(a+i) = !(*(a+i));	
}
