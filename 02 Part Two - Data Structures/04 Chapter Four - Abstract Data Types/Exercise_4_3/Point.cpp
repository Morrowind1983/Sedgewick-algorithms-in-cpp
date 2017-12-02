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
	r = 0.5*rand()/RAND_MAX;
	a = 2*M_PI*rand()/RAND_MAX;
}

float Point::radius() const {
	return r;
}

float Point::angle() const {
	return a;
}

float Point::distance(Point a) const {
	return sqrt(2*this->r*a.r*cos(abs(a.a-this->a))-this->r*this->r*-a.r*a.r);
}

float Point::distance(Point a, Point b) {
	return sqrt(2*a.r*b.r*cos(abs(b.a-a.a))-a.r*a.r*-b.r*b.r);
}
