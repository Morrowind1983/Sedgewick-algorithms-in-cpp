/*
3.25 Write a code fragment that, given pointers x and t to two disjoint
circular lists, inserts the list pointed to by t into the list pointed to by x,
at the point following x.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;
	node (int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node *link;

link create_circular_list(int length);
void release_circular_list(link p);
void print_circular_list(link p);

int main() {
	link first = create_circular_list(30);
	link second = create_circular_list(60);
	link x = first->next->next->next->next;
	link t = second->next->next;
	
	link temp = x->next;
	x->next = t->next;
	t->next = temp;
	
	print_circular_list(first);

	release_circular_list(first);
	second = NULL;
	temp = NULL;
}

link create_circular_list(int length) {
	if (length <= 0) {
		return NULL;
	}
	link first = new node(0, NULL);
	first->next = first;
	link x = first;
	for (int i = 1; i < length; i++) {
		x = (x->next = new node(i, first));
	}
	return first;
}

void release_circular_list(link p) {
	link temp = NULL;
	while (p->next != NULL && p->next != p) {
		temp = p->next;
		p->next = temp->next;
		delete temp;
	}
	delete p;
	p = NULL;
}

void print_circular_list(link p) {
	link head = p;
	do {
		cout << p->item << "->";
		p = p->next;
	} while (p != head);
	cout << p->item << "(head)" << endl;
}

/*
0->1->2->3->4->3->4->5->6->7->8->9->10->11->12->13->14->15->16->17->18->19->20->
21->22->23->24->25->26->27->28->29->30->31->32->33->34->35->36->37->38->39->40->
41->42->43->44->45->46->47->48->49->50->51->52->53->54->55->56->57->58->59->0->1
->2->5->6->7->8->9->10->11->12->13->14->15->16->17->18->19->20->21->22->23->24->
25->26->27->28->29->0(head)
*/
