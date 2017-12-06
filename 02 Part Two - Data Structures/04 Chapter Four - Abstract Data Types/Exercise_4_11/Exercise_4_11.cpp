/*
4.11 Given two sequences, give an algorithm for determining whether or not
asterisks can be added to make the first produce the second, when interpreted as
a sequence of stack operations in the sense of Exercise 4.10.
*/

#include <iostream>
#include "Stack.cpp"
using namespace std;

void findNextChar(char *a, char *b, int ap, int bp, int lenA, int lenB, 
string out);
void forward(char *a, char *b, int ap, int bp, int lenA, int lenB, string out);
void backward(char *a, char *b, int ap, int bp, int lenA, int lenB, int step, string out);

void forward(char *a, char *b, int ap, int bp, int lenA, int lenB, string out) {
	out += a[ap];
	if (a[ap] == b[bp]) {
		// cout << "->" << out << " ap=" << ap << " bp=" << bp << endl;
		backward(a, b, ap, bp, lenA, lenB, 0, out);
	}
	if (ap + 1 < lenA) {
		forward(a, b, ap + 1, bp, lenA, lenB, out);
	}
}

void backward(char *a, char *b, int ap, int bp, int lenA, int lenB, int step, string out) {
	if (ap - step >= 0) {
		if (a[ap - step] == b[bp]) {
			out += "*";
			bp++;
			
			if (bp > lenB - 1) {
				ap++;
				while (ap < lenA) {
					out += a[ap];
					ap++;
				}
				cout << out << endl;
			}
			
			// cout << "* " << out << " ap=" << ap << " bp=" << bp << endl;
			backward(a, b, ap, bp, lenA, lenB, step + 1, out);
		}
		forward(a, b, ap + 1, bp, lenA, lenB, out);
	}
}

int main(int argc, char *argv[]) { 
	char *a = argv[1];
	char *b = argv[2]; 
	Stack<char> stackIn;
	string out = "";
	// findNextChar(a, b, 0, 0, strlen(a), strlen(b), out);
	forward(a, b, 0, 0, strlen(a), strlen(b), out);
	
	return 0;
}


void findNextChar(char *a, char *b, int ap, int bp, int lenA, int lenB, 
string out) {
	if (ap > 0) {
		int back = 1;
		while (true) {
			char c = a[ap - back];
			if (c == b[bp]) {
				out += "*";
				bp++;
				
				cout << "* " << out << " ap=" << ap << " bp=" << bp << endl;
			}
			else {
				break;
			}
			back++;
		}
	}
	while (ap < lenA) {
		out += a[ap];
		if (a[ap] == b[bp]) {
			cout << "->" << out << " ap=" << ap << " bp=" << bp << endl;
			findNextChar(a, b, ap + 1, bp, lenA, lenB, out);
		}
		ap++;
	}
	if (bp > lenB - 1) {
		while (ap < lenA) {
			out += a[ap];
			ap++;
		}
		cout << out << endl;
		return;
	}
}

// void findNextChar(char *a, char *b, int ap, int bp, int lenA, int lenB,
// Stack<char> stackIn, string out) {
// 	if (!stackIn.empty()) {
// 		char c = stackIn.pop();
// 		if (c == b[bp]) {
// 			out += "*";
// 			bp++;
// 			// cout << "* " << out << " ap=" << ap << " bp=" << bp << endl;
//
// 			// cout << "<-" << out << " ap=" << ap << " bp=" << bp << endl;
// 			findNextChar(a, b, ap, bp, lenA, lenB, stackIn, out);
// 			// cout << "<-end" << endl;
//
// 			if (bp == lenB - 1 && ap == lenA - 1) {
// 				stackIn.push(c);
// 				findNextChar(a, b, ap, bp, lenA, lenB, stackIn, out);
// 			}
// 			else if (bp > lenB - 1) {
// 				while (ap < lenA) {
// 					out += a[ap];
// 					ap++;
// 				}
// 				cout << out << endl;
// 				// cout << endl;
// 				return;
// 			}
//
// 			return;
// 		}
// 		stackIn.push(c);
// 	}
// 	while (ap < lenA) {
// 		stackIn.push(a[ap]);
// 		out += a[ap];
// 		if (a[ap] == b[bp]) {
// 			// cout << "->" << out << " ap=" << ap << " bp=" << bp << endl;
// 			findNextChar(a, b, ap + 1, bp, lenA, lenB, stackIn, out);
// 			// cout << "->end" << endl;
// 		}
// 		ap++;
// 	}
// }
