/*
Program 3.19. Adjacency-lists graph representation

This program reads a set of edges that define a graph and builds an
adjacency-matrix representation for the graph. An adjacency list for a graph is
an array of lists, one for each vertex, where the jth list contains a linked list
of the nodes connected to the jth vertex.
*/

#include <iostream>
using namespace std;

static const int V = 100;

struct node {
	int item;
	node *next;
	node (int i, node *t) {
		item = i;
		next = t;
	}
};

int main() {
	int i, j;
	node *adj[V];
	for (i = 0; i < V; i++) {
		adj[i] = nullptr;
	}
	while (cin >> i >> j) {
		adj[i] = new node(j, adj[i]);
		adj[j] = new node(i, adj[j]);
	}
	return 0;
}
