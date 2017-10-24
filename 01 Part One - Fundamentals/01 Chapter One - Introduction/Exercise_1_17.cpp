/*
1.17 Answer Exercise 1.4, but using the weighted quick-union algorithm with
full path compression (Exercise 1.16).

1.16 Show how to modify Program 1.3 to implement full path compression, where
we complete each union operation by making every node that we touch point to
the root of the new tree.
*/

#include <iostream>
using namespace std;

static const int N = 10;

void weighted_quick_union_with_full_path_compression(int ps[], int qs[], int m);

int main() {
	int ps[7] = {0, 1, 2, 3, 0, 6, 1};
	int qs[7] = {2, 4, 5, 6, 4, 0, 3};
	weighted_quick_union_with_full_path_compression(ps, qs, 7);
	
	return 0;
}

void weighted_quick_union_with_full_path_compression(int ps[], int qs[], int m) {
	int i, j, p, q, k, t, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
	for (int idx = 0; idx < m; idx++) {
		int times = 0;
		p = ps[idx];
		q = qs[idx];
		cout << p << "-" << q;
		times++;
		for (i = p; i != id[i]; i = id[i])
			times += 2;
		k = p;
		times++;
		while (k != id[k]) {
			times += 3;
			t = id[k];
			id[k] = i;
			k = t;
		}
		times++;
		for (j = q; j != id[j]; j = id[j])
			times += 2;
		k = q;
		times++;
		while (k != id[k]) {
			times += 3;
			t = id[k];
			id[k] = j;
			k = t;
		}
		if (i == j) {
			cout << " accesses = " << times << endl;
			continue;
		}
		times++;
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
		cout << " id array =";
		for (i = 0; i < N; i++) {
			cout << " " << id[i];
		}
		cout << " accesses = " << times << endl;
	}
}

/*
0-2 id array = 0 1 0 3 4 5 6 7 8 9 accesses = 5
1-4 id array = 0 1 0 3 1 5 6 7 8 9 accesses = 5
2-5 id array = 0 1 0 3 1 0 6 7 8 9 accesses = 10
3-6 id array = 0 1 0 3 1 0 3 7 8 9 accesses = 5
0-4 id array = 0 0 0 3 1 0 3 7 8 9 accesses = 10
6-0 id array = 0 0 0 0 1 0 3 7 8 9 accesses = 10
1-3 accesses = 14
*/