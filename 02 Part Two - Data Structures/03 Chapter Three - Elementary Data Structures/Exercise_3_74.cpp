/* 
3.73 Write a function that uses the adjacency matrix of a graph to calculate,
given vertices a and b, the number of vertices c with the property that there is
an edge from a to c and from c to b.

3.74 Answer Exercise 3.73, but use adjacency lists.
*/

#include <iostream>
using namespace std;

struct node {
	int v;
	node* next;
	node (int x, node* t) {
		v = x;
		next = t;
	}
};

typedef node *link;

int linkNumber(link* adj, int V, int a, int b);
link* malloc_random_adjacency_list(int V);
void release_adjacency_list(link* adj, int V);
void print_adjacency_list(link* adj, int V);

int main() {
	link* list = malloc_random_adjacency_list(7);
	print_adjacency_list(list, 7);
	
	int a = 2;
	int b = 3;
	int cNumber = linkNumber(list, 7, a, b);
	cout << "a = " << a << " b = " << b << " number of c = " << cNumber << endl;
	
	release_adjacency_list(list, 7);

	return 0;
}

int linkNumber(link* adj, int V, int a, int b) {
	int count = 0;
	link x = adj[a];
	link y = nullptr;
	while (x != nullptr) {
		int s = x->v;
		y = adj[s];
		while (y != nullptr) {
			if (y->v == b) {
				count++;
			}
			y = y->next;
		}
		x = x->next;
	}

	return count;
}

link* malloc_random_adjacency_list(int V) {
	link *adj = new link[V];
	for (int i = 0; i < V; i++) {
		adj[i] = nullptr;
	}
	
	// Simulate Edges Input
	int count = V * V / 3;
	while (count > 0) {
		int i = rand() % V;
		int j = rand() % V;
		if (i != j) {
			adj[i] = new node(j, adj[i]);
		}
		count--;
	}
	
	return adj;
}

void release_adjacency_list(link* adj, int V) {
	link temp = nullptr;
	for (int i = 0; i < V; i++) {
		while (adj[i] != nullptr) {
			temp = adj[i];
			adj[i] = temp->next;
			delete temp;
			temp = nullptr;
		}
	}
	delete[] adj;
}

void print_adjacency_list(link* adj, int V) {
	link x = nullptr;
	for (int i = 0; i < V; i++) {
		x = adj[i];
		cout << "[" << i << "]";
		while (x != nullptr) {
			cout << x->v << " ";
			x = x->next;
		}
		cout << endl;
	}
}

/*
[0]2 5 6 
[1]3 0 
[2]4 1 6 
[3]
[4]3 5 3 
[5]
[6]2 2 
a = 2 b = 3 number of c = 3
*/
