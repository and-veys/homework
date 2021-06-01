#include <iostream>
#define TRUE 1==1
#define FALSE 1==2
typedef int boolean;
typedef struct Node
{
	int dt;
	Node * left;
	Node * right;
}Node;
Node * insert(Node * root, int dt)
{
	Node * tmp = (Node *)malloc(sizeof(Node));
	if(tmp==NULL) return NULL;
	tmp->dt = dt;
	tmp->left = NULL;
	tmp->right = NULL;
	if(root != NULL)
	{
		Node * par = root;
		Node * cur = root;
		while(TRUE)
		{
			if(dt <= cur->dt)
			{
				cur = cur->left;
				if(cur == NULL)
				{
					par->left = tmp;
					break;
				}				
			}
			else
			{
				cur = cur->right;
				if(cur == NULL)
				{
					par->right = tmp;
					break;
				}
			}
			par = cur;						
		}		
	}		
	return tmp;
}
int heightTree(Node * root)
{
	if(root == NULL) return 0;
	int lenLeft = heightTree(root->left);
	int lenRight = heightTree(root->right);
	return 1+(lenLeft > lenRight ? lenLeft : lenRight);
}
boolean balanceTree(Node * root)
{
	if(root == NULL) return TRUE;
	int lenLeft = heightTree(root->left);
	int lenRight = heightTree(root->right);
	return (abs(lenLeft-lenRight) <= 1 && balanceTree(root->left) && balanceTree(root->right));
	
}
void printTree(Node * root)
{
	if(root!=NULL)
	{
		printf("%4d", root->dt);
		if(root->left != NULL || root->right != NULL)
		{
			printf("[");
			printTree(root->left);
			printf(";");
			printTree(root->right);
			printf("]");
		}
	}
	else
		printf("NULL");
}
void freeTree(Node * root)
{
	if(root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);	
}
int randInt(int border)
{
	return rand()%border; 
}
boolean findTree(Node * root, int dt)
{
	if(root == NULL) return FALSE;
	if(root->dt == dt) return TRUE;
	return (findTree(root->left, dt) || findTree(root->right, dt));
}
int main()
{
//Exercise #1
	int array[] = {7, 4, 3, 10, 0, 2, 5, 9, 0, 17, 8, 32, 87, 98, 4, 33};
	int MAX = sizeof(array)/sizeof(array[0]);
	Node * root = NULL;
	root = insert(root, array[0]);
	for(int i=1; i<MAX; i++)
		insert(root, array[i]);
	printTree(root);
	printf("\nTree is%sbalanced.\n", (balanceTree(root) ? " " : " not "));
//Exercise #2
	const int SIZE = 50;	
	MAX = 10000;
	int BORDER = 1000;
	Node * trees[SIZE];
	for(int i=0; i<SIZE; i++)
	{
		trees[i] = NULL;
		trees[i]=insert(trees[i], randInt(BORDER));
		for(int j=1; j<MAX; j++)
			insert(trees[i], randInt(BORDER));		
	}
//Exercise #3
	int balance=0;
	for(int i=0; i<SIZE; i++)
	{
		if(balanceTree(trees[i]))
			balance++;
		freeTree(trees[i]);
	}
	printf("Balanced = %f%%\n", 1.0*balance/SIZE);
//Exercise #4
	printf("10 was%sfound.\n", (findTree(root, 10) ? " " : " not "));
	printf("55 was%sfound.\n", (findTree(root, 55) ? " " : " not "));
	freeTree(root);
	return 0;
}