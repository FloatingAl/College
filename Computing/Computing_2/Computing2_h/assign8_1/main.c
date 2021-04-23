/**********************************************************************
	91.102 Assignment8 
	Program: LinkList Selection sort Part 1
	Author: Albara Mehene
	Date: 11/1/2015
	Time spent: 1.5 hours
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
	linkedlistDestroy(&list);
	
	return 0;

}
