/*
1.4 Show the contents of the id array after each union operation when you
use the quick-find algorithm (Program 1.1) to solve the connectivity problem
for the sequence 0-2, 1-4, 2-5, 3-6, 0-4, 6-0, and 1-3. Also give the number
of times the program accesses the id array for each input pair.
*/

#include <iostream>
using namespace std;

static const int N = 10;

void quick_find(int ps[], int qs[], int m);

int main() {
	int ps[7] = {0, 1, 2, 3, 0, 6, 1};
	int qs[7] = {2, 4, 5, 6, 4, 0, 3};
	quick_find(ps, qs, 7);

	return 0;
}

void quick_find(int ps[], int qs[], int m) {
	int i, p, q, id[N];
	for (i = 0; i < N; i++)
		id[i] = i;
	for (int idx = 0; idx < m; idx++) {
		int times = 0;
		p = ps[idx];
		q = qs[idx];
		cout << p << "-" << q;
		times += 2;
		int pID = id[p];
		int qID = id[q];
		if (pID == qID) {
			cout << endl;
			continue;
		}
		cout << " id array =";
		for (i = 0; i < N; i++) {
			times++;
			if (id[i] == pID) {
				times++;
				id[i] = qID;
			}
			cout << " " << id[i];
		}
		cout << " accesses = " << times << endl;
	}
}

/*
0-2 id array = 2 1 2 3 4 5 6 7 8 9 accesses = 13
1-4 id array = 2 4 2 3 4 5 6 7 8 9 accesses = 13
2-5 id array = 5 4 5 3 4 5 6 7 8 9 accesses = 14
3-6 id array = 5 4 5 6 4 5 6 7 8 9 accesses = 13
0-4 id array = 4 4 4 6 4 4 6 7 8 9 accesses = 15
6-0 id array = 4 4 4 4 4 4 4 7 8 9 accesses = 14
1-3
*/