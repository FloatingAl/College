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
	x->item = 10;
	
}