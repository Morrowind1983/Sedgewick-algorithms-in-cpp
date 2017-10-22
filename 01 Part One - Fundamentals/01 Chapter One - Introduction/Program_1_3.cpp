/*
Program 1.3. Weighted version of quick union

This program is a modification to the quick-union algorithm (see Program 1.2)
that keeps an additional array sz for the purpose of maintaining, for each
object with id[i] == i, the number of nodes in the associated tree, so that
the union operation can link the smaller of the two specified trees to the
larger, thus preventing the growth of long paths in the trees.
*/

#include <iostream>
using namespace std;

static const int N = 10000;

int main() {
	int i, j, p, q, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
	while (cin >> p >> q) {
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (i == j)
			continue;
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
		cout << " " << p << " " << q << endl;
	}
	return 0;
}
