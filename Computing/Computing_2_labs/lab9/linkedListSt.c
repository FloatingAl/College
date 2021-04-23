#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListSt.h"

pLinkedList linkedlistInitDefault()
{
  pLinkedList list = malloc(sizeof(LinkedList));
  list->front = NULL;
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
	      free(current->item.username);
	      free(current->item.name);
	      free(current);
	      current = next;  
	    }
	  printf("setting the list to null\n");
	  free((*list));
	  (*list) = NULL;
	}
      
    }

}
/*For the enter info, it is basically a function for the user to enter as many names and usernames. I created two char arrays to store the strings. After that I would called the search function. If the username is succesful, it will malloc space for the name and username. THen it will store it into the node. and add a node to the list. returning 1*/
int enterinfo(pLinkedList user)
{
	pNode current = user->front;
	Item info;
	int repeat = 1;
	int i = 1;
	char nametemp[30];
	char usertemp[30];
	
	
		printf("Enter your name: ");
		scanf(" %s",nametemp);
		printf("\nThe username must be unique\n");
		printf("Enter your user name: ");
		scanf(" %s",usertemp);
		if(search(user, usertemp))
		{
			info.name = malloc(30*sizeof(char));
			info.username = malloc(30*sizeof(char));
			strcpy(info.name, nametemp);
			strcpy(info.username, usertemp);
			info.status = 0;
			linkedlistAddNodeBack(user,info);
			return 1;
		}
		return 0;
	
	
}
/*In the search function, It is used to find the unique username. It will go through the list to find if the username is not taken or not. If it is succesful, it will return return 1. Telling the userinfo function to continue. */
int search(pLinkedList member, char*username)
{
	pNode current = member->front;
	int i;
	while(current != NULL)
	    {
	      	i = strcmp(username,current->item.username);
		if(i == 0)
			return 0;
	      	current = current->next;
	    }
	return 1;
}
/*In the login function, I create a node so it iterate through the list. While is it checking the username, I am having the the status in the node. So basically what the status is that if the status of a username is 1 it is succesfully loged in. If it is 0 then the user is offline. Anything else will return -1 and would indicated that the person is already online. */
int login(pLinkedList member, char* username)
{
	pNode current = member->front;
	while(current != NULL)
	{
		if(strcmp(username,current->item.username) == 0)
		{
			if(current->item.status == 0){			
				current->item.status = 1;
				return 1;
			}
			else
			  return -1;
		}

		current = current->next;
	}
		
	 return 0;
}
/*For the logout function, It is basically the same as the login function but instead we are looking for 0 to set the person to logout. Anything else will indicate that*/
int logout(pLinkedList member, char*username)
{
	pNode current = member->front;
	while(current != NULL)
	{
		if(strcmp(username,current->item.username) == 0)
		{
			if(current->item.status == 1){
				current->item.status = 0;
				return 1;
			}
			else
			{
				return -1;
			}
		}
		current = current->next;
	}
         return 0;
}
/*For the show function, its basically going through the list and seeing who is currently online and offline.*/
void show(pLinkedList member)
{
	pNode current = member->front;
	
	while(current != NULL)
	{
		printf("\n");
		printf("Name: %s\n",current->item.name);
		printf("Username: %s\n", current->item.username);
		printf(current->item.status == 1 ? "Online" : "Offline");
		current = current->next;
		printf("\n");
	}
}

