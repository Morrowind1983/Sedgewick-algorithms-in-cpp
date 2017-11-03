/*
Program 3.11. List insertion sort

This code generates N random integers between 0 and 999, builds a linked list
with one number per node (first for loop), and then rearranges the nodes so
that the numbers appear in order when we traverse the list (second for loop).
To accomplish the sort, we maintain two lists, an input (unsorted) list and an
output (sorted) list. On each iteration of the loop, we remove a node from the
input and insert it into position in the output. The code is simplified by the
use of head nodes for each list, that contain the links to the first nodes on
the lists. The declarations of the head nodes use the constructor, so that
their data members are initialized when they are created.
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

void release_list(link);
void print_list(link);

int main() {
	int N = 30;
	
	node heada = node(0, nullptr);
	link a = &heada;
	link itera = a;
	for (int i = 0; i < N; i++) {
		itera->next = new node(rand() % 1000, nullptr);
		itera = itera->next;
	}
	print_list(a);
	
	node headb = node(0, nullptr);
	link b = &headb;
	link iterb = b;
	link temp = nullptr;
	itera = a->next;
	while (itera != nullptr) {
		temp = itera->next;
		iterb = b;
		while (iterb->next != nullptr) {
			if (iterb->next->item > itera->item)
				break;
			iterb = iterb->next;
		}
		itera->next = iterb->next;
		iterb->next = itera;
		itera = temp;
	}
	a->next = nullptr;
	
	print_list(a);
	print_list(b);
	
	release_list(a);
	release_list(b);
}

void release_list(link head) {
	if (head == nullptr) {
		return;
	}
	link temp = nullptr;
	while (head->next != nullptr && head->next != head) {
		temp = head->next;
		head->next = temp->next;
		delete temp;
		temp = nullptr;
	}
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
