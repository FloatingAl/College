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
	/*The point of this function is to have the user enter as many strings as they want and instering that string into a node. After that they would exit then finish */
	Item input;
	int string = 1;	
	printf("[0] to stop adding strings:\n");
	do{
	    input = malloc(100*sizeof(char));
	    printf("Enter string: "); 
	    gets(input);
	    //scanf(" %s",input);
	    linkedlistAddNodeBack(list,input);
	    scanf("%d",&string);		
	}while(string == 1);	

}
void linkedlistShow(pLinkedList list)
{
	/*This prints out every node info in list until it hits null.*/
        pNode temp;
        for(temp = list->front ; temp != NULL;temp = temp->next)
        {
                printf("%s\n",temp->item);    
        } 
}

