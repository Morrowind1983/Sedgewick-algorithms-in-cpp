/*
Program 3.18. Adjacency-matrix graph representation

This program reads a set of edges that define an undirected graph and builds an
adjacency-matrix representation for the graph, setting a[i][j] and a[j][i] to 1
if there is an edge fromitojorjtoiin the graph, or to 0 if there is no such edge.
The program assumes that the number of vertices V is a compile-time constant.
Otherwise, it would need to dynamically allocate the array that represents the
adjacency matrix (see Exercise 3.71).
*/

#include <iostream>
using namespace std;

static const int V = 100;

int main() {
	int i, j, adj[V][V];
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			adj[i][j] = 0;
		}
	}
	for (i = 0; i < V; i++) {
		adj[i][i] = 1;
	}
	while (cin >> i >> j) {
		adj[i][j] = 1;
		adj[j][i] = 1;
	}
	return 0;
}
