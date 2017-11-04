/*
Program 3.14. Implementation of list-processing interface

This program gives implementations of the functions declared in Program 3.12,
and illustrates a standard approach to allocating memory for fixed-size nodes.
We build a free list that is initialized to the maximum number of nodes that
our program will use, all linked together. Then, when a client program
allocates a node, we remove that node from the free list; when a client program
frees a node, we link that node in to the free list.

By convention, client programs do not refer to list nodes except by declaring
variables of type Node and using them as arguments to functions defined in the
interface, and nodes returned to client programs have self-links. These
conventions provide a measure of protection against referencing undefined
pointers and provide some assurance that the client is using the interface as
intended. In C++, we enforce such conventions by using classes with
constructors (see Chapter 4).
*/

#include <iostream>
#include "List.h"
using namespace std;

node *freelist;

void construct(int N) {
	freelist = new node[N + 1];
	for (int i = 0; i < N; i++) {
		freelist[i].next = &freelist[i + 1];
	}
	freelist[N].next = nullptr;
}

Node newNode(Item item) {
	Node x = remove(freelist);
	x->item = item;
	x->next = x;
	return x;
}

void deleteNode(Node n) {
	insert(freelist, n);
}

void insert(Node n, Node t) {
	t->next = n->next;;
	n->next = t;
}

Node remove(Node n) {
	Node t = n->next;
	n->next = t->next;
	return t;
}

Node next(Node n) {
	return n->next;
}

Item item(Node n) {
	return n->item;
}
