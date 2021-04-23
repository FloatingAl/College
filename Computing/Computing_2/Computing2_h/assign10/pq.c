#include "pq.h"
#include "heap.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct pq
{
  //the array of Items
  //Changed to array of records
  Record *arr;
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
  //changed type from int to Record
  queue->arr = malloc((capacity+1) * sizeof(Record));
 
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
  //Now that we have a record, we need to have it for key and data.
  queue->size++;
  queue->arr[queue->size].key = item;
  queue->arr[queue->size].data = item;
  buildHeap(queue->arr,1,queue->size);
  
  return -1;

}

void pqShow(pPQ queue)
{
  int i;
  for(i = 1 ; i <= queue->size ; i++)
    printf("%d\n", queue->arr[i].data);
}

Item pqGetMax(pPQ queue)
{
  
  if(queue->size != 0)
    return queue->arr[1].data;
  return 0;
}

Item pqRemoveMax(pPQ queue)
{
  if(queue->size != 0)
    {
      Item temp = queue->arr[1].data;
      queue->arr[1] = queue->arr[queue->size];
      queue->size--;
      heapify(queue->arr, 1, queue->size);
      return temp;
    }
  return -1;
}
