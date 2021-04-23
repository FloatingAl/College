#include <stdio.h>
#include <stdlib.h>
#include "heap.h"



void heapify(int * arr, int index, int last)
{
  int left = 2 * index;
  int right = 2 * index + 1;
  int largest = index;
  
  
  if(left <= last && arr[left] > arr[index])
    largest = left;

  if(right <= last && arr[right] > arr[largest])
    largest = right;

  if(largest != index)
    {
      int temp = arr[index];
      arr[index] = arr[largest];
      arr[largest] = temp;
      heapify(arr, largest, last);
    }

}

void buildHeap(int * arr, int first, int last)
{
  int size = last - first +1;
  for(int i = size/2 ; i >= 1 ; i--)
    {
      heapify(arr, i , last);
    }
  
}

void heapSort(int * arr, int first, int last)
{
  buildHeap(arr, first, last);
  int size = last - first + 1;
  for(int i = size ; i > 1 ; i--)
    {
      int temp = arr[last];
      arr[last] = arr[first];
      arr[first] = temp;
      last = last-1;
      heapify(arr, first, last);
    }
}
