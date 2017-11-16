/*
3.55 Write a program that takes a string as argument, and that prints out a
table giving, for each character that occurs in the string, the character and
its frequency of occurrence.
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int i;
	int freq[256] = {};
	char *p = argv[1];
	while (*p) {
		freq[*p]++;
		p++;
	}
	for (i = 0; i < 256; i++) {
		if (freq[i]) {
			cout << (char)i << ": " << freq[i] << endl;
		}
	}
	return 0;
}

/*
ChapterThreeElementaryDataStructures
C: 1
D: 1
E: 1
S: 1
T: 1
a: 4
c: 1
e: 6
h: 2
l: 1
m: 1
n: 1
p: 1
r: 5
s: 1
t: 5
u: 2
y: 1
*/
