#include <cmath>
#include "Triangle.h"

float triangle_area(triangle t) {
	return 0.5 * abs(t.a.x * t.b.y + t.b.x * t.c.y + t.c.x * t.a.y 
		- t.a.x * t.c.y - t.b.x * t.a.y - t.c.x * t.b.y);
}
