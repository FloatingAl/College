/*************************************************
91.102 Assignment3
Program: LinkList(main.c,linkedListSt.h,linkedListSt.c)
Author: Albara Mehene
Date: 9/27/2015 1:24PM
Time spent: 2 hours
Purpose: The purpose of this code was I needed to create a function
that was to take a node and determine where to put it in the Linklist
from the order the LinkList is in.
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedListSt.h"

int main(void)
{

  pLinkedList list = linkedlistInitDefault();
  linkedlistAddSortedNode(list,10);
  linkedlistDestroy(&list);
  printf("%p\n",list);

  return 0;
}
