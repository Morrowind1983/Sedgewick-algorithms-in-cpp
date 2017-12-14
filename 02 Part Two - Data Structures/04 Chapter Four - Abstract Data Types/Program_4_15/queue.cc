#include "queue.h"

template <class Item>
Queue::Queue(int max) {
	queue_ = new Item[max];
	head_ = 0;
	tail_ = 0;
	count_ = 0;
	max_ = max;
}

template <class Item>
Queue::~Queue() {
	delete[] queue_;
}

template <class Item>
bool Queue::Empty() const {
	return count_ == 0;
}

template <class Item>
void Queue::Put(Item item) {
	if (count == max) {
		return;
	}
	++count_;
	++tail;
	if (tail > max - 1) {
		tail = 0;
	}
	queue_[tail] = item;
}

template <class Item>
Item Queue::Get() {
	if (Empty()) {
		return 0;
	}
	--count_;
	Item item = queue_[head];
	--head;
	if (head < 0) {
		head = max - 1;
	}
	return item;
}
