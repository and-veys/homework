#include <iostream>
#include <locale>				//��� setlocale
typedef enum field {empty, X, O, won_X, won_O} Field;	// ������� 5 ����. �� ����� �������� � �� 11 )) 
typedef union my_union
{
	int i;
	float f;
	char c;
} My_union;
typedef struct game_XO
{
	bool end;			//���� ��������� ����;
	int count;			//������� ��������� �����;
	Field cell[3][3];	//������� ����	
} Game_XO;
typedef struct my_struct
{
	My_union un;
	int is_int : 1;
	int is_float : 1;
	int is_char : 1;	
} My_struct;
void init_game(Game_XO * g);
int main()
{
	setlocale(LC_CTYPE, "Russian");		//��� ������ ���������  
// ������� �1
	int i=0;
	short sh = 5;
	char ch='A';
	long l = 10;
	long long ll = 20;
	float f = 1.15;
	double d = 12.21;
	bool b = false;
// ������� �2,3
	Field arr[] = {empty, X, O, won_X, won_O};
// ������� �4
	Game_XO gm;	
	init_game (&gm);		
// ������� �5
	My_struct st;
	st.un.f = 32.67;
	st.is_int = 0;
	st.is_float = 1;
	st.is_char = 0;	
	std::cout << sizeof(st) << std::endl;	//8 ����
	return 0;
}
void init_game(Game_XO * g)
{
	g->count = 9;
	g->end = false;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			g->cell[i][j] = empty;	
}