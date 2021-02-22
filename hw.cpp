#include <iostream>
#include <locale>				//для setlocale
int main()
{
	setlocale(LC_CTYPE, "Russian");		//для вывода кирилицей  
	std::cout << "Привет, Мир!" << std::endl;
	return 0;
}