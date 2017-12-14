#include "queue.h"

template <class Item>
Queue::Queue() {
	head_ = nullptr;
	tail_ = nullptr;
	count_ = 0;
}

template <class Item>
Queue::~Queue() {
	while (!Empty()) {
		Get();
	}
}

template <class Item>
bool Queue::Empty() const {
	return count_ == 0;
}

template <class Item>
void Queue::Put(Item item) {
	node* old_tail = tail_;
	tail_ = new node(item, nullptr);
	if (head_ == nullptr) {
		head_ = tail_;
	}
	else {
		old_tail->next = tail_;
	}
	++count_;
}

template <class Item>
Item Queue::Get() {
	if (Empty()) {
		return 0;
	}
	Item item = head->item;
	node* new_head = head_->next;
	delete head_;
	head_ = new_head;
	--count_;
	return item;
}
