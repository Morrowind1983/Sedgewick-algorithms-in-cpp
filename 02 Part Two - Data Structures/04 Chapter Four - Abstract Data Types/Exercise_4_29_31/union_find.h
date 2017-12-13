#ifndef UNIONFIND_H__
#define UNIONFIND_H__

class UnionFind {
public:
	UnionFind(int);
	~UnionFind();
	
	bool Find(int, int) const;
	void Unite(int, int);
	bool FindAndUnite(int, int);  // combines union and find
	int NumOfNodes(int, int) const;
	
private:
	int *id_;
	int *sz_;
	int Find(int) const;
};

#endif // UNIONFIND_H__
