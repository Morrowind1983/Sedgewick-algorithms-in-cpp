/*
Program 4.6. Infix-to-postfix conversion

This program is another example of a pushdown-stack client. In this case, the
stack contains characters. To convert (A+B) to the postfix form AB+, we ignore
the left parenthesis, convert A to postfix, save the + on the stack, convert B
to postfix, then, on encountering the right parenthesis, pop the stack and
output the +.
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
