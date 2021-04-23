#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListSt.h"
#include "item.h"

pLinkedList linkedlistInitDefault()
{
  pLinkedList list = malloc(sizeof(LinkedList));
  list->front = NULL;
  list->iterator = NULL;
  list->size = 0;
  return list;
}

int linkedlistGetSize(pLinkedList list)
{
  return list->size;
}

void linkedlistAddNodeBack(pLinkedList list, Item item)
{
  if(list->front == NULL)
    {
      list->front = malloc(sizeof(Node));
      if(list->front != NULL)
	{
	  list->front->next = NULL;
	  list->front->item = item;
	  list->size++;
	}
    }
  else
    {
      pNode current = list->front;
      while(current->next != NULL)
	{
	  current = current->next;
	}
      current->next = malloc(sizeof(Node));
      if(current->next!=NULL)
	{
	  current->next->item = item;
	  current->next->next = NULL;
	  list->size++;
	}
      
    }
  
}


void linkedlistDestroy(pLinkedList *list)
{
  if((*list) != NULL)
    {
      printf("list is not null\n");
      if((*list)->front == NULL)
	{
	  free((*list));
	  (*list) = NULL;
	}
      else
	{
	  printf("looping to delete all nodes\n");
	  pNode current = (*list)->front;
	  pNode next = (*list)->front;
	  while(current!=NULL)
	    {
	      printf("I am deleting here\n");
	      next = current->next;
	      free(current->item);
	      free(current);
	      current = next;  
	    }
	  printf("setting the list to null\n");
	  free((*list));
	  (*list) = NULL;
	}
      
    }

}
void linkedlistScanInit(pLinkedList list)
{
		
	Item input;
	int string = 1;	
	while(string == 1)
	   {
	    input = malloc(100*sizeof(char));
	    printf("Enter string: "); 
	    //gets(input);
	    scanf(" %s",input);
	    fflush(stdin);
	    linkedlistAddNodeBack(list,input);
	    printf("Do you to continue ? Yes[1] No[0]: ");
	    scanf("%d",&string);		
	   }
}
void linkedlistShow(pLinkedList list)
{
        pNode temp;
        for(temp = list->front ; temp != NULL;temp = temp->next)
        {
                printf("%s\n",temp->item);    
        } 
}
void linkedlistSort(pLinkedList list)
{	
	//Check to see if the list is empty
	if(list == NULL)return;
	
	//if(linkedlistGetSize(list) < 2);
	//Current to the front of the list
	pNode current = list->front;
	char* temp;	
	//Holds what next of current
	pNode hold = current->next; 
	
	//iterate through null
	while(current != NULL)
	{
		//call the less function and give it current item and hold item. If its greater than 0 it will do the process of switching 
		if(less(current->item, hold->item) > 0)
		{
			temp = current->item;
			current->item = hold->item;
			hold->item = temp;
		}
		else
		{
			hold = current->next;
		}
		current = current->next;
		
	}

	
}
