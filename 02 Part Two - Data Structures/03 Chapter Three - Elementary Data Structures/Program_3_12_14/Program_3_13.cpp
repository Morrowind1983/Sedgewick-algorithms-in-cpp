/*
Program 3.13. List allocation for the Josephus problem

This program for the Josephus problem is an example of a client program
utilizing the list-processing primitives declared in Program 3.12 and
implemented in Program 3.14.
*/

#include <iostream>
#include "List.h"
using namespace std;

int main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	Node t;
	construct(N);
	Node x = newNode(1);
	for (i = 2; i <= N; i++) {
		t = newNode(i);
		insert(x, t);
		x = t;
	}
	while (x != next(x)) {
		for (i = 1; i < M; i++)
			x = next(x);
		deleteNode(remove(x));
	}
	cout << item(x) << endl;
	deleteNode(x);
	return 0;
}
