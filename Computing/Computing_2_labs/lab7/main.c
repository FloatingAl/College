/**********************************************************************
Program: lab7 /Linklist strings
Author: Albara Mehene
Date: 10/8/2015
Time spent: 2 hours 
Purpose: The purpose of thie program is to store the strings in a filename and put it into a linklist

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedListSt.h"
#include <string.h>

int main(void)
{
  //created a temp to store the value of the return 
  pLinkedList temp;
  //malloced filename to store the person's name of the file	
  char *fileName;
  fileName = malloc(55*sizeof(char));
  printf("What is the file name ? ");
  scanf(" %s",fileName);
  //storing the return value of loadBookInfo
  temp = loadBookInfo(fileName);
  //giving destorybookinfo the return value of loadbookinfo
  destroyBookInfo(temp);
  printf("%p\n", temp);

  free(fileName);
 
  return 0;
}
