/*
3.24 Write a code fragment that determines the number of nodes that are
between the nodes referenced by two given pointers x and t to nodes on a
circular list.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;
	node (int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node *link;

link create_circular_list(int length);
void release_circular_list(link p);

int main() {
	link first = create_circular_list(30);
	link x = first->next->next->next->next->next;
	link t = first->next->next;
	int cnt = 0;
	bool connected = true;
	do {
		if (x == NULL) {
			connected = false;
			break;
		}
		x = x->next;
		cnt++;
	} while (x != t);
	if (connected) {
		cnt--;
		cout << "nodes between x and t: " << cnt << endl;
	}
	else {
		cout << "x and t are not connected" << endl;
	}
	release_circular_list(first);
}

link create_circular_list(int length) {
	if (length <= 0) {
		return NULL;
	}
	link first = new node(0, NULL);
	first->next = first;
	link x = first;
	for (int i = 1; i < length; i++) {
		x = (x->next = new node(i, first));
	}
	return first;
}

void release_circular_list(link p) {
	link temp = NULL;
	while (p->next != NULL && p->next != p) {
		temp = p->next;
		p->next = temp->next;
		delete temp;
	}
	delete p;
	p = NULL;
}

/*
nodes between x and t: 26
*/
