#include <stdio.h>
#include <stdlib.h>
#include "linkedListSt.h"

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

void linkedlistAddNodeBack(pLinkedList list, int item)
{//This is checking the of 
  if(list->front == NULL)
    {
      list->front = malloc(sizeof(Node));
      if(list->front != NULL)
	{
	  //Set the next node pointer to NULL. It is reiquered to do it
	  //The last node needs to always to point to null because its at the end of the list.
	  list->front->next = NULL;
	  //Now we are giving the next node to store data into the node 
	  //we created.
	  list->front->item = item;
	  //increase the size of the list.
	  list->size++;
	}
    }
  else
    {
	  //pNode current is equal to the front of the list.
	  //current is storing the front of the list.
      pNode current = list->front;
	  
      while(current->next != NULL)
	{
	  //This is storing whats next after the front node.
	  //Current is will continue to store the next node until
	  //the last node points to NULL. 
	  current = current->next;
	}
	 //Current now points to last node in list.
	 // current now creates a new node after the last node.
      current->next = malloc(sizeof(Node));
    if(current->next!=NULL)
	{
	  //current creates a new node and gives it data from item
	  current->next->item = item;
	  //the new node now needs to point to Null because 
	  //the last node needs to point to NULL.
	  current->next->next = NULL;
	  //the amount of nodes is now updated which is size.
	  list->size++;
	}
      
    }
  
}

void linkedlistAddSortedNode(pLinkedList list, int item)
{
	//I created a node called temp and giving it space
	pNode temp = malloc(sizeof(Node));
	//Then I created a node called current and set it equal to
	//the front of the node.
	pNode current = list->front;
	/*I needed to create another varaible called temp
	to set it equal whats next after current*/
	pNode temp2;
	if(temp != NULL)
	{
		//we are storing into temp and giving it the data of temp.
		temp->item = item;
	}
	/*Each node has a pointer and a value. Each node can 
	only use the variables next and item. Next is the 
	pointer and item is the value*/
	while(current->next != NULL)
	{
	
	if(temp->item > current->item && temp->item < current->next->item)
		{
		/*I set temp2 equal to whats after current because after I set current pointer to temp, It 
		willnow have a diffrent meaning for current->next*/
			temp2 = current->next;
		/* Now the pointer from current is pointing to temp. So current->next is now pointing to the node temp*/
			current->next = temp;
		/*Now I told the node temp to point to the next node. temp is pointing to nothing. So we set the pointer of 			temp to the next node which is stored into temp2*/
			temp->next = temp2;
			break;
		}
		//current is not set to the next node.
		//so Now when we run it, current is now equal to the next node
			current = current->next;
	}
  
}

//This destroys the nodes
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
