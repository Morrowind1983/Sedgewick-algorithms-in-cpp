/*
3.64 Write a program to fill in a two-dimensional array of 0–1 values by
setting a[i][j] to 1 if the greatest common divisor of i and j is 1, and to 0
otherwise.
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void method1(int **a, int V);
void method2(int **a, int V);
int** malloc2d(int row, int col);
void release2d(int** matrix, int row);

int main() {
	int N = 50000;
	int **matrix = malloc2d(N, N);
	
	steady_clock::time_point t1;
	steady_clock::time_point t2;
	duration<double> time_span;
	
	t1 = steady_clock::now();
	method1(matrix, N);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "method1 duration " << 
		time_span.count() << " seconds." << endl;
	
	t1 = steady_clock::now();
	method2(matrix, N);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "method2 duration " << 
		time_span.count() << " seconds." << endl;
	
	release2d(matrix, N);

	return 0;
}

void method1(int **a, int V) {
	int x, y, m;
	for (x = 0; x < V; x++) {
		a[0][x] = 0;
		a[x][0] = 0;
	}
	for (y = 1; y < V; y++) {
		for (x = y + 1; x < V; x++) {
			a[y][x] = 1;
			a[x][y] = 1;
		}
	}
	for (x = 1; x < V; x++) {
		a[x][x] = 1;
	}
	
	int step = 2;
	while (step < V) {
		if (a[step][step] == 1) {
			for (y = step; y < V; y += step) {
				for (x = step; x < V; x += step) {
					a[y][x] = 0;
				}
			}
		}
		step++;
	}
}

void method2(int **a, int V) {
	int x, y, m;
	for (x = 0; x < V; x++) {
		a[0][x] = 0;
		a[x][0] = 0;
	}
	for (x = 1; x < V; x++) {
		a[1][x] = 1;
		a[x][1] = 1;
	}
	for (x = 2; x < V; x++) {
		a[x][x] = 0;
	}
	
	for (y = 2; y < V; y++) {
		for (x = y + 1; x < V; x++) {
			m = x % y;
			if (m == 0 || a[m][y] == 0) {
				a[y][x] = 0;
			}
			else {
				a[y][x] = 1;
			}
			a[x][y] = a[y][x];
		}
	}
}

int** malloc2d(int row, int col) {
	int **matrix = new int*[row];
	for (int r = 0; r < row; r++) {
		matrix[r] = new int[col];
	}
	return matrix;
}

void release2d(int** matrix, int row) {
	for (int r = 0; r < row; r++) {
		delete[] matrix[r];
	}
	delete[] matrix;
}

/*
N = 50000
method1 duration 61.0916 seconds.
method2 duration 102.52 seconds.
*/
