#include "deque.h"

#include <iostream>

using namespace std;

template <class Item>
Deque<Item>::Deque() {
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}

template <class Item>
Deque<Item>::~Deque() {
	while (!Empty()) {
		PopBack();
	}
}

template <class Item>
bool Deque<Item>::Empty() const {
	return size_ == 0;
}

template <class Item>
void Deque<Item>::PushBack(Item item) {
	++size_;
	node* old_tail = tail_;
	tail_ = new node(item, old_tail, nullptr);
	if (head_ == nullptr) {
		head_ = tail_;
	}
	else {
		old_tail->next = tail_;
	}
}

template <class Item>
void Deque<Item>::PushFront(Item item) {
	++size_;
	node* old_head = head_;
	head_ = new node(item, nullptr, old_head);
	if (tail_ == nullptr) {
		tail_ = head_;
	}
	else {
		old_head->prev = head_;
	}
}

template <class Item>
Item Deque<Item>::PopBack() {
	if (Empty()) {
		return 0;
	}
	--size_;
	Item item = tail_->item;
	node* new_tail = tail_->prev;
	delete tail_;
	if (new_tail == nullptr) {
		head_ = nullptr;
	}
	else {
		new_tail->next = nullptr;
	}
	tail_ = new_tail;
	return item;
}

template <class Item>
Item Deque<Item>::PopFront() {
	if (Empty()) {
		return 0;
	}
	--size_;
	Item item = head_->item;
	node* new_head = head_->next;
	delete head_;
	if (new_head == nullptr) {
		tail_ = nullptr;
	}
	else {
		new_head->prev = nullptr;
	}
	head_ = new_head;
	return item;
}

template <class Item>
Item Deque<Item>::Back() const {
	if (Empty()) {
		return 0;
	}
	return tail_->item;
}

template <class Item>
Item Deque<Item>::Front() const {
	if (Empty()) {
		return 0;
	}
	return head_->item;
}

template <class Item>
void Deque<Item>::Dump() {
	node* p = head_;
	while (p != nullptr) {
		cout << p->item << " ";
		p = p->next;
	}
	cout << endl;
}
