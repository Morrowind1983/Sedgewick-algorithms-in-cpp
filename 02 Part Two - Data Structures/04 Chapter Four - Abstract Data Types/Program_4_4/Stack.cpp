/*
Program 4.7. Array implementation of a pushdown stack

When there are N items in the stack, this implementation keeps them in s[0],. .
.,s[N-1], in order from least recently inserted to most recently inserted. The
top of the stack (the position where the next item to be pushed will go) is
s[N]. The client program passes the maximum number of items expected on the
stack as the argument to the constructor for STACK, which allocates an array of
that size, but this code does not check for errors such as pushing onto a full
stack (or popping an empty one).
*/

#include "Stack.h"

template <class Item>
Stack<Item>::Stack(int max) {
	maxN = max;
	s = new Item[maxN];
	N = 0;
}

template <class Item>
bool Stack<Item>::empty() const {
	return N == 0;
}

template <class Item>
void Stack<Item>::push(Item item) {
	if (N < maxN) {
		s[N++] = item;
	}
}

template <class Item>
Item Stack<Item>::pop() {
	if (!empty()) {
		return s[--N];
	}
	return 0;
}