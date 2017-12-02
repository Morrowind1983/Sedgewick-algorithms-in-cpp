/*
Program 4.1. Point class implementation

This class defines a data type consisting of the set of values "pairs of
floating-point numbers" (which are presumably interpreted as points in the
Cartesian plane), along with two member functions that are defined for all
POINTs: the function POINT() is a constructor that initializes the coordinates
to random values between 0 and 1, and the function distance(POINT) computes the
distance to another POINT. The data representation is private and can be
accessed or modified only by the member functions, and the member functions are
public and can be used by any client. We might keep this code, for example, in
a file named POINT.cxx.
*/

#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

Point::Point() {
	static int N = 0;
	x = 1.0*rand()/RAND_MAX;
	y = 1.0*rand()/RAND_MAX;
	N++;
}

float Point::X() const {
	return x;
}

float Point::Y() const {
	return y;
}

float Point::distance(Point a) const {
	float dx = this->x - a.x;
	float dy = this->y - a.y;
	return sqrt(dx*dx + dy*dy);
}

float Point::radius() const {
	return sqrt(x*x + y*y);
}

float Point::distance(Point a, Point b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

float distance(Point a, Point b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

bool operator==(Point a, Point b) {
	return Point::distance(a, b) < 0.001;
}

ostream& operator<<(ostream& t, Point p) {
	cout << "(" << p.X() << "," << p.Y() << ")";
	return t;
}
