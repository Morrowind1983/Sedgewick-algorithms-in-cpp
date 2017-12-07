/*
4.11 Given two sequences, give an algorithm for determining whether or not
asterisks can be added to make the first produce the second, when interpreted as
a sequence of stack operations in the sense of Exercise 4.10.
*/

#include <iostream>
#include "Stack.cpp"
using namespace std;

void findNext(char *a, char *b, int lenA, int lenB, int ap, int bp, 
Stack<char> stack, string out);

int main(int argc, char *argv[]) { 
	char *a = argv[1];
	char *b = argv[2]; 
	Stack<char> stack;
	string out = "";
	findNext(a, b, strlen(a), strlen(b), 0, 0, stack, out);
	
	return 0;
}

void findNext(char *a, char *b, int lenA, int lenB, int ap, int bp, 
Stack<char> stack, string out) {
	if (bp > lenB - 1) {
		while (ap < lenA) {
			out += a[ap];
			ap++;
		}
		cout << out << endl;
		return;
	}
	while (ap < lenA) {
		stack.push(a[ap]);
		out += a[ap];
		string star = "";
		int step = 0;
		while (bp + step <= lenB - 1 && stack.top() == b[bp + step]) {
			star += "*";
			step++;
			stack.pop();
			findNext(a, b, lenA, lenB, ap + 1, bp + step, stack, out + star);
		}
		ap++;
	}
}

/*
"EASYEASY" "EASY"
E*A*S*Y*EASY
E*A*S*YEASY*
E*A*SYEAS*Y*
E*ASYEA*S*Y*
EASYE*A*S*Y*
EASYE*A*S**Y
/*
