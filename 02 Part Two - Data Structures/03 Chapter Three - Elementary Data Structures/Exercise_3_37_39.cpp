/*
3.37 Write a function that takes a link to a list as argument and returns a
link to a copy of the list (a new list that contains the same items, in the
same order).

3.38 Write a function that takes two arguments—a link to a list and a function
that takes a link as argument—and removes all items on the given list for
which the function returns a nonzero value.

3.39 Solve Exercise 3.38, but make copies of the nodes that pass the test and
return a link to a list containing those nodes, in the order that they appear
in the original list.
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
typedef int (*filter)(link);

link copy_list(link);
void filter_list(link, filter);
link new_filter_list(link, filter);
int is_odd(link);
int is_even(link);
int is_under_100(link);
	
link create_random_list(int);
void release_list(link&);
void print_list(link);

int main() {
	link head = create_random_list(30);
	print_list(head);
	
	link new_head = copy_list(head);
	print_list(new_head);
	
	filter_list(head, is_odd);
	print_list(head);
	
	filter_list(new_head, is_even);
	print_list(new_head);
	
	link small_head = new_filter_list(head, is_under_100);
	print_list(small_head);
	
	release_list(head);
	release_list(new_head);
	release_list(small_head);
}

link copy_list(link p) {
	if (p == nullptr) {
		return nullptr;
	}
	link x = p;
	link copy_p = new node(x->item, nullptr);
	link t = copy_p;
	while (x->next != nullptr) {
		x = x->next;
		t = (t->next = new node(x->item, nullptr));
	}
	return copy_p;
}

void filter_list(link head, filter f) {
	link x = head;
	while (x->next != nullptr) {
		if (f(x->next) != 0) {
			link t = x->next;
			x->next = t->next;
			delete t;
			t = nullptr;
		}
		else {
			x = x->next;
		}
	}
}

link new_filter_list(link head, filter f) {
	if (head == nullptr) {
		return nullptr;
	}
	link x = head->next;
	link new_head = new node(0, nullptr);
	link t = new_head;
	while (x != nullptr) {
		if (f(x) == 0) {
			t->next = new node(x->item, nullptr);
			t = t->next;
		}
		x = x->next;
	}
	return new_head;
}

int is_odd(link p) {
	if (p->item % 2 == 1) {
		return 0;
	}
	return 1;
}

int is_even(link p) {
	if (p->item % 2 == 0) {
		return 0;
	}
	return 1;
}

int is_under_100(link p) {
	if (p->item < 100) {
		return 0;
	}
	return 1;
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
