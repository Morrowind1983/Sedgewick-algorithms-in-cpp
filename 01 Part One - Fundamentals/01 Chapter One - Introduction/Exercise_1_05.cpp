/*
1.5 Do Exercise 1.4, but use the quick-union algorithm (Program 1.2).

1.4 Show the contents of the id array after each union operation when you use
the quick-find algorithm (Program 1.1) to solve the connectivity problem for
the sequence 0-2, 1-4, 2-5, 3-6, 0-4, 6-0, and 1-3. Also give the number of
times the program accesses the id array for each input pair.
*/

#include <iostream>
using namespace std;

static const int N = 10;

void quick_union(int ps[], int qs[], int m);

int main() {
	int ps[7] = {0, 1, 2, 3, 0, 6, 1};
	int qs[7] = {2, 4, 5, 6, 4, 0, 3};
	quick_union(ps, qs, 7);

	return 0;
}

void quick_union(int ps[], int qs[], int m) {
	int i, j, p, q, id[N];
	for (i = 0; i < N; i++)
		id[i] = i;
	for (int idx = 0; idx < m; idx++) {
		int times = 0;
		p = ps[idx];
		q = qs[idx];
		cout << p << "-" << q;
		times++;
		for (i = p; i != id[i]; i = id[i])
			times += 2;
		times++;
		for (j = q; j != id[j]; j = id[j])
			times += 2;
		if (i == j) {
			cout << " accesses = " << times << endl;
			continue;
		}
		times++;
		id[i] = j;
		cout << " id array =";
		for (i = 0; i < N; i++) {
			cout << " " << id[i];
		}
		cout << " accesses = " << times << endl;
	}
}

/*
0-2 id array = 2 1 2 3 4 5 6 7 8 9 accesses = 3
1-4 id array = 2 4 2 3 4 5 6 7 8 9 accesses = 3
2-5 id array = 2 4 5 3 4 5 6 7 8 9 accesses = 3
3-6 id array = 2 4 5 6 4 5 6 7 8 9 accesses = 3
0-4 id array = 2 4 5 6 4 4 6 7 8 9 accesses = 7
6-0 id array = 2 4 5 6 4 4 4 7 8 9 accesses = 9
1-3 accesses = 8
*/