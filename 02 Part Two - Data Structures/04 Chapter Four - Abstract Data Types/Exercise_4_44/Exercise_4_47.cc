/*
4.47 Write a client that tests your deque ADTs (Exercise 4.43) by reading, as the
first argument on the command line, a string of commands like those given in
Exercise 4.40 then performing the indicated operations. Add a member function
dump to the interface and implementations, and print out the contents of the
deque after each operation, in the style of Figure 4.6.
*/

#include "deque.cc"

#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	getline(cin, input);

	Deque<char> deque(100);

	int len = input.length();
	char c;
	for (int i = 0; i < len; ++i) {
		c = input[i];
		if (c == '*') {
			cout << deque.PopFront() << " ";
		}
		else {
			deque.PushBack(c);
		}
	}
	cout << endl;
	
	return 0;
}
