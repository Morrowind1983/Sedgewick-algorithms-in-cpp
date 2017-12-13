/*
Program 4.10. Equivalence-relations ADT client

The ADT of Program 4.9 separates the connectivity algorithm from the union–find
implementation, making that algorithm more accessible.
*/

#include <iostream>
#include "UF.h"
using namespace std;

int main(int argc, char *argv[]) {
	int p, q, N = atoi(argv[1]);
	UF info(N);
	while (cin >> p >> q) {
		if (!info.find(p, q)) {
			info.unite(p, q);
			cout << " " << p << " " << q << endl;
		}
	}
	return 0;
}
