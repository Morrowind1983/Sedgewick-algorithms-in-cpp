/*
Program 4.8. Linked-list implementation of a pushdown stack

This code implements the pushdown stack ADT using a linked list. The data
representation for linked-list nodes is organized in the usual way (see Chapter
3), and includes a constructor for nodes that fills in each new node with the
given item and link.
*/

#include "Stack.h"
#include <iostream>
using namespace std;

template <class Item>
Stack<Item>::Stack() {
	head = nullptr;
	cnt = 0;
}

template <class Item>
bool Stack<Item>::empty() const {
	return head == nullptr;
}

template <class Item>
void Stack<Item>::push(Item item) {
	try {
		head = new node(item, head);
		cnt++;
	}
	catch (const bad_alloc& e) {
		error();
	}
}

template <class Item>
Item Stack<Item>::pop() {
	if (empty()) {
		error();
		return 0;
	}
	Item x = head->item;
	node* t = head;
	head = head->next;
	cnt--;
	delete t;
	t = nullptr;
	return x;
}

template <class Item>
Item Stack<Item>::top() const {
	if (!empty()) {
		return head->item;
	}
	return 0;
}

template <class Item>
int Stack<Item>::count() const {
	return cnt;
}

template <class Item>
void Stack<Item>::error() {
	cout << "error!" << endl;
}
