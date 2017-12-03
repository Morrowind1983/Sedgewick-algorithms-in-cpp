/*
4.5 Convert the list-processing interface in Section 3.4 (Program 3.12) into a
class-based ADT implementation, using a linked-list representation as in Program
3.14. Test your interface by modifying the client program, Program 3.13, to use
it, then switch to an array-based implementation (see Exercise 3.52).
*/

typedef int Item;

class Node {
private:
	Item m_item;
	Node *m_next;
public:
	Node(Item);
	void insert(Node*);
	Node* removeNext();
	Item item() const;
	Node* next() const;
};
