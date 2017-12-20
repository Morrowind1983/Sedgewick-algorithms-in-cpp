#ifndef DEQUE_H__
#define DEQUE_H__

template <class Item>
class Deque {
public:
	Deque(int);
	~Deque();
	
	bool Empty() const;
	bool Full() const;
	void PushBack(Item);
	void PushFront(Item);
	Item PopBack();
	Item PopFront();
	Item Back() const;
	Item Front() const;
	void Dump();
	
private:
	Item* array_;
	int head_;
	int tail_;
	int size_;
	int capacity_;
};

#endif // DEQUE_H__
