/**********************************************************************
	91.102 Assignment9
	Program: LinkedList MergeSort
	Author: Albara Mehene
	Date: 11/20/2015
	Time spent: 2.0 hours
	Purpose: Purpose of this code is be able to apply merge sort using a linklist with nodes.
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
	list->front = mergesort(list->front);
	linkedlistShow(list);
	linkedlistDestroy(&list);
	
	return 0;

}
