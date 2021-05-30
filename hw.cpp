#include <iostream>
#define TRUE 1==1
#define FALSE 1==2
typedef int boolean;
typedef struct Node
{
	int dt;
	Node * next;
} Node;
typedef struct
{
	Node * head;
	int size;
	
} List;
void initList(List * list)
{
	list->head = NULL;
	list->size = 0;
}
Node * push(List * list, int dt)
{
	Node * tmp = (Node *)malloc(sizeof(Node));
	if(tmp != NULL)
	{
		tmp->next = list->head;
		tmp->dt = dt;
		list->head = tmp;
		list->size++;
	}
	return tmp;
}
Node * pop(List * list)
{
	Node * tmp = list->head;
	if(tmp != NULL)
	{
		list->head = tmp->next;
		list->size--;
	}		
	return tmp;
}
void printList(List * list)
{
	Node * tmp = list->head;
	while(tmp != NULL)
	{
		printf("[%2d] ", tmp->dt);
		tmp = tmp->next;
	}
	printf("\n");
}
void freeList(List * list)
{
	Node * tmp;
	while(list->head != NULL)
	{
		tmp = list->head->next;
		free(list->head);
		list->head = tmp;		
	}
	free(list);	
}
boolean controlBrackets(char * dt, char * br, int nBr, List * list)
{
	int i=0;
	while(dt[i] != '\0')
	{
		for(int j=0; j < nBr; j++)
		{
			if(dt[i] == br[j])
			{
				if(j%2 != 0)	//esli zakrytaya skobka		
				{
					if(list->head == NULL || list->head->dt != j-1)
						return FALSE;
					else
						free(pop(list));
				}			
				else 			//esli otkrytaya skobka
				{
					if(push(list, j)==NULL)
					{
						printf("ERROR");
						return FALSE;
					}
				}
				break;
			}
		}	
		i++;
	}
	return (list->head == NULL);
}
boolean copyList(List * cl, List * list)
{
	Node * tmp;
	for(int i=0; i<list->size; i++)
	{
		tmp = list->head;
		for(int j=i+1; j<list->size; j++)
			tmp = tmp->next;
		if(push(cl, tmp->dt)==NULL)
			return FALSE;			
	}
	return TRUE;	
}
boolean sortList(List * list)
{
	Node * tmp = list->head;
	if(tmp != NULL)
	{
		int dt = tmp->dt;
		tmp = tmp->next;
		while(tmp != NULL)
		{
			if(tmp->dt > dt)
				return FALSE;
			dt = tmp->dt;
			tmp = tmp->next;
		}
	}
	return TRUE;
}
int main()
{
//Exercise #1
	char brackets[] = {'(',')','[',']','{','}'};
	char str[64];
	List * stack = (List *)malloc(sizeof(List));
	initList(stack);
	sprintf(str, "[2/{5*(4+7)}]");
	if(controlBrackets(str, brackets, sizeof(brackets), stack)==TRUE)
		printf("%s - is correct.\n", str);
	else
	{
		printf("%s - is not correct.\n", str);
		freeList(stack);
	}
//Exercise #2
	int i=0;
	List * copyStack = (List *)malloc(sizeof(List));
	stack = (List *)malloc(sizeof(List));
	initList(stack);
	initList(copyStack);
	sprintf(str, "abcdWefgh");
	while(str[i] != '\0')
	{
		if(push(stack, str[i]) == NULL)
			break;
		i++;
	}
	if(str[i] == '\0' && copyList(copyStack, stack))
	{		
		printList(stack);
		printList(copyStack);
	}
	else
		printf("ERROR");
	freeList(copyStack);
//Exercise #3
	if(sortList(stack) == TRUE)
		printf("List is sort");
	else
		printf("List is not sort");
	freeList(stack);
	return 0;
}