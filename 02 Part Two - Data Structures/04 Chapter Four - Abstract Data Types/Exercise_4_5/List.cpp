/*
4.5 Convert the list-processing interface in Section 3.4 (Program 3.12) into a
class-based ADT implementation, using a linked-list representation as in Program
3.14. Test your interface by modifying the client program, Program 3.13, to use
it, then switch to an array-based implementation (see Exercise 3.52).
*/

#include <iostream>
#include "List.h"
using namespace std;

Node::Node(Item item) {
	this->m_item = item;
	this->m_next = this;
}

void Node::insert(Node* t) {
	t->m_next = this->m_next;;
	this->m_next = t;
}

Node* Node::removeNext() {
	Node* t = this->m_next;
	this->m_next = t->m_next;
	return t;
}

Item Node::item() const {
	return this->m_item;
}

Node* Node::next() const {
	return this->m_next;
}
