/*
1.6 Give the contents of the id array after each union operation for the
weighted quick-union algorithm running on the examples corresponding to Figure
1.7 and Figure 1.8.
*/

#include <iostream>
using namespace std;

static const int N = 10;

void weighted_quick_union(int ps[], int qs[], int m);

int main() {
	cout << "Figure 1.7" << endl;
	int ps7[12] = {3, 4, 8, 2, 5, 2, 5, 7, 4, 5, 0, 6};
	int qs7[12] = {4, 9, 0, 3, 6, 9, 9, 3, 8, 6, 2, 1};
	weighted_quick_union(ps7, qs7, 12);
	
	cout << endl;
	cout << "Figure 1.8" << endl;
	int ps8[9] = {0, 2, 4, 6, 8, 1, 5, 3, 7};
	int qs8[9] = {1, 3, 5, 7, 9, 3, 7, 7, 9};
	weighted_quick_union(ps8, qs8, 9);
	
	return 0;
}

void weighted_quick_union(int ps[], int qs[], int m) {
	int i, j, p, q, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
	for (int idx = 0; idx < m; idx++) {
		p = ps[idx];
		q = qs[idx];
		cout << p << "-" << q;
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (i == j) {
			cout << endl;
			continue;
		}
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
		cout << endl;
	}
}

/*
Figure 1.7
3-4 id array = 0 1 2 3 3 5 6 7 8 9
4-9 id array = 0 1 2 3 3 5 6 7 8 3
8-0 id array = 8 1 2 3 3 5 6 7 8 3
2-3 id array = 8 1 3 3 3 5 6 7 8 3
5-6 id array = 8 1 3 3 3 5 5 7 8 3
2-9
5-9 id array = 8 1 3 3 3 3 5 7 8 3
7-3 id array = 8 1 3 3 3 3 5 3 8 3
4-8 id array = 8 1 3 3 3 3 5 3 3 3
5-6
0-2
6-1 id array = 8 3 3 3 3 3 5 3 3 3

Figure 1.8
0-1 id array = 0 0 2 3 4 5 6 7 8 9
2-3 id array = 0 0 2 2 4 5 6 7 8 9
4-5 id array = 0 0 2 2 4 4 6 7 8 9
6-7 id array = 0 0 2 2 4 4 6 6 8 9
8-9 id array = 0 0 2 2 4 4 6 6 8 8
1-3 id array = 0 0 0 2 4 4 6 6 8 8
5-7 id array = 0 0 0 2 4 4 4 6 8 8
3-7 id array = 0 0 0 2 0 4 4 6 8 8
7-9 id array = 0 0 0 2 0 4 4 6 0 8
*/