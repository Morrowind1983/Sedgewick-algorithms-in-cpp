/*
Program 3.3. Point data type interface

This interface defines a data type consisting of the set of values "pairs of
floating-point numbers" and the operation "compute the distance between two
points."
*/

struct point { float x; float y; };
float distance(point, point);
