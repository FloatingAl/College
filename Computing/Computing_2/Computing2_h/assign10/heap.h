#ifndef HEAP_H
#define HEAP_H
#include "pq.h"

void heapify(Record * arr, int index, int last);
void buildHeap(Record * arr, int first, int last);
void heapSort(Record * arr, int first, int last);

#endif
