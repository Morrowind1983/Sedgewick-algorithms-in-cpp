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

void reverse(link);
link create_random_list(int);
void release_list(link&);
void print_list(link);

int main() {
	link head = create_random_list(30);
	print_list(head);
	
	reverse(head);
	print_list(head);
	
	release_list(head);
}

void reverse(link head) {
	if (head == nullptr) {
		return;
	}
	link t = head->next;
	link tp = nullptr;
	link tn = nullptr;
	while (t != nullptr) {
		tn = t->next;
		t->next = tp;
		tp = t;
		t = tn;
	}
	head->next = tp;
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

/*
0->335->816->278->99->933->560->157->709->169->303->612->840->729->327->503->98
7->42->492->165->440->709->923->878->544->272->930->658->73->249->807->(nullptr
)
0->807->249->73->658->930->272->544->878->923->709->440->165->492->42->987->503
->327->729->840->612->303->169->709->157->560->933->99->278->816->335->(nullptr
)
*/
