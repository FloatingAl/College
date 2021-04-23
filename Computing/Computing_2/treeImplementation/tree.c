#include <stdio.h>
#include "tree.h"

void postOrderTraversal(pBinaryNode node){
  if(node == NULL) return;
  postOrderTraversal(node->left);
  postOrderTraversal(node->right);
  printf("%d\n", node->item);
}

void preOrderTraversal(pBinaryNode node){
  if(node == NULL) return;
  printf("%d\n", node->item);
  preOrderTraversal(node->left);
  preOrderTraversal(node->right);
}

void inOrderTraversal(pBinaryNode node){
  if(node == NULL) return;
  inOrderTraversal(node->left);
  printf("%d\n", node->item);
  inOrderTraversal(node->right);
}
void destory(pBinaryNode node){
	
	if(node == NULL)
	{
		return;
	}
	destory(node->left);
	destory(node->right);
	free(node);


}
