#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "pq.h"
#include "item.h"

void heapify(Record * arr, int index, int last)
{
  int left = 2 * index;
  int right = 2 * index + 1;
  int largest = index;
  
  //Used to be arr[left], > arr[index] now applying less function
  if(left <= last && less(arr[left].key,arr[index].key) == 0)
    largest = left;

  if(right <= last && less(arr[right].key,arr[largest].key) == 0)
    largest = right;

  if(largest != index)
    {
      int temp = arr[index].key;
      int tempdata = arr[index].data;
      arr[index].key = arr[largest].key;
      arr[index].data = arr[largest].data;
      arr[largest].key = temp;
      arr[largest].data = tempdata;
      
      heapify(arr, largest, last);
    }

}

void buildHeap(Record * arr, int first, int last)
{
  int size = last - first +1;
  int i;
  for(i = size/2 ; i >= 1 ; i--)
    {
      heapify(arr, i , last);
    }
  
}


void heapSort(Record * arr, int first, int last)
{
  buildHeap(arr, first, last);
  int size = last - first + 1;
  int i;
  for(i = size ; i > 1 ; i--)
    {
      int temp = arr[last].data;
      int tempkey = arr[last].key;
      arr[last].key = arr[first].key;
      arr[last].data = arr[first].data;
      arr[first].key = tempkey;
      arr[first].data = temp;
      last = last-1;
      heapify(arr, first, last);
    }
}
