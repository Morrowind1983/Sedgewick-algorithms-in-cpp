/*
4.5 Convert the list-processing interface in Section 3.4 (Program 3.12) into a
class-based ADT implementation, using a linked-list representation as in Program
3.14. Test your interface by modifying the client program, Program 3.13, to use
it, then switch to an array-based implementation (see Exercise 3.52).
*/

#include <iostream>
#include "List.h"
using namespace std;

int main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	Node* t;
	Node* x = new Node(1);
	for (i = 2; i <= N; i++) {
		t = new Node(i);
		x->insert(t);
		x = t;
	}
	while (x != x->next()) {
		for (i = 1; i < M; i++) {
			x = x->next();
		}
		delete x->removeNext();
	}
	cout << x->item() << endl;
	delete x;

	return 0;
}
