#include "hw.h"
void hw5::offset_array(int * a, int n, int offs)
{
	int k = (offs < 0)?-1*offs:offs;
	while(k >= n)
		k -=n;
	if(k==0)
		return;
/*	int * mem = (int *)malloc(n*sizeof(int));
	memcpy(mem, a, n*sizeof(int));
	if(offs > 0)
	{
		memcpy(a, (mem+n-k), k*sizeof(int));
		memcpy(a+k, mem, (n-k)*sizeof(int));
	}		
	else
	{
		memcpy(a, mem+k, (n-k)*sizeof(int));
		memcpy(a+n-k, mem, k*sizeof(int));
	}
	free(mem);
*/		
	int temp;
	for(int i=0; i<k; i++)
	{
		if(offs > 0)
		{
			temp = *(a+n-1);		
			for(int j=n-2; j>=0; j--)
				*(a+j+1)=*(a+j);
			*a = temp;
		}
		else
		{
			temp = *a;
			for(int j=1; j<n; j++)
				*(a+j-1) = *(a+j);
			*(a+n-1)= temp;
		}
	}
}