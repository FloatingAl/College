/*************************************************
91.102 Assignment4
Program: QueueLinkList
Author: Albara Mehene
Date: 10/8/2015 9:05PM
Time spent: 1 hour
Purpose: The purpose of this code was implement a queue using what we
all ready have. We have already created the linklist, so we just 
just used parts of the linklist to create a queue.
*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "linkedListQueue.h"
#include "queueInterface.h"

int main(void)
{//Made a linklist of 10 spaces
  QUEUEinit(10);
//I put the numbers 20 and 30
  QUEUEput(20);
  QUEUEput(30);
  Item item = QUEUEget();
  printf("The first item is %d\n",item);
  //Add here other get and put to make sure that the queue works     correctly
  QUEUEput(10);
  item = QUEUEget();
  printf("The next item is %d\n",item);
	return 0;

}
