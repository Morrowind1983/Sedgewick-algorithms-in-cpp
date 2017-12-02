#include <iostream>
#include <cstdlib>
#include "Point.h"
using namespace std;

int main(int argc, char *argv[]) { 
	float d = atof(argv[2]);
	int i, cnt = 0, N = atoi(argv[1]);
	Point *a = new Point[N];
	for (i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (Point::distance(a[i], a[j]) < d)  {
				cnt++;
			}
		}
	}
	cout << cnt << " pairs within " << d << endl;
}