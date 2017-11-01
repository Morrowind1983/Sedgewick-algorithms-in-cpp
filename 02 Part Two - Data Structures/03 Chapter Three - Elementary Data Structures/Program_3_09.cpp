/*
Program 3.9. Circular list example (Josephus problem)

To represent people arranged in a circle, we build a circular linked list, with a
link from each person to the person on the left in the circle. The integer i
represents the ith person in the circle. After building a one-node circular list
for 1, we insert 2 through N after that node, resulting in a circle with 1
through N, leaving x pointing to N. Then, we skip M - 1 nodes, beginning with 1,
and set the link of the (M - 1)st to skip the Mth, continuing until only one node
is left.
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

int main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	link t = new node(1, 0);
	t->next = t;
	link x = t;
	link c;
	for (i = 2; i <= N; i++)
		x = (x->next = new node(i, t));
	while (x != x->next) {
		for (i = 1; i < M; i++)
			x = x->next;
		c = x->next;
		x->next = c->next;
		delete c;
	}
	cout << x->item << endl;
	delete x;
}
