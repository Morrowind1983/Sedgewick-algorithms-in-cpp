/*
3.56 Write a program that checks whether a given string is a palindrome (reads
the same backward or forward), ignoring blanks. For example, your program
should report success for the string if i had a hifi.
*/

#include <iostream>
using namespace std;

int main() {
	char a[100];
	cin.getline(a, 100);
	if (!*a) {
		return 0;
	}
	char *s = a;
	while (*s == ' ') {
		s++;
	}
	if (!*s) {
		return 0;
	}
	char *e = s;
	while (*e++);
	e -= 2;
	while (*e == ' ') {
		e--;
	}

	while (*s == *e) {
		do {
			s++;
		} while (*s == ' ');
		do {
			e--;
		} while (*e == ' ');
		if (s >= e) {
			cout << "success" << endl;
			break;
		}
	}
	
	return 0;
}

/*
if i had a hifi
success
*/
