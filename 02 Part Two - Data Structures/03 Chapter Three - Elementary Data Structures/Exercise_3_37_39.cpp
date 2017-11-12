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

node copy_list(link);
void filter_list(node, filter);
node new_filter_list(node, filter);
int is_odd(link);
int is_even(link);
int is_under_100(link);
	
node create_random_list(int);
void release_list(node);
void print_list(node);

int main() {
	node head = create_random_list(30);
	print_list(head);
	
	node copy_head = copy_list(head.next->next);
	print_list(copy_head);
	
	filter_list(head, is_odd);
	print_list(head);
	
	filter_list(copy_head, is_even);
	print_list(copy_head);
	
	node small_head = new_filter_list(head, is_under_100);
	print_list(small_head);
	
	release_list(head);
	release_list(copy_head);
	release_list(small_head);
}

node copy_list(link p) {
	node head = node(0, nullptr);
	if (p == nullptr) {
		return head;
	}
	link x = p;
	link copy_p = new node(x->item, nullptr);
	link t = copy_p;
	while (x->next != nullptr) {
		x = x->next;
		t = (t->next = new node(x->item, nullptr));
	}
	head.next = copy_p;
	return head;
}

void filter_list(node head, filter f) {
	link x = &head;
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

node new_filter_list(node head, filter f) {
	link x = head.next;
	node new_head = node(0, nullptr);
	link t = &new_head;
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
(head)->335->816->278->99->933->560->157->709->169->303->612->840->729->327->5
03->987->42->492->165->440->709->923->878->544->272->930->658->73->249->807->(
nullptr)
(head)->816->278->99->933->560->157->709->169->303->612->840->729->327->503->9
87->42->492->165->440->709->923->878->544->272->930->658->73->249->807->(nullp
tr)
(head)->335->99->933->157->709->169->303->729->327->503->987->165->709->923->7
3->249->807->(nullptr)
(head)->816->278->560->612->840->42->492->440->878->544->272->930->658->(nullp
tr) (head)->99->73->(nullptr)
*/