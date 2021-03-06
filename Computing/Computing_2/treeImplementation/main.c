#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
  pBinaryTree tree = malloc(sizeof(BinaryTree));
  tree->root = malloc(sizeof(BinaryNode));
  tree->root->left = NULL;
  tree->root->right = NULL;
  tree->root->item = 1;

  tree->root->left = malloc(sizeof(BinaryNode));
  tree->root->left->left = NULL;
  tree->root->left->right = NULL;
  tree->root->left->item = 2;

  tree->root->right = malloc(sizeof(BinaryNode));
  tree->root->right->left = NULL;
  tree->root->right->right = NULL;
  tree->root->right->item = 3;

  //  postOrderTraversal(tree->root);
  //  preOrderTraversal(tree->root);
  inOrderTraversal(tree->root);
  destroy(tree->root);
  return 0;
}


