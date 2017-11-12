/*
3.33 Write a function that moves the largest item on a given list to be the
final node on the list.

3.34 Write a function that moves the smallest item on a given list to be the
first node on the list.

3.35 Write a function that rearranges a linked list to put the nodes in even
positions after the nodes in odd positions in the list, preserving the relative
order of both the evens and the odds.

3.36 Implement a code fragment for a linked list that exchanges the positions
of the nodes after the nodes referenced by two given links t and u.
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

node move_largest_to_end(node);
node move_smallest_to_begin(node);
node rearrange_odd_even(node);

node create_random_list(int);
void release_list(node);
void print_list(node);

int main() {
	node head = create_random_list(30);
	print_list(head);
	
	head = move_largest_to_end(head);
	print_list(head);
	
	head = move_smallest_to_begin(head);
	print_list(head);
	
	head = rearrange_odd_even(head);
	print_list(head);
	
	link t = head.next->next->next->next;
	link u = head.next->next;
	link tn = t->next;
	link un = u->next;
	link tnn = tn->next;
	link unn = un->next;
	tn->next = unn;
	un->next = tnn;
	t->next = un;
	u->next = tn;
	print_list(head);
	
	release_list(head);
}

node move_largest_to_end(node head) {
	link x = &head;
	if (x->next == nullptr) {
		return head;
	}
	link largest_link_pre = x;
	int largest_num = x->next->item;
	x = x->next;
	while (x->next != nullptr) {
		if (x->next->item > largest_num) {
			largest_num = x->next->item;
			largest_link_pre = x;
		}
		x = x->next;
	}
	link t = largest_link_pre->next->next;
	largest_link_pre->next->next = nullptr;
	x->next = largest_link_pre->next;
	largest_link_pre->next = t;
	return head;
}

node move_smallest_to_begin(node head) {
	link x = &head;
	if (x->next == nullptr) {
		return head;
	}
	link smallest_link_pre = x;
	int smallest_num = x->next->item;
	x = x->next;
	while (x->next != nullptr) {
		if (x->next->item < smallest_num) {
			smallest_num = x->next->item;
			smallest_link_pre = x;
		}
		x = x->next;
	}
	link t = smallest_link_pre->next->next;
	smallest_link_pre->next->next = head.next;
	head.next = smallest_link_pre->next;
	smallest_link_pre->next = t;
	return head;
}

node rearrange_odd_even(node head) {
	link odd_head = head.next;
	if (odd_head == nullptr) {
		return head;
	}
	link even_head = odd_head->next;
	if (even_head == nullptr) {
		return head;
	}
	link odd_x = odd_head;
	link even_x = even_head;
	while (true) {
		if (even_x->next == nullptr) {
			break;
		}
		odd_x->next = even_x->next;
		odd_x = odd_x->next;
		if (odd_x->next == nullptr) {
			even_x->next = nullptr;
			break;
		}
		even_x->next = odd_x->next;
		even_x = even_x->next;
	}
	odd_x->next = even_head;
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
(head)->335->816->278->99->933->560->157->709->169->303->612->840->729->327->5
03->987->42->492->165->440->709->923->878->544->272->930->658->73->249->807->(
nullptr)
(head)->335->816->278->99->933->560->157->709->169->303->612->840->729->327->5
03->42->492->165->440->709->923->878->544->272->930->658->73->249->807->987->(
nullptr)
(head)->42->335->816->278->99->933->560->157->709->169->303->612->840->729->32
7->503->492->165->440->709->923->878->544->272->930->658->73->249->807->987->(
nullptr)
(head)->42->816->99->560->709->303->840->327->492->440->923->544->930->73->807
->335->278->933->157->169->612->729->503->165->709->878->272->658->249->987->(
nullptr)
(head)->42->816->709->560->99->303->840->327->492->440->923->544->930->73->807
->335->278->933->157->169->612->729->503->165->709->878->272->658->249->987->(
nullptr)
*/