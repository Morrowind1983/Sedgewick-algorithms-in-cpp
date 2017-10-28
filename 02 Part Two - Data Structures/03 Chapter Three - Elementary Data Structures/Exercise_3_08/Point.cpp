#include <cmath>
#include "Point.h"

float distance(point a, point b) {
	float dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

bool isCollinear(point a, point b, point c) {
	return abs((b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x)) < 0.0001;
}
