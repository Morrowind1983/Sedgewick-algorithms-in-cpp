/*
4.22 Suppose that you change the pushdown-stack interface to replace test if
empty by count, which should return the number of items currently in the data
structure. Provide implementations for count for the array representation
(Program 4.7) and the linked-list representation (Program 4.8).

4.23 Modify the array-based pushdown-stack implementation in the text (Program
4.7) to call a member function error() if the client attempts to pop when the
stack is empty or to push when the stack is full.

4.24 Modify the linked-list–based pushdown-stack implementation in the text
(Program 4.8) to call a member function error() if the client attempts to pop
when the stack is empty or if there is no memory available from new for a push.
*/

#include <iostream>
#include "Stack.cpp"
using namespace std;

int main(int argc, char *argv[]) {
	char *a = argv[1];
	int N = strlen(a);
	Stack<char> ops;
	for (int i = 0; i < N; i++) {
		if (a[i] == ')') {
			cout << ops.pop() << " ";
		}
		else if (a[i] == '+' || a[i] == '*') {
			ops.push(a[i]);
		}
		else if (a[i] >= '0' && a[i] <= '9') {
			cout << a[i] << " ";
		}
	}
	cout << endl;
}

