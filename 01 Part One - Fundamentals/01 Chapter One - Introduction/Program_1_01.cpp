/*
Program 1.1. Quick-find solution to connectivity problem

This program reads a sequence of pairs of nonnegative integers less than N
from standard input (interpreting the pair p q to mean "connect object p to
object q") and prints out pairs representing objects that are not yet
connected. It maintains an array id that has an entry for each object, with
the property that id[p] and id[q] are equal if and only if p and q are
connected. For simplicity, we define N as a compile-time constant.
Alternatively, we could take it from the input and allocate the id array
dynamically (see Section 3.3).
*/

#include <iostream>
using namespace std;

static const int N = 10000;

int main() {
	int i, p, q, id[N];
	for (i = 0; i < N; i++)
		id[i] = i;
	while (cin >> p >> q) {
		int t = id[p];
		if (t == id[q])
			continue;
		for (i = 0; i < N; i++) {
			if (id[i] == t)
				id[i] = id[q];
		}
		cout << " " << p << " " << q << endl;
	}
	return 0;
}
