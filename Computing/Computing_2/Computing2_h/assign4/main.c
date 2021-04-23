#include<stdio.h>
#include"linkedListQueue.h"
#include"queueInterface.h"

int main(void)
{

  // Creating the linkedlist, adding nodes and removing them
  pLinkedList pList = linkedlistInitDefault();
  linkedlistAddNodeBack(pList, 10);
  linkedlistAddNodeBack(pList, 20);
  Item item = linkedlistRemoveNodeFront(pList);
  printf("item is: %d\n",item);
  item = linkedlistRemoveNodeFront(pList);
  printf("Second item is: %d\n",item);
  linkedlistDestroy(&pList);
  printf("%p\n",pList);

  return 0;
}
