/*
3.49 Implement the interface in Program 3.12 using new and delete directly in
newNode and deleteNode, respectively.
*/

#include <iostream>
#include "List.h"
using namespace std;

void construct(int N) {
}

Node newNode(Item item) {
	Node n = new node(item, nullptr);
	n->next = n;
	return n;
}

void deleteNode(Node n) {
	delete n;
	n = nullptr;
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
