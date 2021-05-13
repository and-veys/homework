#include <iostream>
#include <locale>				//для setlocale
int main()
{
	setlocale(LC_CTYPE, "Russian");		//для вывода кирилицей  
	printf("Привет, Мир!\n");
	return 0;
}