#ifndef DEQUE_H__
#define DEQUE_H__

template <class Item>
class Deque {
public:
	Deque();
	~Deque();
	
	bool Empty() const;
	void PushBack(Item);
	void PushFront(Item);
	Item PopBack();
	Item PopFront();
	Item Back() const;
	Item Front() const;
	void Dump();
	
private:
	struct node {
		Item item;
		node* prev;
		node* next;
		node (Item x, node* p, node* t) {
			item = x;
			prev = p;
			next = t;
		}
	};
	node* head_;
	node* tail_;
	int size_;
};

#endif // DEQUE_H__
