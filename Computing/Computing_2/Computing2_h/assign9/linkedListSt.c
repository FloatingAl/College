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
	do{
	    input = malloc(100*sizeof(char));
	    printf("Enter string: "); 
	    scanf(" %s", input);
	    linkedlistAddNodeBack(list,input);
	    printf("Enter [1] to continue or [0] to stop: ");
	    scanf("%d",&string);		
	}while(string == 1);	

}
void linkedlistShow(pLinkedList list)
{
        pNode temp;
        for(temp = list->front ; temp != NULL;temp = temp->next)
        {
                printf("%s\n",temp->item);    
        } 
}
/*This function is used so it can pass the front of the list to the mergesort.
The mergesort takes a node.Instead of using this function,
I just gave mergesort the front of the list to make it easier.*/
/*void fakesort(pLinkedList list)
{
	list->front = mergesort(list->front);
}*/

/*In the mergesort I give the front of the list first so it can iterate through the list.
I first check to see if the list is empty or not. Then I give left and right hte front of the list 
and the next node after it. Now comes the iteration, I say if the right node which is next not equal 
to null or the next node is null. I make order equal to the previos node and make right the next next node. after 
the orginal possion After that call the merge sort 3 times to check the left and right and then return the string 
character back */
pNode mergesort(pNode order)
{	
	
	pNode left, right;
	if(order == NULL || order->next == NULL)
	{
		return order;
	} 
	left = order; 
	right = order->next;

	while((right != NULL) && (right->next != NULL))
	{
		order = order->next; 
		right = right->next->next;
	} 
	right = order->next;
	order->next = NULL;
	
	return (merge(mergesort(left), mergesort(right)));
}
/*In the merge sort, we create a head and c of pNode type, We check the left right and until its null.
Each time it checks, I call the function less to determine if left is less or equal to right. If it returns less than 0 then it changes 
the order. if its equal then it will keep going with the right.*/
pNode merge(pNode left, pNode right)
{
	Node head; 
	pNode c = &head;
	while(left != NULL && right !=NULL)
	{
		if(less(left->item, right->item) < 0 )
		{
			c->next = left; 
			c = left;
			left = left->next;
		}
		else
		{
			c->next = right;
			c = right;
			right = right->next;
		}
		
	}
	c->next = (left == NULL) ? right : left;
	//After the iteration is done, I return the head of the next,
	return head.next;
}
