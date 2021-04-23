typedef struct node Node,* pNode;
//This structure is creating a node. As in the item or information.
struct node
{
  //The item is the information that is stored into the node
  int item;
  //The next variable is the pointer in the linklist. To go to the 	next node, the cyntax is varaiblename->next
  pNode next;
};

//Ths structure is the linkedlist. Basically it creates the linklist linking the nodes together.
struct linkedlist
{
  //The front is the begining of the list. As in the the front or back 	  node of the linklist.
  //linklist depends on the first node to create newer nodes
  pNode front;
  int size;
  pNode iterator;
                                    
};

typedef struct linkedlist LinkedList, *pLinkedList;

pLinkedList linkedlistInitDefault();
int linkedlistGetSize(pLinkedList list);
void linkedlistAddNodeBack(pLinkedList list, int item);
//void linkedlistAddNodeFront(pLinkedList list, int item);
void linkedlistAddSortedNode(pLinkedList list, int item);                      
void linkedlistDestroy(pLinkedList *list);

