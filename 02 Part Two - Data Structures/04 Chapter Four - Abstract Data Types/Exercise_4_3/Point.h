/*
4.3 Modify the point ADT implementation in Program 4.3 to represent points with
polar coordinates.

Program 4.3. Point ADT interface

By convention, we derive the interface associated with a class ADT implementation
by removing the private parts and by replacing function implementations with
declarations (signatures). This interface is derived in this way from Program
4.1. We can use different implementations that have the same interface without
changing any code in the client programs that use the ADT.
*/

#include <iostream>
using namespace std;

class Point {
private:
	float r, a;
public:
	Point();
	float radius() const;
	float angle() const;
	float distance(Point) const;
	static float distance(Point, Point);
};
