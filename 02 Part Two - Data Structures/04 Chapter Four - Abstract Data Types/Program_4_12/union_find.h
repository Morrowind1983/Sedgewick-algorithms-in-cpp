#ifndef UNIONFIND_H__
#define UNIONFIND_H__

class UnionFind {
public:
	inline UnionFind() {}
	virtual ~UnionFind();
	
	virtual bool Find(int, int) const = 0;
	virtual void Unite(int, int) = 0;
};

#endif // UNIONFIND_H__
