#include "random_queue.h"

#include <iostream>

using namespace std;

template <class Item>
RandomQueue<Item>::RandomQueue(int capacity) {
	array_ = new Item[capacity];
	tail_ = 0;
	size_ = 0;
	capacity_ = capacity;
}

template <class Item>
RandomQueue<Item>::~RandomQueue() {
	delete[] array_;
}

template <class Item>
bool RandomQueue<Item>::Empty() const {
	return size_ == 0;
}

template <class Item>
bool RandomQueue<Item>::Full() const {
	return size_ == capacity_;
}

template <class Item>
void RandomQueue<Item>::Push(Item item) {
	if (Full()) {
		return;
	}
	++size_;
	array_[tail_++] = item;
}

template <class Item>
Item RandomQueue<Item>::Pop() {
	if (Empty()) {
		return 0;
	}
	int i = rand() % size_;
	Item item = array_[i];
	array_[i] = array_[--tail_];
	--size_;
	return item;
}

template <class Item>
void RandomQueue<Item>::Dump() {
	for (int i = 0; i < tail_; ++i) {
		cout << array_[i] << " ";
	}
	cout << endl;
}
