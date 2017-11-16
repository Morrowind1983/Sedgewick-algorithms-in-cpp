/*
Program 3.17. Sorting an array of strings

This program illustrates an important string-processing function: rearranging a
set of strings into sorted order. We read strings into a buffer large enough to
hold them all, maintaining a pointer to each string in an array, then rearrange
the pointers to put the pointer to the smallest string in the first position in
the array, the pointer to the second smallest string in the second position in
the array, and so forth.

The qsort library function that actually does the sort takes four arguments: a
pointer to the beginning of the array, the number of objects, the size of each
object, and a comparison function. It achieves independence from the type of
object being sorted by blindly rearranging the blocks of data that represent
objects (in this case string pointers) and by using a comparison function that
takes pointers to void as argument. This code casts these back to type pointer to
pointer to char for strcmp. To actually access the first character in a string
for a comparison, we dereference three pointers: one to get the index (which is a
pointer) into our array, one to get the pointer to the string (using the index),
and one to get the character (using the pointer).

We use a different method to achieve type independence for our sorting and
searching functions (see Chapters 4 and 6).
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int compare(const void *i, const void *j) {
	return strcmp(*(char **)i, *(char **)j);
}

int main() {
	const int WORD_MAX = 1000;
	const int BUF_MAX = 10000;
	char *word[WORD_MAX];
	char buf[BUF_MAX];
	int idx = 0;
	int p;
	for (p = 0; p < WORD_MAX; p++) {
		word[p] = &buf[idx];
		if (!(cin >> word[p])) {
			break;
		}
		idx += strlen(word[p]) + 1;
	}
	qsort(word, p, sizeof(char*), compare);
	for (int i = 0; i < p; i++) {
		cout << word[i] << " ";
	}
	cout << endl;
	return 0;
}
