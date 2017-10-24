/*
1.22 Modify Program 1.4 to generate random pairs of integers between 0 and N –
1 instead of reading them from standard input, and to loop until N – 1 union
operations have been performed. Run your program for N = 10^3, 10^4, 10^5, and
10^6 and print out the total number of edges generated for each value of N.
*/

#include <iostream>
#include <random>
using namespace std;

void weighted_quick_union_with_halving_path_compression(
	int ps[], int qs[], int M, int N);

int main() {
	random_device rd;
	mt19937 random_number_engine(rd());
	
	uniform_int_distribution<> dis(0, 99999);
	int ps[100000] = {};
	int qs[100000] = {};
	for (int j = 0; j < 100000; j++) {
		ps[j] = dis(random_number_engine);
		qs[j] = dis(random_number_engine);
	}
	weighted_quick_union_with_halving_path_compression(ps, qs, 100000, 100000);
	
	return 0;
}

void weighted_quick_union_with_halving_path_compression(
int ps[], int qs[], int M, int N) {
	int i, j, p, q, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
	int edges = 0;
	for (int idx = 0; idx < M; idx++) {
		p = ps[idx];
		q = qs[idx];
		cout << "[" << idx << "]" <<p << "-" << q;
		for (i = p; i != id[i]; i = id[i])
			id[i] = id[id[i]];
		for (j = q; j != id[j]; j = id[j])
			id[j] = id[id[j]];
		if (i == j) {
			cout << endl;
			continue;
		}
		edges++;
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
		cout << " edges = " << edges << endl;
	}
}

/*
[0]19413-97713 edges = 1
[1]47048-24186 edges = 2
[2]12774-26538 edges = 3
[3]56228-84999 edges = 4
[4]59912-56768 edges = 5
......
[99995]41202-3429 edges = 83849
[99996]55363-53414
[99997]83737-42084
[99998]16830-74295 edges = 83850
[99999]52429-17376
*/