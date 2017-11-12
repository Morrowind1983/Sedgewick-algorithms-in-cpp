/*
3.40 Implement a version of Program 3.10 that uses a head node.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;
	node(int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node *link;

node reverse(node);
node create_random_list(int);
void release_list(node);
void print_list(node);

int main() {
	node head = create_random_list(30);
	print_list(head);
	
	head = reverse(head);
	print_list(head);
	
	release_list(head);
}

node reverse(node head) {
	link t = head.next;
	link tp = nullptr;
	link tn = nullptr;
	while (t != nullptr) {
		tn = t->next;
		t->next = tp;
		tp = t;
		t = tn;
	}
	head.next = tp;
	return head;
}

node create_random_list(int length) {
	link x = nullptr;
	while (length != 0) {
		x = new node(rand() % 1000, x);
		length--;
	}
	return node(0, x);
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

void print_list(node head) {
	link x = head.next;
	cout << "(head)->";
	while (x != nullptr) {
		cout << x->item << "->";
		x = x->next;
		if (x == &head) {
			cout << x->item << "(head)" << endl;
			return;
		}
	}
	cout << "(nullptr)" << endl;
}

/*
(head)->335->816->278->99->933->560->157->709->169->303->612->840->729->327->50
 3->987->42->492->165->440->709->923->878->544->272->930->658->73->249->807->(n
ullptr)
(head)->807->249->73->658->930->272->544->878->923->709->440->165->492->42->987
 ->503->327->729->840->612->303->169->709->157->560->933->99->278->816->335->(n
 ullptr)
*/
