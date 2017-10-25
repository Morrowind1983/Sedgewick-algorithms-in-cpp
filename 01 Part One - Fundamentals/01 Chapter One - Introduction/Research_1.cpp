#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

static const int M = 100000;
static const int N = 100000;

void quick_find(int ps[], int qs[], int m);
void quick_union(int ps[], int qs[], int m);
void weighted_quick_union(int ps[], int qs[], int m);
void weighted_quick_union_with_halving_path_compression(
	int ps[], int qs[], int m);
void weighted_quick_union_with_full_path_compression(
	int ps[], int qs[], int m);

int main() {
	random_device rd;
	mt19937 random_number_engine(rd());
	
	uniform_int_distribution<> dis(0, N - 1);
	int ps[M] = {};
	int qs[M] = {};
	for (int i = 0; i < M; i++) {
		ps[i] = dis(random_number_engine);
		qs[i] = dis(random_number_engine);
	}
	
	cout << "M = " << M << " N = " << N << endl; 
	
	steady_clock::time_point t1 = steady_clock::now();
	quick_find(ps, qs, M);
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "quick find " << time_span.count() << " seconds." << endl;
	
	t1 = steady_clock::now();
	quick_union(ps, qs, M);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "quick union " << time_span.count() << " seconds." << endl;
	
	t1 = steady_clock::now();
	weighted_quick_union(ps, qs, M);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "weighted quick union " << time_span.count() << " seconds." << endl;
	
	t1 = steady_clock::now();
	weighted_quick_union_with_halving_path_compression(ps, qs, M);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "weighted quick union with halving path compression " 
		<< time_span.count() << " seconds." << endl;
	
	t1 = steady_clock::now();
	weighted_quick_union_with_full_path_compression(ps, qs, M);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "weighted quick union with full path compression " 
		<< time_span.count() << " seconds." << endl;
	
	return 0;
}

void quick_find(int ps[], int qs[], int m) {
	int i, p, q, id[N];
	for (i = 0; i < N; i++)
		id[i] = i;
	for (int idx = 0; idx < m; idx++) {
		p = ps[idx];
		q = qs[idx];
		int pID = id[p];
		int qID = id[q];
		if (pID == qID)
			continue;
		for (i = 0; i < N; i++) {
			if (id[i] == pID)
				id[i] = qID;
		}
	}
}

void quick_union(int ps[], int qs[], int m) {
	int i, j, p, q, id[N];
	for (i = 0; i < N; i++)
		id[i] = i;
	for (int idx = 0; idx < m; idx++) {
		p = ps[idx];
		q = qs[idx];
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (i == j)
			continue;
		id[i] = j;
	}
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
	}
}

void weighted_quick_union_with_halving_path_compression(
int ps[], int qs[], int m) {
	int i, j, p, q, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
	for (int idx = 0; idx < m; idx++) {
		p = ps[idx];
		q = qs[idx];
		for (i = p; i != id[i]; i = id[i])
			id[i] = id[id[i]];
		for (j = q; j != id[j]; j = id[j])
			id[j] = id[id[j]];
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
	}
}

void weighted_quick_union_with_full_path_compression(
int ps[], int qs[], int m) {
	int i, j, p, q, k, t, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
	for (int idx = 0; idx < m; idx++) {
		int times = 0;
		p = ps[idx];
		q = qs[idx];
		for (i = p; i != id[i]; i = id[i]);
		k = p;
		while (k != id[k]) {
			t = id[k];
			id[k] = i;
			k = t;
		}
		for (j = q; j != id[j]; j = id[j]);
		k = q;
		while (k != id[k]) {
			t = id[k];
			id[k] = j;
			k = t;
		}
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
	}
}

/*
M = 100000 N = 100000
quick find 24.327 seconds.
quick union 1.96062 seconds.
weighted quick union 0.00533143 seconds.
weighted quick union with halving path compression 0.00334834 seconds.
weighted quick union with full path compression 0.00454696 seconds.
*/