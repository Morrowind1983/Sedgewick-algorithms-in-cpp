#include "random_queue.h"

#include <iostream>

using namespace std;

template <class Item>
RandomQueue<Item>::RandomQueue() {
	head_ = nullptr;
	size_ = 0;
}

template <class Item>
RandomQueue<Item>::~RandomQueue() {
	while (head_ != nullptr) {
		node* temp = head_;
		head_ = head_->next;
		delete temp;
		temp = nullptr;
	}
}

template <class Item>
bool RandomQueue<Item>::Empty() const {
	return size_ == 0;
}

template <class Item>
void RandomQueue<Item>::Push(Item item) {
	++size_;
	head_ = new node(item, head_);
}

template <class Item>
Item RandomQueue<Item>::Pop() {
	if (Empty()) {
		return 0;
	}
	node* temp = head_;
	Item item;
	int i = rand() % size_;
	if (i == 0) {
		item = temp->item;
		head_ = head_->next;
		delete temp;
		temp = nullptr;
	}
	else {
		while (i != 1) {
			temp = temp->next;
			--i;
		}
		node* drop = temp->next;
		item = drop->item;
		temp->next = drop->next;
		delete drop;
		drop = nullptr;
	}
	--size_;
	return item;
}

template <class Item>
void RandomQueue<Item>::Dump() {
	for (node* p = head_; p != nullptr; p = p->next) {
		cout << p->item << " ";
	}
	cout << endl;
}
