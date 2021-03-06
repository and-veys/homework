#include "hw.h"
bool hw5::check_array(int * a, int n)
{
	int sum = 0;
	int rez = 0;
	for(int i=0; i<n; i++)
		sum += *(a+i);
	for(int i=0; i<n; i++)
	{
		rez += *(a+i);
		if(rez == (sum-rez))
			return true;	
	}
	return false;	
}