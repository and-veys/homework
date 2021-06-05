#include <iostream>
#define SZ 17
#define TRUE 1==1
#define FALSE 1==2
typedef int boolean;
int matrix[SZ][SZ] = 
{
	{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//0
	{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},	//1
	{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},	//2
	{0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0},	//3
	{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},	//4
	{0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},	//5
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},	//6
	{0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},	//7
	{0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0},	//8
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//9
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},	//10
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//11
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//12
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//13
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},	//14
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//15
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}		//16
};
struct Vertex;
typedef struct Edge
{
	Vertex * vertex;
	Edge * next;
} Edge;
typedef struct Vertex
{
	Edge * head;
	Vertex * next;
	Vertex * prev;
	int dt;
	int count_out;
	int count_in;
	boolean visited;
} Vertex;
void printArray(int* ar, int L)
{
	for(int i=0; i<L; i++)
		printf("%3d", *(ar+i));
	printf("\n");	
}
void printMatrix(int** mx, int W, int H)
{
	for(int i=0; i<H; i++)
		printArray((int *)(mx + i*H), W);
}
void printGraph(Vertex * gr, int L)
{
	Vertex * tmp;
	Edge * ed;
	for(int i=0; i<L; i++)
	{
		tmp = gr+i;
		ed = tmp->head;
		printf("%2d - ", tmp->dt);
		while(ed != NULL)
		{
			printf("%3d", ed->vertex->dt);			
			ed = ed->next;
		}
		printf("\n");
	}	
}
int error()
{
	printf("Error");
	return 1;
}
boolean addEdge(Vertex * par, Vertex * ch)
{
	Edge * ed = (Edge *)malloc(sizeof(Edge));
	if(ed == NULL) return FALSE;
	ed->vertex = ch;
	ed->next=par->head;
	par->head = ed;
	return TRUE;
}
boolean initVertex(Vertex * gr, Vertex * vx, int dt, int * mx, int L)
{
	vx->next = NULL;
	vx->prev = NULL;
	vx->head=NULL;
	vx->visited = FALSE;
	vx->dt = dt;
	vx->count_out = 0;
	vx->count_in = 0;
	for(int i=0; i<L; i++)
	{
		if(*(mx+i)==1)
		{
			if(addEdge(vx, gr + i)==FALSE) return FALSE;
			vx->count_out++;			
		}
	}
	return TRUE;
}
boolean initGraph(Vertex * gr, int ** mx, int L)
{
	for(int i=0; i<L; i++)
		if(initVertex(gr, gr+i, i, (int *)(mx + i*L), L)==FALSE) return FALSE;
	return TRUE;
}
void freeGraph(Vertex * gr, int L)
{
	Vertex * tmp;
	Edge * ed;
	for(int i=0; i<L; i++)
	{
		tmp = gr+i;
		while(tmp->head != NULL)
		{
			ed = tmp->head->next;
			free(tmp->head);
			tmp->head = ed;
		}
	}	
}
void traversDepth(Vertex * vx)
{
	if(vx->visited) return;
	vx->visited = TRUE;
	Edge * ed = vx->head;
	while(ed != NULL)
	{
		ed->vertex->count_in++;
		traversDepth(ed->vertex);
		ed = ed->next;
	}	
}
void traversMatrix(Vertex * gr, int ** mn, int L)
{
	Vertex * tmp;
	int * ar;
	for(int i=0; i<L; i++)
	{
		ar = (int *)(mn + i*L);
		for(int j=0; j<L; j++)
		{
			if(*(ar+j) == 1)
			{
				tmp = gr + j;
				tmp->count_in++;
			}
		}					
	}
}
Vertex * sortGraph(Vertex * gr, int L)
{
	Vertex * head = gr;
	Vertex * tail = gr;
	Vertex * tmp;
	Vertex * cur;
	for(int i=1; i<L; i++)
	{
		cur = head;
		tmp=gr+i;
		while(cur != NULL && cur->count_in > tmp->count_in)
			cur = cur->next;			
		if(cur == NULL)
		{
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
		}
		else
		{
			tmp->prev = cur->prev;
			tmp->next = cur;
			cur->prev = tmp;
			if(tmp->prev == NULL)
				head = tmp;
			else
				tmp->prev->next = tmp;
		}		
	}
	return head;
}
void paintSortGraph(Vertex * head)
{
	Vertex * tmp = head;
	while(tmp != NULL)
	{
		printf("[%2d-%2d] ", tmp->dt, tmp->count_in);
		tmp=tmp->next;
	}
	printf("\n");
}
void paintCountIn(Vertex * gr, int L)
{
	Vertex * tmp;
	for(int i=0; i<L; i++)
	{
		tmp = gr+i;
		printf("[%2d-%2d] ", tmp->dt, tmp->count_in);
	}
	printf("\n");
}
void clearGraph(Vertex * gr, int L)
{
	Vertex * tmp;
	for(int i=0; i<L; i++)
	{
		tmp = gr+i;
		tmp->next=NULL;
		tmp->prev=NULL;
		tmp->visited=FALSE;
		tmp->count_in=0;
	}
}
int main()
{
	Vertex graph[SZ];
	if (initGraph(graph, (int **)matrix, SZ) == FALSE) return error();
	printGraph(graph, SZ);
	int start_vertex = 1;
	traversDepth(graph + start_vertex);
	paintSortGraph(sortGraph(graph, SZ));
	clearGraph(graph, SZ);
	traversMatrix(graph, (int **)matrix, SZ);
	paintSortGraph(sortGraph(graph, SZ));
	freeGraph(graph, SZ);
	return 0;
}