/*
4.4 Write a client program that takes an integer N from the command line, and
fills an array with N points, no two of which are equal. Use the overloaded==
operator described in the text to test equality.
*/

#include <iostream>
#include "Point.h"
using namespace std;

int main(int argc, char *argv[]) { 
	int N = atoi(argv[1]);
	int i, j;
	bool unique;
	Point *points = new Point[N];
	for (i = 0; i < N; i++) {
		unique = false;
		while (!unique) {
			unique = true;
			for (j = 0; j < i; j++) {
				if (points[i] == points[j]) {
					unique = false;
					points[i] = Point();
					break;
				}
			}
		}
		cout << "[" << i << "]" << points[i] << endl;
	}
	delete[] points;
	
	return 0;
}

/*
N = 10
[0](7.82637e-06,0.131538)
[1](0.755605,0.45865)
[2](0.532767,0.218959)
[3](0.0470446,0.678865)
[4](0.679296,0.934693)
[5](0.383502,0.519416)
[6](0.830965,0.0345721)
[7](0.247039,0.98255)
[8](0.999458,0.888572)
[9](0.325579,0.00166435)
*/