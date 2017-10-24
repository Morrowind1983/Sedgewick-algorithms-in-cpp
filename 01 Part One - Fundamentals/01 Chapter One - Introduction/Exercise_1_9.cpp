/*
1.9 Prove an upper bound on the number of machine instructions required to
process M connections on N objects using Program 1.3. You may assume, for
example, that any C++ assignment statement always requires less than c
instructions, for some fixed constant c.
*/

#include <iostream>
#include <random>
using namespace std;

static const int M = 100000;
static const int N = 1024;

int weighted_quick_union(int ps[], int qs[], int m);

int main() {
    random_device rd;
    mt19937 random_number_engine(rd());
	uniform_int_distribution<> dis(0, N - 1);
	
	cout << "M = " << M << " N = " << N << endl;
	cout << "M * log2(N) = " << (int)(M * log2(N)) << endl;
	cout << "5 * M * log2(N) = " << (int)(5 * M * log2(N)) << endl;
	
	int ps[M] = {};
	int qs[M] = {};
	for (int n = 0; n < M; n++) {
		ps[n] = dis(random_number_engine);
		qs[n] = dis(random_number_engine);
	}
	int instructions = weighted_quick_union(ps, qs, M);
	cout << "random input instructions = " << instructions << endl;
	
	int id[N] = {};
	for (int i = 0; i < N; i++) {
		id[i] = i;
	}
	int p = 0;
	int next_p = 0;
	int max_p = N - 1;
	for (int n = 0; n < M; n++) {
		if (max_p == 0) {
			ps[n] = ps[n - 1];
			qs[n] = qs[n - 1];
			continue;
		}
		if (p + 1 > max_p) {
			id[next_p] = id[p];
			max_p = next_p;
			next_p = 0;
			p = 0;
			continue;
		}
		ps[n] = id[p];
		p++;
		qs[n] = id[p];
		p++;
		id[next_p] = qs[n];
		if (p > max_p) {
			max_p = next_p;
			next_p = 0;
			p = 0;
			continue;
		}
		next_p++;
	}
	instructions = weighted_quick_union(ps, qs, M);
	cout << "max input instructions = " << instructions << endl;
	
	return 0;
}

int weighted_quick_union(int ps[], int qs[], int m) {
	int i, j, p, q, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
	int instructions = 2;
	for (int idx = 0; idx < m; idx++) {
		instructions += 9;
		p = ps[idx];
		q = qs[idx];
		for (i = p; i != id[i]; i = id[i])
			instructions += 2;
		for (j = q; j != id[j]; j = id[j])
			instructions += 2;
		if (i == j)
			continue;
		instructions += 3;
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}
	return instructions;
}

/*
M = 100000 N = 1024
M * log2(N) = 1000000
5 * M * log2(N) = 5000000
random input instructions = 1669515
max input instructions = 4668249
*/