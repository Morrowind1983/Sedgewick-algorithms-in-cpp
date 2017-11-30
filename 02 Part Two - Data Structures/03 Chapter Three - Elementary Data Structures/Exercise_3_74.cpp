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

int linkNumber(int **adj, int V, int a, int b);
int** malloc_random_adjacency_matrix(int V);
void release_adjacency_matrix(int **adj, int V);
void print_adjacency_matrix(int **adj, int V);

int main() {
	int **matrix = malloc_random_adjacency_matrix(7);
	print_adjacency_matrix(matrix, 7);
	
	int a = 2;
	int b = 3;
	int cNumber = linkNumber(matrix, 7, a, b);
	cout << "a = " << a << " b = " << b << " number of c = " << cNumber << endl;
	
	release_adjacency_matrix(matrix, 7);

	return 0;
}

int linkNumber(int **adj, int V, int a, int b) {
	int count = 0;
	for (int i = 0; i < V; i++) {
		count += adj[a][i]*adj[i][b];
	}
	return count;
}

link* malloc_random_adjacency_matrix(int V) {
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

void release_adjacency_matrix(int **adj, int V) {
	for (int i = 0; i < V; i++) {
		delete[] adj[i];
	}
	delete[] adj;
}

void print_adjacency_matrix(int **adj, int V) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

/*
1 0 1 0 0 1 1 
1 1 0 1 0 0 0 
0 1 0 0 1 0 1 
0 0 0 0 0 0 0 
0 0 0 1 0 1 0 
0 0 0 0 0 0 0 
0 0 1 0 0 0 1 
a = 2 b = 3 number of c = 2
*/
