/*
3.26 Given pointers x and t to nodes on a circular list, write a code fragment
that moves the node following t to the position following the node following x
on the list.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;
	node (int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node *link;

link create_circular_list(int length);
void release_circular_list(link&);
void print_circular_list(link);

int main() {
	link first = create_circular_list(30);
	link x = first->next->next->next->next;
	link t = first->next->next;
	
	link temp = t->next;
	t->next = temp->next;
	
	temp->next = x->next->next;
	x->next->next = temp;
	
	print_circular_list(first);

	release_circular_list(first);
	temp = nullptr;
}

link create_circular_list(int length) {
	if (length <= 0) {
		return nullptr;
	}
	link first = new node(0, nullptr);
	first->next = first;
	link x = first;
	for (int i = 1; i < length; i++) {
		x = (x->next = new node(i, first));
	}
	return first;
}

void release_circular_list(link& p) {
	link temp = nullptr;
	while (p->next != nullptr && p->next != p) {
		temp = p->next;
		p->next = temp->next;
		delete temp;
		temp = nullptr;
	}
	delete p;
	p = nullptr;
}

void print_circular_list(link p) {
	link start = p;
	do {
		cout << p->item << "->";
		p = p->next;
	} while (p != start);
	cout << p->item << "(start)" << endl;
}

/*
0->1->2->4->5->3->6->7->8->9->10->11->12->13->14->15->16->17->18->19->20->21->2
2->23->24->25->26->27->28->29->0(start)
*/
