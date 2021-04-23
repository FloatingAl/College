/**********************************************************************
	91.102 Assignment10
	Program: Priority queues 
	Author: Albara Mehene
	Date: 11/30/2015
	Time spent: 2.0 hours
	Purpose: Purpose of this is to now make a record that hold a key and the data from what is given.
***********************************************************************/
#include "pq.h"
#include "heap.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  
  pPQ queue = pqInit(10);
  pqInsert(queue, 10);
  pqInsert(queue, 50);
  pqInsert(queue, 80);
  pqInsert(queue, 70);
  pqInsert(queue, 90);
  pqInsert(queue, 65);
  pqShow(queue);
  printf("max value %d \n", pqRemoveMax(queue));
  pqShow(queue);
  printf("max value %d \n", pqRemoveMax(queue));
  pqShow(queue);
  printf("Capacity: %d \n", pqGetCapacity(queue));
  return 0;
}
