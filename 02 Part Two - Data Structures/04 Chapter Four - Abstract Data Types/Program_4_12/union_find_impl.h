#ifndef UNIONFINDIMPL_H__
#define UNIONFINDIMPL_H__

#include "union_find.h"

class UnionFindImpl : public UnionFind {
public:
	UnionFindImpl(int);
	~UnionFindImpl();
	
	bool Find(int, int) const;
	void Unite(int, int);
	
private:
	int *id_;
	int *sz_;
	int Find(int) const;
};

#endif // UNIONFINDIMPL_H__
