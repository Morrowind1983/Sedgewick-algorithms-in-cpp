#ifndef QUEUE_H__
#define QUEUE_H__

template <class Item>
class Queue {
public:
	Queue();
	~Queue();
	
	bool Empty() const;
	void Put(Item);
	Item Get();
	
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
	node* tail_;
	int count_;
};

#endif // QUEUE_H__
