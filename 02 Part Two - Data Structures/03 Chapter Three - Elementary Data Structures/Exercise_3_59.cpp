/*
3.59 Write a program that replaces substrings of more than one blank in a given
string by exactly one blank.
*/

#include <iostream>
using namespace std;

int main() {
	char a[100];
	cin.getline(a, 100);
	char *p = a;
	char *q = a;
	while (*q) {
		*p = *q;
		p++;
		if (*q == ' ') {
			do {
				q++;
			} while (*q == ' ');
		}
		else {
			q++;
		}
	}
	*p = 0;
	cout << "[" << a << "]" << endl;
	return 0;
}

/*
   abc   def g  h  
[ abc def g h]
*/
