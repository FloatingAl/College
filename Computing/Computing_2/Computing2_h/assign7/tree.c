#include<stdlib.h>
#include <stdio.h>
#include "tree.h"


typedef struct binaryNode BinaryNode, *pBinaryNode;

struct binaryNode
{
  Item item;
  pBinaryNode left, right;
};

struct binaryTree
{
  pBinaryNode root;
};

typedef struct binaryTree BinaryTree;

/**
   Function: nodeTreeTraverse
   pre: the node representing the root of a tree
   post: none
   This is an internal function cannot be seen 
   by the client. The function recursively traverse
   the tree
 */
void nodeTreeTraverse(pBinaryNode pNode);
//Implementing a test function just returning a test tree
hBinaryTree testInit()
{
  hBinaryTree pTree = malloc(sizeof(BinaryTree));
  pTree->root = NULL;

  //Allocating the root
  pTree->root = malloc(sizeof(BinaryNode));
  //Check here if node was allocated
  
  //Creating a tree of only one node
  pTree->root->left = NULL;
  pTree->root->right = NULL;
  pTree->root->item = 1;

  pTree->root->left = malloc(sizeof(BinaryNode));
  pTree->root->right = malloc(sizeof(BinaryNode));
  pTree->root->right->left = NULL;
  pTree->root->right->right = NULL;
  pTree->root->right->item = 3;
  
  pTree->root->left->item = 2;
  pTree->root->left->left = malloc(sizeof(BinaryNode));
  pTree->root->left->left->left = NULL;
  pTree->root->left->left->right= NULL;
  pTree->root->left->left->item = 4;

  pTree->root->left->right = malloc(sizeof(BinaryNode));
  pTree->root->left->right->left = NULL;
  pTree->root->left->right->right = NULL;
  pTree->root->left->right->item = 5;


  return pTree;
}

void treeTraverse(hBinaryTree pTree)
{
  nodeTreeTraverse(pTree->root);
}
//prints out the nodes in the tree
void nodeTreeTraverse(pBinaryNode pNode)
{
  if(pNode == NULL)
    return;
  nodeTreeTraverse(pNode->left);
  nodeTreeTraverse(pNode->right);
  printf("%d\n", pNode->item);
}
//Delcared NodetreeCount for the treeCount to be private
int NodetreeCount(pBinaryNode pNode);
//Now treeCount will call NodetreeCount
int treeCount(hBinaryTree pTree)
{	//Giving Nodetee the root
	NodetreeCount(pTree->root);
}
int NodetreeCount(pBinaryNode pNode)
{       //This checks if the root is null
	if(pNode == NULL) 
	{
		return 0;
	}	
//I then return the number of nodes by adding from the left and right and adding 1
//Adding 1 if because of the logarthimc formula for example: ln(8) /ln(2) +1
return NodetreeCount(pNode->left) + NodetreeCount(pNode->right) + 1;
		
}
//Same deal with the count I am declerating a function to make the orginal private
int NodetreeHeight(pBinaryNode pNode);
//orginal calling decoy function
int treeHeight(hBinaryTree pTree)
{
	NodetreeHeight(pTree->root);
}
 
int NodetreeHeight(pBinaryNode pNode)
{
	//created two variables 
	int u, v;
	//checks to see if the root/node is NUll
	if(pNode == NULL) 
	{	
		return -1;
	}
	//I then have u hold the value of the left node
	u = NodetreeHeight(pNode->left); 
	//The v variable is holding the right variable
	v= NodetreeHeight(pNode->right);
	//This loop is to return u or v adding 1 to find the height 
	if( u > v)
	{
		return u+1;
	}
	else
	{
		return v+1;
	}


}
