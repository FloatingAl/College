#include<stdio.h>
#include<stdlib.h>



typedef struct node *Next;
struct node{
	int item;
	Next next;
};

typedef struct node Node, *pNode;

int main(void)
{
	Next x = malloc(sizeof(*x));
	if(!x)
	{
		printf("could not allocate x\n");
		return(1);
	}
	x->item = 10;
	x->next = NULL;
	x->next = malloc(sizeof(Next));
	/*x->next->item = 20;
	This stores a 20 in the next node.
	----
	Next temp = x->next->next;
	free(x->next);
	x->next = Temp;
	^This deletes the node and replaces it with the one after it. Basically delte a node in between 2 nodes.
	----
	Next temp = malloc(sizeof(Next));
	temp ->next = x->next;
	x->next = temp;
	This make a node in between 2 nodes.
	----
	//This creates another node. 
	/*Next y = malloc(sizeof(*y));
		if(!y)
	{
		printf("could not allocate x\n");
		return(1);
	}
	x->next = y;
	----*/
	return 0;
}