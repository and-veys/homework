#include <iostream>
#include <locale>				//для setlocale
int main()
{
	setlocale(LC_CTYPE, "Russian");		//для вывода кирилицей 
//Exercise #1
	double a = 10;
	double b = 7;
	if(a+b >=10 && a+b <= 20)
	{
		std::cout << "TRUE" << std::endl;
	}
	else
	{
		std::cout << "FALSE" << std::endl;
	}
//Exercise #2
	int c = 21;
	int i;
	if(c > 0)
	{
		for(i=2; i<c; i++)
		{		
			if(c%i==0)
			{
				break;
			}
		} 
		std::cout << c << " - натуральное" << ((i==c)?" ":" не ") << "простое число" << std::endl;
	}
	else
	{
		std::cout << c << " - не натуральное число" << std::endl;		
	}
//Exercise #3
	const int d1 = 14;
	const int d2 = 10;
	if((d1 == 10 && d2 == 10) || d1+d2==10)
	{
		std::cout << "TRUE" << std::endl;
	}
	else
	{
		std::cout << "FALSE" << std::endl;
	}
//Exercise #4
	int y = 2021;
	bool bl;
	if(y%400==0)
	{
		bl=true;
	}
	else if (y%100==0)
	{
		bl=false;				
	}
	else
	{
		bl = (y%4==0);
	}
	std::cout << y << " - " << (bl?"":"не ") << "високосный год" << std::endl;
	return 0;
}