/*
Program 3.15. String search

This program discovers all occurrences of a word from the command line in a
(presumably much larger) text string. We declare the text string as a
fixed-size character array (we could also use new[], as in Program 3.6) and
read it from standard input, using cin.get(). Memory for the word from the
command line-argument is allocated by the system before this program is
invoked, and we find the string pointer in argv[1]. For each starting position
i in a, we try matching the substring starting at that position with p, testing
for equality character by character. Whenever we reach the end of p
successfully, we print out the starting position i of the occurrence of the
word in the text.
*/

#include <iostream>
using namespace std;

static const int N = 100;

int main(int argc, char *argv[]) {
	int i, j;
	char t;
	char a[N], *p = argv[1];
	for (i = 0; i < N - 1; a[i] = t, i++) {
		if (!cin.get(t)) {
			break;
		}
	}
	a[i] = 0;
	for (i = 0; a[i] != 0; i++) {
		for (j = 0; p[j] != 0; j++) {
			if (p[j] != a[i + j]) {
				break;
			}
		}
		if (p[j] == 0) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
