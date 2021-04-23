typedef int Item;
typedef struct node Node,* pNode;
struct node
{
  Item item;
  pNode next;
};

struct linkedlist
{
  pNode front;
  int size;
  pNode back;
  
};

typedef struct linkedlist LinkedList, *pLinkedList;

pLinkedList linkedlistInitDefault();
void linkedlistAddNodeBack(pLinkedList list, Item item);
Item linkedlistRemoveNodeFront(pLinkedList list);                   
void linkedlistDestroy(pLinkedList * list);
int linkedlistGetSize(pLinkedList list);
