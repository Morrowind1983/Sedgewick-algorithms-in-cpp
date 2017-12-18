/*
4.39 Modify the linked-list–based FIFO queue implementation in the text
(Program 4.14) to call a function error() if the client attempts to get when
the queue is empty or if there is no memory available from new for a put.
*/

#include "queue.h"

#include <iostream>

using namespace std;

template <class Item>
Queue<Item>::Queue() {
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}

template <class Item>
Queue<Item>::~Queue() {
	while (!Empty()) {
		Get();
	}
}

template <class Item>
bool Queue<Item>::Empty() const {
	return size_ == 0;
}

template <class Item>
void Queue<Item>::Put(Item item) {
	try {
		node* old_tail = tail_;
		tail_ = new node(item, nullptr);
		if (head_ == nullptr) {
			head_ = tail_;
		}
		else {
			old_tail->next = tail_;
		}
		++size_;
	}
	catch (const bad_alloc& e) {
		Error();
	}
}

template <class Item>
Item Queue<Item>::Get() {
	if (Empty()) {
		Error();
		return 0;
	}
	Item item = head_->item;
	node* new_head = head_->next;
	delete head_;
	head_ = new_head;
	--size_;
	return item;
}

template <class Item>
void Queue<Item>::Error() {
	cout << "error!" << endl;
}
