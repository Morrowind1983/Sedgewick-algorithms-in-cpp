/*
3.49 Implement the interface in Program 3.12 using new and delete directly in
newNode and deleteNode, respectively.

3.50 Run empirical studies comparing the running times of the memory-allocation
functions in Program 3.14 with new and delete (see Exercise 3.49) for Program
3.13 with M = 2 and N = 10^3, 10^4, 10^5, and 10^6.
*/

#include <iostream>
#include <chrono>
#include "List.h"
using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]) {
	steady_clock::time_point t1 = steady_clock::now();
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	Node t;
	construct(N);
	Node x = newNode(1);
	for (i = 2; i <= N; i++) {
		t = newNode(i);
		insert(x, t);
		x = t;
	}
	while (x != next(x)) {
		for (i = 1; i < M; i++)
			x = next(x);
		deleteNode(remove(x));
	}
	cout << item(x);
	deleteNode(x);
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << " N = " << N << " M = " << M << " " 
		<< time_span.count() << " seconds." << endl;
	return 0;
}

/*
977 N = 1000 M = 2 0.000473143 seconds.
3617 N = 10000 M = 2 0.00182667 seconds.
68929 N = 100000 M = 2 0.0191912 seconds.
951425 N = 1000000 M = 2 0.215506 seconds.
*/
