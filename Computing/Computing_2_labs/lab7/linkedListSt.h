
struct book
{
  char * bookName;
  char * authorName;
};


typedef struct book Book,* pBook;
typedef struct node Node,* pNode;



/**
   Linkedlist node
*/
struct node
{
  Book item;
  pNode next;
};
/**
   Struct representing a linkedlist with
   holding only the front node of the 
   linkedlist
   front: the front node of the linkedlist
   size: the number of nodes in the linkedlist
*/
struct linkedlist
{
  pNode front;
  int size;
};


typedef struct linkedlist LinkedList, *pLinkedList;


/**
   Initializing the linkedlist
   Returning the address of the created linkedlist
*/
pLinkedList linkedlistInitDefault();
/**
   Returning the number of items in the linkedlist
 */
int linkedlistGetSize(pLinkedList list);
/**
   Adding a new item to the linkedlist
 */
void linkedlistAddNodeBack(pLinkedList list, Book item);
/**
   Destroying all the nodes in the linkedlist
 */
void linkedlistDestroy(pLinkedList *list);
/**
   Returning the item at a cetain index ( node number)
   in the linkedlist
 */
Book getBookatIndex(pLinkedList list, int index);

pLinkedList loadBookInfo(char *fileName);
void destroyBookInfo(pLinkedList);
void destroyBookStruct(pNode);
