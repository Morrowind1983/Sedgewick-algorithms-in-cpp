#include "union_find_impl.h"

UnionFindImpl::UnionFindImpl(int n) {
	id_ = new int[n];
	sz_ = new int[n];
	for (int i = 0; i < n; ++i) {
		id_[i] = i;
		sz_[i] = 1;
	}
}

UnionFindImpl::~UnionFindImpl() {
	delete[] id_;
	delete[] sz_;
}

bool UnionFindImpl::Find(int p, int q) const {
	return Find(p) == Find(q);
}

void UnionFindImpl::Unite(int p, int q) {
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

int UnionFindImpl::Find(int x) const {
	while (x != id_[x]) {
		x = id_[x];
	}
	return x;
}
