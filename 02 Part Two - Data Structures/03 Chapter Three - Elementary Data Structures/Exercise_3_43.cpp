/*
3.43 Implement a function that exchanges two given nodes on a doubly linked
list.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* prev;
	node* next;
	node(int x, node* p, node* n) {
		item = x;
		prev = p;
		next = n;
	}
};

typedef node *link;

void exchange(link, link);
node create_random_doubly_linked_list(int);
void release_list(node);
void print_doubly_linked_list(node);

int main() {
	node head = create_random_doubly_linked_list(30);
	print_doubly_linked_list(head);
	
	exchange(head.next->next, head.next->next->next->next);
	print_doubly_linked_list(head);
	
	release_list(head);
}

void exchange(link a, link b) {
	link ap = a->prev;
	link an = a->next;
	link bp = b->prev;
	link bn = b->next;
	a->prev = bp;
	a->next = bn;
	b->prev = ap;
	b->next = an;
	ap->next = b;
	an->prev = b;
	bp->next = a;
	bn->prev = a;
}

node create_random_doubly_linked_list(int length) {
	node head = node(0, nullptr, nullptr);
	link x = nullptr;
	link p = &head;
	while (length != 0) {
		x = new node(rand() % 1000, p, nullptr);
		p->next = x;
		p = x;
		length--;
	}
	return head;
}

void release_list(node head) {
	link t = nullptr;
	while (head.next != nullptr && head.next != &head) {
		t = head.next;
		head.next = t->next;
		delete t;
		t = nullptr;
	}
}

void print_doubly_linked_list(node head) {
	link x = head.next;
	cout << "(head)<=>";
	while (x != nullptr) {
		cout << x->item << "<=>";
		x = x->next;
		if (x == &head) {
			cout << x->item << "(head)" << endl;
			return;
		}
	}
	cout << "(nullptr)" << endl;
}

/*
(head)<=>807<=>249<=>73<=>658<=>930<=>272<=>544<=>878<=>923<=>709<=>440<=>165<=
>492<=>42<=>987<=>503<=>327<=>729<=>840<=>612<=>303<=>169<=>709<=>157<=>560<=>9
33<=>99<=>278<=>816<=>335<=>(nullptr)
(head)<=>807<=>658<=>73<=>249<=>930<=>272<=>544<=>878<=>923<=>709<=>440<=>165<=
>492<=>42<=>987<=>503<=>327<=>729<=>840<=>612<=>303<=>169<=>709<=>157<=>560<=>9
33<=>99<=>278<=>816<=>335<=>(nullptr)
*/