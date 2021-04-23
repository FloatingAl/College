#ifndef TREE_H
#define TREE_H

typedef int Item;
typedef struct binaryTree * hBinaryTree;

/**
   Function: testInit
   pre: none
   post: creates a sample binary tree to test 
   the correctness of the functions
 */
hBinaryTree testInit();
/**
   Function:treeTraverse
   pre: The tree to traverse
   post: printing the values inside the tree
   based on the tree traversal order
 */
void treeTraverse(hBinaryTree pTree);
/**
   Function: treeCount
   pre: the tree to count the number of nodes in it
   post: the number of nodes in the tree
 */
int treeCount(hBinaryTree pTree);
/**
   Function: treeHeight
   pre: the tree to calculate its height
   post: the height of the given tree
 */
int treeHeight(hBinaryTree pTree);

#endif
