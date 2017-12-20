/*
4.47 Write a client that tests your deque ADTs (Exercise 4.43) by reading, as the
first argument on the command line, a string of commands like those given in
Exercise 4.40 then performing the indicated operations. Add a member function
dump to the interface and implementations, and print out the contents of the
deque after each operation, in the style of Figure 4.6.

EAs+Y+QUE**+st+*+IO*n++*
*/

#include "deque.cc"

#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	getline(cin, input);

	Deque<char> deque;

	int len = input.length();
	char c;
	for (int i = 0; i < len; ++i) {
		c = input[i];
		cout << c << "   ";
		if (c == '+') {
			cout <<  deque.PopFront() << "   ";
		}
		else if (c == '*') {
			cout <<  deque.PopBack() << "   ";
		}
		else if (c >= 'A' && c <= 'Z') {
			deque.PushFront(c);
			cout << "    ";
		}
		else if (c >= 'a' && c <= 'z') {
			deque.PushBack(c);
			cout << "    ";
		}
		deque.Dump();
	}
	cout << endl;
	
	return 0;
}

/*
EAs+Y+QUE**+st+*+IO*n++*
E       E 
A       A E 
s       A E s 
+   A   E s 
Y       Y E s 
+   Y   E s 
Q       Q E s 
U       U Q E s 
E       E U Q E s 
*   s   E U Q E 
*   E   E U Q 
+   E   U Q 
s       U Q s 
t       U Q s t 
+   U   Q s t 
*   t   Q s 
+   Q   s 
I       I s 
O       O I s 
*   s   O I 
n       O I n 
+   O   I n 
+   I   n 
*   n     
*/
