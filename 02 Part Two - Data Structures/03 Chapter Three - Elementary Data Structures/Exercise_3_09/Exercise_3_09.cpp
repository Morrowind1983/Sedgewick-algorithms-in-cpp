/*
3.9 Define a data type for triangles in the unit square, including a function
that computes the area of a triangle. Then write a client program that generates
random triples of pairs of floats between 0 and 1 and computes the average area
of the triangles generated.
*/

#include <iostream>
#include <random>
#include "Triangle.h"
using namespace std;

int main() {
	random_device rd;
	mt19937 random_number_engine(rd());
	
	uniform_real_distribution<> dis(0, 1);
	
	int N = 3;
	float sum_area = 0;
	for (int i = 0; i < N; i++) {
		point a, b, c;
		a.x = dis(random_number_engine);
		a.y = dis(random_number_engine);
		b.x = dis(random_number_engine);
		b.y = dis(random_number_engine);
		c.x = dis(random_number_engine);
		c.y = dis(random_number_engine);
		
		triangle t;
		t.a = a;
		t.b = b;
		t.c = c;
		
		float area = triangle_area(t);
		sum_area += area;
		
		cout << "area: " << area << endl;
	}
	
	float mean_area = sum_area / N;
	cout << "mean area: " << mean_area << endl;
}
