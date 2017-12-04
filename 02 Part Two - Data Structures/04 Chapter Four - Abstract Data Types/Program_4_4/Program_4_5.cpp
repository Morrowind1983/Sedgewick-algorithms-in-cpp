/*
Program 4.5. Postfix-expression evaluation

This pushdown-stack client reads any postfix expression involving multiplication
and addition of integers, then evaluates the expression and prints the computed
result. It saves intermediate results on a stack of integers, assuming that the
interface of Program 4.4 is implemented as a templatized class in the file
STACK.cxx. When we encounter operands, we push them on the stack; when we
encounter operators, we pop the top two entries from the stack and push the
result of applying the operator to them. The order in which the two pop()
operations are performed in the expressions in this code is unspecified in C++,
so the code for noncommutative operators such as subtraction or division would
be slightly more complicated. The program implicitly assumes that the integers
and operators are delimited by other characters of some kind (blanks, say), but
does not check the legality of the input at all. The final if statement and the
while loop perform a calculation similar to the C++ atoi function, which
converts integers from ASCII strings to integers for calculation. When we
encounter a new digit, we multiply the accumulated result by 10 and add the
digit.
*/

#include <iostream>
#include "Stack.cpp"
using namespace std;

int main(int argc, char *argv[]) { 
	char *a = argv[1];
	int N = strlen(a);
	Stack<int> save(N);
	for (int i = 0; i < N; i++) {
		if (a[i] == '+') {
			save.push(save.pop() + save.pop());
		}
		else if (a[i] == '*') {
			save.push(save.pop() * save.pop());
		}
		else if (a[i] >= '0' && a[i] <= '9') {
			save.push(0);
		}
		while (a[i] >= '0' && a[i] <= '9') {
			save.push(10*save.pop() + (a[i++]-'0'));
		}
	}
	cout << save.pop() << endl;
}