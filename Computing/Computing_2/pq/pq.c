#include "pq.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

struct pq
{
  //the array of Items
  Item * arr;
  //the current number of elements
  int size;
  //Max number of elements pq can hold
  int capacity;
};

pPQ pqInit(int capacity)
{
  pPQ queue = malloc(sizeof(struct pq));
  if(queue == NULL)
    return NULL;
  
  queue->capacity = capacity;
  queue->arr = malloc((capacity+1) * sizeof(int));
 
 if(queue->arr == NULL)
   {
     free(queue);
    return NULL;
   }
 queue->size = 0;
 return queue;
}

int pqGetCapacity(pPQ queue)
{
  return queue->capacity;
}

int pqInsert(pPQ queue,Item item)
{
  if(queue == NULL)
      return -1;

  if(queue->size >= queue->capacity)
    {
      return -1;
    }
  //This is a heap tree, array start from location 1
  queue->size++;
  queue->arr[queue->size] = item;
  buildHeap(queue->arr,1,queue->size);
  
  return -1;

}

void pqShow(pPQ queue)
{
  for(int i = 1 ; i <= queue->size ; i++)
    printf("%d\n", queue->arr[i]);
}

Item pqGetMax(pPQ queue)
{
  if(queue->size != 0)
    return queue->arr[1];
  return 0;
}

Item pqRemoveMax(pPQ queue)
{
  if(queue->size != 0)
    {
      Item temp = queue->arr[1];
      queue->arr[1] = queue->arr[queue->size];
      queue->size--;
      heapify(queue->arr, 1, queue->size);
      return temp;
    }
  return -1;
}
