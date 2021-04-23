#include <stdio.h>
#include <stdlib.h>
#include "queueInterface.h"
#include "linkedListQueue.h"

static pLinkedList list;// I made a static of pLinkedlist list so it can be used and recongnized by the other functions

void QUEUEinit()//This function is to create the queue linked list
{
	/*I called the function, linkedlistInitDefault because we already have a function makes a linklist and creates the 
	front of the array*/
	list = linkedlistInitDefault();
}


int QUEUEempty()//This checks if the function is empty or not
{
	if(linkedlistGetSize(list) == 0)//I called the function get size because it creates the size of the linklist
	{//If it is empty it returns 1
		return 1;
	}
	return 0;//If not, it returns 0;
}

void QUEUEput(Item item)//This function adds a node into the queue.
{
	linkedlistAddNodeBack(list, item);/*I called the Addnode back, because we all ready have a function that 
	creates a node and adds it to the back. We just gave it the information and list that represents a queue.*/
	
}

Item QUEUEget()//This function goes to the linklist and takes whatever that was put in the list first and returns it to the client.
{
	
	if(!(QUEUEempty()))//I called the queue empty because If it wasn't empty I would cancle the program.
	{	
		Item temp;//created a temporary node
		temp = linkedlistRemoveNodeFront(list);// This function removes the front of the node
		return temp; //Then I return the node
	}
	else
	{
		return 0;
	}
}


