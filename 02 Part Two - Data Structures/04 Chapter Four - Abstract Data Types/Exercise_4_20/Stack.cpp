/*
Program 4.8. Linked-list implementation of a pushdown stack

This code implements the pushdown stack ADT using a linked list. The data
representation for linked-list nodes is organized in the usual way (see Chapter
3), and includes a constructor for nodes that fills in each new node with the
given item and link.
*/

#include "Stack.h"

template <class Item>
Stack<Item>::Stack() {
	head = nullptr;
}

template <class Item>
bool Stack<Item>::empty() const {
	return head == nullptr;
}

template <class Item>
void Stack<Item>::push(Item item) {
	head = new node(item, head);
}

template <class Item>
Item Stack<Item>::pop() {
	if (!empty()) {
		Item x = head->item;
		node* t = head;
		head = head->next;
		delete t;
		t = nullptr;
		return x;
	}
	return 0;
}

template <class Item>
Item Stack<Item>::top() {
	if (!empty()) {
		return head->item;
	}
	return 0;
}
