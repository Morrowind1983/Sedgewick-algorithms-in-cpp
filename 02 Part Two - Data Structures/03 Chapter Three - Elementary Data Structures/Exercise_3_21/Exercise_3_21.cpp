/*
3.21 Modify Program 3.8 to print out the coordinates of the closest pair of
points.

Program 3.8. Closest-point computation

This program illustrates the use of an array of structures, and is
representative of the typical situation where we save items in an array to
process them later, during some computation. It counts the number of pairs of N
randomly generated points in the unit square that can be connected by a straight
line of length less than d, using the data type for points described in Section
3.1. The running time is O(N^2), so this program cannot be used for huge N.
Program 3.20 provides a faster solution.
*/

#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

float randFloat() {
	return 1.0*rand()/RAND_MAX;
}

int main(int argc, char *argv[]) {
	int i, j, N = atoi(argv[1]);
	point *a = new point[N];
	for (i = 0; i < N; i++) {
		a[i].x = randFloat();
		a[i].y = randFloat();
	}
	float min_d = -1;
	int min_i1;
	int min_i2;
	float t;
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			t = distance(a[i], a[j]);
			if (min_d < 0 || t < min_d) {
				min_d = t;
				min_i1 = i;
				min_i2 = j;
			}
		}
	}
	if (min_d >= 0) {
		cout << "closest pair: (" << a[min_i1].x << ", "<< a[min_i1].y << ")-(" 
			<< a[min_i2].x << ", " << a[min_i2].y << ") d = " << min_d << endl;
	}
	else {
		cout << "error!" << endl;
	}
	delete [] a;
	return 0;
}

/*
N = 1000
closest pair: (0.854365, 0.314699)-(0.854603, 0.314608) d = 0.000254939
*/
