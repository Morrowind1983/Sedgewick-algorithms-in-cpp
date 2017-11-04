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

link move_largest_to_end(link);
link move_smallest_to_begin(link);
link rearrange_odd_even(link);

link create_random_list(int);
void release_list(link&);
void print_list(link);

int main() {
	link head = create_random_list(30);
	print_list(head);
	
	move_largest_to_end(head);
	print_list(head);
	
	move_smallest_to_begin(head);
	print_list(head);
	
	rearrange_odd_even(head);
	print_list(head);
	
	link t = head->next->next->next->next;
	link u = head->next->next;
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

link move_largest_to_end(link head) {
	link x = head;
	if (x == nullptr || x->next == nullptr) {
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

link move_smallest_to_begin(link head) {
	link x = head;
	if (x == nullptr || x->next == nullptr) {
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
	smallest_link_pre->next->next = head->next->next;
	head->next = smallest_link_pre->next;
	smallest_link_pre->next = t;
	return head;
}

link rearrange_odd_even(link head) {
	if (head == nullptr) {
		return head;
	}
	link odd_head = head->next;
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
