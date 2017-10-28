/*
3.8 Add a function to the point data type (Programs 3.3 and 3.4) that determines
whether or not three points are collinear, to within a numerical tolerance of
10–4. Assume that the points are all in the unit square.
*/

#include <iostream>
#include "Point.h"
using namespace std;

int main() {
	point a, b, c;
	a.x = 0;
	a.y = 0;
	b.x = 0.2;
	b.y = 0.3;
	c.x = 0.4;
	c.y = 0.6;
	cout << "is collinear: " << isCollinear(a, b, c) << endl;
}
