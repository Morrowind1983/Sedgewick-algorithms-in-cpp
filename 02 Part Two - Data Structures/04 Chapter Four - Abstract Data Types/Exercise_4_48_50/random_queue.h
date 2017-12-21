#ifndef RANDOMQUEUE_H__
#define RANDOMQUEUE_H__

template <class Item>
class RandomQueue {
public:
	RandomQueue(int);
	~RandomQueue();
	
	bool Empty() const;
	bool Full() const;
	void Push(Item);
	Item Pop();
	void Dump();
	
private:
	Item* array_;
	int tail_;
	int size_;
	int capacity_;
};

#endif // RANDOMQUEUE_H__
