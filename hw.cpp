#include <iostream>
#include <locale>				//��� setlocale
int main()
{
	setlocale(LC_CTYPE, "Russian");		//��� ������ ���������  
	std::cout << "������, ���!" << std::endl;
	return 0;
}