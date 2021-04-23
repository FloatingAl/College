/*******************************************************
	91.102 Assignment7
	Program: Trees (treeClient.c, tree.c, tree.h)
	Author: Albara Mehene
	Date: 10/26/2015
	Time spent: 1 hour
	Purpose: The purpose of this program is to count the amount nodes in the tree and figure out what the height is.
********************************************************/
#include <stdio.h>
#include "tree.h"

int main(void)
{
  hBinaryTree pTree = testInit();
 
 int count;
 int height;
 treeTraverse(pTree);
 //Have count equal to the return value of treeCount to print out
 count = treeCount(pTree);
 //Same with height
 height = treeHeight(pTree);


printf("The nodes are %d\n",count);
printf("The height is %d\n",height);
  return 0;
}
