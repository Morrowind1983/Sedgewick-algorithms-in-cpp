/* 
Program 1.2. Quick-union solution to connectivity problem

If we replace the body of the while loop in Program 1.1 by this code, we have
a program that meets the same specifications as Program 1.1, but does less
computation for the union operation at the expense of more computation for the
find operation. The for loops and subsequent if statement in this code specify
the necessary and sufficient conditions on the id array for p and q to be
connected. The assignment statement id[i] = j implements the union operation.
*/

#include <iostream>
using namespace std;

static const int N = 10000;

int main() {
	int i, j, p, q, id[N];
	for (i = 0; i < N; i++)
		id[i] = i;
	while (cin >> p >> q) {
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (i == j)
			continue;
		id[i] = j;
		cout << " " << p << " " << q << endl;
	}
	return 0;
}
