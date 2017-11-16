/*
3.49 Implement the interface in Program 3.12 using new and delete directly in
newNode and deleteNode, respectively.
*/

typedef int Item;

struct node { 
	Item item;
	node *next;
	node(int x, node* t) {
		item = x;
		next = t;
	}
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
