#include "pq.h"
#include <stdio.h>

int main()
{
  pPQ queue = pqInit(10);
  pqInsert(queue, 10);
  pqInsert(queue, 20);
  pqInsert(queue, 30);
  pqInsert(queue, -30);
  pqInsert(queue, -10);
  pqInsert(queue, 50);
  pqShow(queue);
  printf("max value %d \n", pqRemoveMax(queue));
  pqShow(queue);
  printf("max value %d \n", pqRemoveMax(queue));
  pqShow(queue);
  printf("Capacity: %d \n", pqGetCapacity(queue));
  return 0;
}
