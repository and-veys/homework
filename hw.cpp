#include <iostream>
#include <locale>				//��� setlocale
int main()
{
	setlocale(LC_CTYPE, "Russian");		//��� ������ ���������  
	printf("������, ���!\n");
	return 0;
}