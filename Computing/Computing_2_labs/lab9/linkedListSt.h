
//TODO: add a struct member representing a member in
//your system

typedef struct Member Item;

struct Member
{
	char* name;
	char* username;
	int status;
};

/**
   Linkedlist node
*/
typedef struct node Node,*pNode;

struct node
{
  Item item;
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
void linkedlistAddNodeBack(pLinkedList list, Item item);
/**
   Destroying all the nodes in the linkedlist
 */
void linkedlistDestroy(pLinkedList *list);

int enterinfo(pLinkedList user);

int search(pLinkedList member, char* username);

int login(pLinkedList member, char* username);

int logout(pLinkedList member, char*username);

void show(pLinkedList member);
