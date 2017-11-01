/*
Point data type interface for n dimensions.
*/

struct point {
	int n;
	float *x;
};
float distance(point, point);
