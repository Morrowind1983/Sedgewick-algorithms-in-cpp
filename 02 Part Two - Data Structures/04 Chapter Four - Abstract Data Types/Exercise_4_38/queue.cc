#include "queue.h"

#include <iostream>

using namespace std;

template <class Item>
Queue<Item>::Queue(int capacity) {
	queue_ = new Item[capacity];
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	capacity_ = capacity;
}

template <class Item>
Queue<Item>::~Queue() {
	delete[] queue_;
}

template <class Item>
bool Queue<Item>::Empty() const {
	return size_ == 0;
}

template <class Item>
void Queue<Item>::Put(Item item) {
	if (size_ == capacity_) {
		return;
	}
	++size_;
	queue_[tail_++] = item;
	tail_ = tail_ % capacity_;
}

template <class Item>
Item Queue<Item>::Get() {
	if (Empty()) {
		return 0;
	}
	--size_;
	head_ = head_ % capacity_;
	return queue_[head_++];
}
