/*
Program 3.12. List-processing interface

In this code, which we might keep in an interface file list.h, we define the
types of nodes and links, including the operations we want to perform on them.
We declare our own functions for allocating and freeing memory for list nodes.
The function construct is for the convenience of the implementation. These
definitions allow clients to use Nodes and associated operations without
dependence upon implementation details. As we shall see in Chapter 4, a
slightly different interface based on C++ classes can ensure that client
programs do not depend on implementation details.
*/

typedef int Item;

struct node { 
	Item item;
	node *next;
};

typedef node *link;
typedef link Node;

void construct(int);
Node newNode(Item);
void deleteNode(Node);
void insert(Node, Node);
Node remove(Node);
Node next(Node);
Item item(Node);
