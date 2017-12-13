#include "union_find.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int p, q;
	int n = atoi(argv[1]);
	
	UnionFind info(n);
	
	while (cin >> p >> q) {
		if (!info.FindAndUnite(p, q)) {
			cout << " " << p << " " << q << endl;
		}
	}
	
	return 0;
}
