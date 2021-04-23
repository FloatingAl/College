#include <stdio.h>
#include <stdlib.h>
#include "linkedListQueue.h"

//Initializing and creating our linkedlist
pLinkedList linkedlistInitDefault()
{
  pLinkedList list = malloc(sizeof(LinkedList));
  list->front = NULL;
  list->back =  NULL;
  list->size = 0;
  return list;
}

int linkedlistGetSize(pLinkedList list)
{
  return list->size;
}

void linkedlistAddNodeBack(pLinkedList list, Item item)
{
  if(list->back == NULL)
    {
      pNode temp = malloc(sizeof(Node));
      temp->item = item;
      temp->next = NULL;
      list->front = temp;
      list->back = temp;
    }
  else
    {
      pNode temp = malloc(sizeof(Node));
      temp->item = item;
      temp->next = NULL;
      list->back->next = temp;
      list->back = list->back->next;
    }
  list->size++;
  
}

Item linkedlistRemoveNodeFront(pLinkedList list)
{
  if(list->front == NULL)
    {
      return -1;
    }
  else if(list->front == list->back)
    {
      Item tempItem = list->front->item;
      free(list->front);
      list->front = NULL;
      list->back = NULL;
      list->size--;
      return tempItem;
    }
  else
    {
      Item tempItem = list->front->item;
      pNode temp = list->front->next;
      free(list->front);
      list->front = temp;
      list->size--;
      return tempItem;
      
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
	      free(current);
	      current = next;  
	    }
	  printf("setting the list to null\n");
	  free((*list));
	  (*list) = NULL;
	}
      
    }

}

