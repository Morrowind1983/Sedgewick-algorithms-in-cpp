/*
Point data type implementation
*/

#include <cmath>
#include "Point.h"

float distance(point a, point b) {
	if (a.n != b.n)
		return -1;
	
	float sum = 0;
	for (int i = 0; i < a.n; i++) {
		sum += (a.x[i] - b.x[i])*(a.x[i] - b.x[i]);
	}
	
	return sqrt(sum);
}
