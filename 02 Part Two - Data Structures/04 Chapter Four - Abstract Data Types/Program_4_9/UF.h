/*
Program 4.9. Equivalence-relations ADT interface

Our ADT interface mechanism makes it convenient for us to encode precisely our
decision to consider the connectivity algorithm in terms of a class that
suppports three abstract operations: initialize an abstract data structure to
keep track of connections among the given number of nodes, find whether two given
nodes are connected, and unite two given nodes to consider them connected
henceforth.
*/

class UF {
private:
	int *id;
	int *sz;
	int find(int) const;
public:
	UF(int);
	~UF();
	bool find(int, int) const;
	void unite(int, int);
};