/* 
4.2 Add a member function to the point class in Program 4.3 that returns the
distance to the origin.

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
	float x, y;
public:
	Point();
	float X() const;
	float Y() const;
	float distance(Point) const;
	float radius() const;
	static float distance(Point, Point);
	friend float distance(Point, Point);
	friend bool operator==(Point, Point);
	friend ostream& operator<<(ostream&, Point);
};
