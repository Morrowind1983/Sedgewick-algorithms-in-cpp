/*
Program 3.10. List reversal

This function reverses the links in a list, returning a pointer to the final
node, which then points to the next-to-final node, and so forth, with the link in
the first node of the original list set to 0, the null pointer. To accomplish
this task, we need to maintain links to three consecutive nodes in the list.
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

link reverse(link);
void release_list(link&);
void print_list(link);

int main() {
	int N = 30;
	link head = new node(N, nullptr);
	for (int i = N - 1; i >= 1; i--) {
		head = new node(i, head);
	}
	print_list(head);
	link new_head = reverse(head);
	print_list(new_head);
	release_list(new_head);
}

link reverse(link head) {
	link t = nullptr, r = nullptr, x = head;
	while (x != nullptr) {
		t = x->next;
		x->next = r;
		r = x;
		x = t;
	}
	return r;
}

void release_list(link& x) {
	if (x == nullptr) {
		return;
	}
	link temp = nullptr;
	while (x->next != nullptr && x->next != x) {
		temp = x->next;
		x->next = temp->next;
		delete temp;
		temp = nullptr;
	}
	delete x;
	x = nullptr;
}

void print_list(link head) {
	link x = head;
	while (x != nullptr) {
		cout << x->item << "->";
		x = x->next;
		if (x == head) {
			cout << x->item << "(head)" << endl;
			return;
		}
	}
	cout << "(nullptr)" << endl;
}
