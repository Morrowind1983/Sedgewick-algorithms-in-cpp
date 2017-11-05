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
	node(int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node *link;

void exchange(link, link);
link create_random_list(int);
void release_list(link&);
void print_list(link);

int main() {
	link head = create_random_list(30);
	print_list(head);
	
	// exchange(head);
	print_list(head);
	
	release_list(head);
}

void exchange(link a, link b) {
	
}

link create_random_list(int length) {
	link head = nullptr;
	while (length != 0) {
		head = new node(rand() % 1000, head);
		length--;
	}
	return new node(0, head);
}

void release_list(link& head) {
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
	delete head;
	head = nullptr;
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
