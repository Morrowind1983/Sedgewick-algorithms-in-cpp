/*
Program 4.2. Point client (closest-point computation)

This version of Program 3.8 is a client that uses the POINT ADT defined in
Program 4.3. The new[] operator constructs an array of POINT objects (invoking
the constructor POINT() to initialize each with random coordinates). The call
a[i].distance(a[j]) invokes the distance member function for the object a[i]
with argument a[j].
*/

#include <iostream>
#include <cstdlib>
#include "Point.h"
using namespace std;

int main(int argc, char *argv[]) { 
	float d = atof(argv[2]);
	int i, cnt = 0, N = atoi(argv[1]);
	Point *a = new Point[N];
	for (i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (Point::distance(a[i], a[j]) < d)  {
				cout << a[i] << " - " << a[j] << endl;
				cnt++;
			}
		}
	}
	cout << cnt << " pairs within " << d << endl;
}