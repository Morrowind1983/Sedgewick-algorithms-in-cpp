#include "deque.h"

#include <iostream>

using namespace std;

template <class Item>
Deque<Item>::Deque(int capacity) {
	array_ = new Item[capacity];
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	capacity_ = capacity;
}

template <class Item>
Deque<Item>::~Deque() {
	delete[] array_;
}

template <class Item>
bool Deque<Item>::Empty() const {
	return size_ == 0;
}

template <class Item>
bool Deque<Item>::Full() const {
	return size_ == capacity_;
}

template <class Item>
void Deque<Item>::PushBack(Item item) {
	if (Full()) {
		return;
	}
	++size_;
	array_[tail_++] = item;
	tail_ = tail_ % capacity_;
}

template <class Item>
void Deque<Item>::PushFront(Item item) {
	if (Full()) {
		return;
	}
	++size_;
	--head_;
	if (head_ < 0) {
		head_ = capacity_ - 1;
	}
	array_[head_] = item;
}

template <class Item>
Item Deque<Item>::PopBack() {
	if (Empty()) {
		return 0;
	}
	--size_;
	--tail_;
	if (tail_ < 0) {
		tail_ = capacity_ - 1;
	}
	return array_[tail_];
}

template <class Item>
Item Deque<Item>::PopFront() {
	if (Empty()) {
		return 0;
	}
	--size_;
	Item item = array_[head_];
	++head_;
	head_ = head_ % capacity_;
	return item;
}

template <class Item>
Item Deque<Item>::Back() const {
	if (Empty()) {
		return 0;
	}
	return array_[tail_];
}

template <class Item>
Item Deque<Item>::Front() const {
	if (Empty()) {
		return 0;
	}
	return array_[head_];
}

template <class Item>
void Deque<Item>::Dump() {
	int i = head_;
	while (i != tail_) {
		cout << array_[i++] << " ";
		i = i % capacity_;
	}
	cout << endl;
}
