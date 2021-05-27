#include <iostream>
#define SIZE 11
#define SIZE_2 32
typedef struct
{
	int pr;
	char dt;
} Note;
Note * array[SIZE];
char array_2[SIZE_2];
int head;
int tail;
int items;
void init()
{
	items = 0;
	for(int i=0; i<SIZE; i++)
		array[i] = NULL;
}
void nextIndex(int * a)
{
	(*a)++;
	(*a) %= SIZE;
}
void prevIndex(int * a)
{
	(*a)--;
	(*a) %= SIZE;
}
void insert(int pr, char dt)
{
	Note * note = (Note *)malloc(sizeof(Note));
	note->pr = pr;
	note->dt = dt;
	if(items != SIZE)
	{
		if(items == 0)
		{
			head=0;
			tail=0;
		}
		else nextIndex(&tail);
		array[tail] = note;
		items++;
	}
	else
		printf("\nArray is full !!\n");
}
Note * remove()
{
	Note * rez = NULL;
	if(items != 0)
	{
		int ind = head;
		items--;
		if(items != 0)
		{			
			int i = head;
			do
			{
				nextIndex(&i);
				if(array[i]->pr > array[ind]->pr)
					ind = i;
			} while(i != tail);
			rez = array[ind];
			if(ind == head) 
				nextIndex(&head);
			else
			{
				while(ind != tail)
				{
					i=ind;
					nextIndex(&ind);
					array[i] = array[ind];
				}				
				prevIndex(&tail);
			}			
		}
		else 
			rez = array[ind];
		array[ind] = NULL;
	}
	else
		printf("\nArray is empty !!\n");
	return rez;	
}
void printArray()		
{
	for(int i=0; i<SIZE; i++)
	{
		if(array[i] == NULL)
			printf(" NULL  ");
		else
			printf("[%2d %c] ", array[i]->pr, array[i]->dt);
	}
	printf(" - [%2d %2d %2d]\n", head, tail, items);
}
void push(char ch)
{
	if(items != SIZE_2)
		array_2[++items] = ch;
	else
		printf("\nArray is full !!\n");	
}
void DecToBin(int num)
{
	items=0;
	do
	{
		push(num%2 + '0');
		num /= 2;
	}while(num != 0);
}
char pop()
{
	if(items != 0)
		return array_2[items--];
	else
		printf("\nArray is empty !!\n");
	return -1;
}
int main()
{
//Exercise #1
	init();
	insert(8, 'l');
	insert(2, 'l');
	insert(6, ' ');	
	insert(3, 'r');	
	insert(5, 'W');	
	insert(1, 'd');
	insert(7, 'o');
	insert(9, 'l');
	insert(10, 'e');
	insert(4, 'o');
	insert(11, 'H');
	insert(0, '!');
	printArray();
	Note * note = remove();
	while(note != NULL)
	{
		printf("%c", note->dt);
		free(note);
		note = remove();
	}
//Exercise #2	
	DecToBin(12345);
	char ch = pop();
	while(ch >= 0)
	{
		printf("%c", ch);
		ch = pop();	
	}
	return 0;
}