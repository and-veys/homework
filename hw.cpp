#include <iostream>
#include <locale>				//��� setlocale
int main() 
{
	setlocale(LC_CTYPE, "Russian");		//��� ������ ���������  
	int a = -1;
	int i;
	while (a < 2)
	{
		printf("������� ����� ������ 1: ");
		scanf("%d", &a);
	}
	for(i=2; i<a; i++)	
	{
		if(a%i == 0)
			break;		
	}
	printf("��c�� %d �������� %s", a, (a==i) ? "�������" : "���������");	
	return 0;
}