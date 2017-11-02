/*
3.27 When building the list, Program 3.9 sets twice as many link values as it
needs to because it maintains a circular list after each node is inserted.
Modify the program to build the circular list without doing this extra work.
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
	link x = new node(N, t);
	link c = x;
	for (i = N - 1; i >= 2; i--) {
		c = new node(i, c);
	}
	t->next = c;
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
