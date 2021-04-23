#include <stdio.h>
#include <stdlib.h>

//The algorithm is obtained from the following link:
//http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Sorting/heapSort.htm
//the following is a direct implementation for the algorithm

void heapify(int * arr, int index, int last); 
void buildHeap(int * arr, int first, int last);
void heapSort(int * arr, int first, int last);

int main()
{
  int arr[10]= {0,4,20,10,1,5,19, -1, 0, 13};

  heapSort(arr, 1, 9);
  for(int i= 0 ; i < 10 ; i++)
    printf("%d\n", arr[i]);

  return 0;
}


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
