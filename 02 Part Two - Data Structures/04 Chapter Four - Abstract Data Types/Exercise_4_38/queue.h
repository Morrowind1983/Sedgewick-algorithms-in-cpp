#ifndef QUEUE_H__
#define QUEUE_H__

template <class Item>
class Queue {
public:
	Queue(int);
	~Queue();
	
	bool Empty() const;
	void Put(Item);
	Item Get();
	
private:
	Item* queue_;
	int head_;
	int tail_;
	int size_;
	int capacity_;
};

#endif // QUEUE_H__
