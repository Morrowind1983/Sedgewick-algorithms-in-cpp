/*
4.37 A letter means put and an asterisk means get in the sequence

EAS*Y*QUE***ST***IO*N***

Give the sequence of values returned by the get operations when this sequence of
operations is performed on an initially empty FIFO queue.
*/

#include "queue.cc"

#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	getline(cin, input);

	Queue<char> queue(100);

	int len = input.length();
	char c;
	for (int i = 0; i < len; ++i) {
		c = input[i];
		if (c == '*') {
			cout << queue.Get() << " ";
		}
		else {
			queue.Put(c);
		}
	}
	cout << endl;
	
	return 0;
}
