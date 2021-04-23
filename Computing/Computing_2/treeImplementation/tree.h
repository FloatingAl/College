typedef int Data;
typedef struct binaryNode BinaryNode, * pBinaryNode;
typedef struct binaryTree BinaryTree, * pBinaryTree;

struct binaryNode{
  pBinaryNode left, right;
  Data item;
};

struct binaryTree{
  pBinaryNode root;
};

void postOrderTraversal(pBinaryNode);
void preOrderTraversal(pBinaryNode);
void inOrderTraversal(pBinaryNode);
void destory(pBinaryNode);

