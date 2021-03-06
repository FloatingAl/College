/**********************************************************************
	91.102 Assignment8 part 2
	Program: LinkList Selection sort Part 2
	Author: Albara Mehene
	Date: 12/3/2015
	Time spent: 8 hours
	Purpose: Purpose of this code is to store as many strings and then apply selection sort for linklist.
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "linkedListSt.h"

int main(void)
{	
	pLinkedList list = linkedlistInitDefault();
	linkedlistScanInit(list); 
	linkedlistShow(list);
	//This is the insertion sort.
	printf("\n");
	linkedlistSort(list);
	linkedlistShow(list);
	linkedlistDestroy(&list);

	
	return 0;

}
