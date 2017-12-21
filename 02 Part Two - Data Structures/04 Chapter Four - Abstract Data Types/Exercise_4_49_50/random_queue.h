#ifndef RANDOMQUEUE_H__
#define RANDOMQUEUE_H__

template <class Item>
class RandomQueue {
public:
	RandomQueue();
	~RandomQueue();
	
	bool Empty() const;
	void Push(Item);
	Item Pop();
	void Dump();
	
private:
	struct node {
		Item item;
		node* next;
		node (Item x, node* t) {
			item = x;
			next = t;
		}
	};
	node* head_;
	int size_;
};

#endif // RANDOMQUEUE_H__
