#include <stdio.h>
#include <stdlib.h>
typedef int item Item;
typedef struct node Node, *pNode;

struct node
{
	int item;
	pNode next;
};

struct linkedlist
{	
	//This is the front of the node and the begining
	pNode front;
	int size;
	pNode iterator;
};
typedef struct linkedlist LinkedList, *pLinkedList; 

pLinkedList linkedlistInitDefault();
void linkedlistAddNode(pLinkedList list, Item item);
void linkedlistDestroy(pLinkedList *list);

int main(void)
{
	pLinkedList list = linkedlistInitDefault();
	return 0;
}
pLinkedList linkedlistInitDefault()
{
	pLinkedList pList = malloc(sizeof(LinkedList));
	if(pList != NULL)
	{
		pList->front = NULL;
		pList->iterator = NULL;
		pList->size = 0;
	}
	return pList;
}
void linkedlistAddNode(pLinkedList pList, Item item)
{
	if(pList -> dront == NULL)
	{
		pList -> front = malloc(sizeof(Node));
		if(pList->front != NULL)
		{
			pList->front->item = item;
			pList->front->next = NULL;
			pList->size++;
		}
	}
	else
	{
		pNode current = pList->front;
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = malloc(sizeof(Node));
		if(current->next != NULL)
		{
			current->next->item = item;
			current->next->next = NULL;
			pList->size++;
		}
	}
}
void linkedlistDestroy(pLinkedList *list)
{
	if(*list) != NULL)
	{
		printf("list is not null\n");
	}
}