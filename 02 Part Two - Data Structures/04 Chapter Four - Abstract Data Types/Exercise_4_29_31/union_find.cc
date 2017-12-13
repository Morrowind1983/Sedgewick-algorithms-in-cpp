/*
4.29 Modify Program 4.11 to use path compression by halving.

4.30 Remove the inefficiency mentioned in the text by adding an operation to
Program 4.9 that combines union and find, providing an implementation in
Program 4.11, and modifying Program 4.10 accordingly.

4.31 Modify our equivalence-relations interface (Program 4.9) and
implementation (Program 4.11) to provide a function that will return the number
of nodes known to be connected to a given node.
*/

#include "union_find.h"

UnionFind::UnionFind(int n) {
	id_ = new int[n];
	sz_ = new int[n];
	for (int i = 0; i < n; ++i) {
		id_[i] = i;
		sz_[i] = 1;
	}
}

UnionFind::~UnionFind() {
	delete[] id_;
	delete[] sz_;
}

bool UnionFind::Find(int p, int q) const {
	return Find(p) == Find(q);
}

void UnionFind::Unite(int p, int q) {
	int i = Find(p);
	int j = Find(q);
	if (i == j) {
		return;
	}
	if (sz_[i] < sz_[j]) {
		id_[i] = j;
		sz_[j] += sz_[i];
	}
	else {
		id_[j] = i;
		sz_[i] += sz_[j];
	}
}

bool UnionFind::FindAndUnite(int p, int q) {
	int i = Find(p);
	int j = Find(q);
	if (i == j) {
		return true;
	}
	if (sz_[i] < sz_[j]) {
		id_[i] = j;
		sz_[j] += sz_[i];
	}
	else {
		id_[j] = i;
		sz_[i] += sz_[j];
	}
	return false;
}

int UnionFind::NumOfNodes(int p, int q) const {
	int num_p = 0;
	int num_q = 0;
	int x = p;
	int y = q;
	while (x != id_[x]) {
		if (x == q) {
			return num_p;
		}
		x = id_[x];
		++num_p;
	}
	while (y != id_[y]) {
		if (y == p) {
			return num_q;
		}
		y = id_[y];
		++num_q;
	}
	if (x == y) {
		return num_p + num_q;
	}
	return -1;
}

int UnionFind::Find(int x) const {
	while (x != id_[x]) {
		id_[x] = id_[id_[x]];  // path compression by halving
		x = id_[x];
	}
	return x;
}
