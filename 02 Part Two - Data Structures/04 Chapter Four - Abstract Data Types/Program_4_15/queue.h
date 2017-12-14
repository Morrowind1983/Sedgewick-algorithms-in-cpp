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
	int* queue_;
	int head_;
	int tail_;
	int count_;
	int max_;
};

#endif // QUEUE_H__
