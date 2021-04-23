#include <stdio.h>
#include <stdlib.h>
#include "linkedListSt.h"
#include <string.h>

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

void linkedlistAddNodeBack(pLinkedList list,Book item)
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
	      destroyBookStruct(current);
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

Book getBookatIndex(pLinkedList list, int index)
{
  int i;
  if(index > list->size)
    exit(1);

  pNode current = list->front;
  for(i = 0 ; i < index ; i++)
    current = current->next;
  return current->item;
}
pLinkedList loadBookInfo(char *fileName)
{
    //calling this function to create the linklist to begin with.
    pLinkedList list = linkedlistInitDefault();
   //I am opening the file right now
    FILE *fp;
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Can not open the file %s\n", fileName);
        return 0;
    }
  //made a variable called books that represents the struct
  Book books;
  int i;
  //malloced 55 space for buffer so it can store lines of the file.
  char *buffer = malloc(sizeof(char)*55);
  char *temp;
  int length;
 
  //This for loop to go through the list 55 times inserting the strings in the linklist
  for(i = 0; i < 55; i++){
  //gets the first line of the file
  fgets(buffer,55,fp);
  //store the length of the first half of the line
  temp = strtok(buffer,",");
  //store it into length
  length = strlen(temp);
  //then I malloced the same amount of space for the first half of the line
  books.bookName = malloc(length*sizeof(char));
  //Storing into bookname
  strcpy(books.bookName, temp);
  //store the other half of the line
  temp = strtok(NULL,",");
  //store it into length
  length = strlen(temp);
  //Then store into authorname for the rest 
  books.authorName = malloc(length*sizeof(char));
  //store it into authorNamenow
  strcpy(books.authorName, temp);
  //After that, it creates a node for that string
  linkedlistAddNodeBack(list, books);
  //then stores is into the index in the linklist
  Book books2 = getBookatIndex(list, i);
  //this prints ut out
  printf("%s\n",books2.bookName);
  printf("%s\n",books2.authorName);
    }
  //closing the file and freeing what I malloced and returning the list
  fclose(fp);
  free(buffer);
  return list;
}
void destroyBookInfo(pLinkedList list)
{
	//Im giving destroy Book the front of the list
	destroyBookStruct(list->front);
        //Then im calling the list destroy destroy the list
	linkedlistDestroy(&list);		
}
void destroyBookStruct(pNode list)
{
	//Now I am freeing the structure and items in it also
        //freeing the authorname and bookname
	free(list->item.authorName);
	free(list->item.bookName);
	list->item.bookName = NULL;
	list->item.authorName = NULL;
	
}
