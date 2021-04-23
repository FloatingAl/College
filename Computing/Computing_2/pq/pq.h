#ifndef PQ_H
#define PQ_H

typedef int Item;

typedef struct pq * pPQ;

/**
   Initializing a PQ 
   Pre: size of the priority queue
   Post: the initialized priority queue
 **/
pPQ pqInit(int capacity);

/**
   Get the max capacity of the priority queue
 **/
int pqGetCapacity(pPQ);

/**
 Returning the Max element in the priority queue
 Pre: PQ
 Post: the Item with the max key. If the PQ is empty 
 terminate
 **/
Item pqGetMax(pPQ);
/**
   Removing the Max item from the priority queue
   Pre: PQ
   Post: Removing the Item with the Max key and 
   return it. If the Item does not exist, terminate
 **/
Item pqRemoveMax(pPQ);
/**
   Inserting a new Item to the PQ
   The PQ must be initialized before doing that
 **/
int pqInsert(pPQ,Item);

void pqShow(pPQ);

#endif
