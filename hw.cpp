#include <iostream>
#include <locale>				//для setlocale
int main() 
{
	setlocale(LC_CTYPE, "Russian");		//для вывода кирилицей  
	int a = -1;
	int i;
	while (a < 2)
	{
		printf("Введите число больше 1: ");
		scanf("%d", &a);
	}
	for(i=2; i<a; i++)	
	{
		if(a%i == 0)
			break;		
	}
	printf("Чиcло %d является %s", a, (a==i) ? "простым" : "составным");	
	return 0;
}