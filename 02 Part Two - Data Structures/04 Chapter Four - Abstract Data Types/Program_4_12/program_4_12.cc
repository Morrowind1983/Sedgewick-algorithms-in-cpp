#include "union_find_impl.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int p, q;
	int n = atoi(argv[1]);
	
	UnionFindImpl info(n);
	
	while (cin >> p >> q) {
		if (!info.Find(p, q)) {
			info.Unite(p, q);
			cout << " " << p << " " << q << endl;
		}
	}
	
	return 0;
}
