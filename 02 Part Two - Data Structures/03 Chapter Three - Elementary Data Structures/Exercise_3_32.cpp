/*
3.32 Develop a version of Program 3.9 that uses an array of indices to
implement the linked list (see Figure 3.6).
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	int *item = new int[N];
	int *next = new int[N];
	for (i = 0; i < N; i++) {
		item[i] = i + 1;
		next[i] = i + 1;
	}
	next[N - 1] = 0;
	int p = N - 1;
	while (next[p] != p) {
		for (i = 0; i < M - 1; i++)
			p = next[p];
		next[p] = next[next[p]];
	}
	cout << item[p] << endl;
	delete [] item;
	delete [] next;
}
