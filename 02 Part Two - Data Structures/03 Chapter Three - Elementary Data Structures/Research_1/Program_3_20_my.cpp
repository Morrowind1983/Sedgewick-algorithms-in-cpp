/*
Program 3.20. A two-dimensional array of lists

This program illustrates the effectiveness of proper data-structure choice, for
the geometric computation of Program 3.8. It divides the unit square into a
grid, and maintains a two-dimensional array of linked lists, with one list
corresponding to each grid square. The grid is chosen to be sufficiently fine
that all points within distance d of any given point are either in the same grid
square or an adjacent one. The function malloc2d is like the one in Program
3.16, but for objects of type linkinstead of int.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <chrono>
#include "Point.h"
using namespace std;
using namespace std::chrono;

struct node {
	point p;
	node *next;
	node(point pt, node* t) {
		p = pt;
		next = t;
	}
};

typedef node *link;
static link **grid;
static int G;
static long long cnt = 0;
static float d;

float randFloat() {
	return 1.0*rand()/RAND_MAX;
}

link **malloc2d(int r, int c) {
	link **t = new link*[r];
	for (int i = 0; i < r; i++)
		t[i] = new link[c];
	return t;
}

void gridinsert(float x, float y) {
	int i, j;
	int X = 2*x/d;
	int Y = 2*y/d;
	if (X > G - 1)
		X = G - 1;
	if (Y > G - 1)
		Y = G - 1;
	point p;
	p.x = x;
	p.y = y;
	link s, t = new node(p, grid[X][Y]);
	for (i = max(0, X - 2); i <= min(G - 1, X + 2); i++) {
		for (j = max(0, Y - 2); j <= min(G - 1, Y + 2); j++) {
			if (i == X && j == Y) {
				for (s = grid[i][j]; s != 0; s = s->next)
					cnt++;
			}
			else {
				for (s = grid[i][j]; s != 0; s = s->next) {
					if (distance(s->p, t->p) < d)
						cnt++;
				}
			}
		}
	}				
	grid[X][Y] = t;
}

int main(int argc, char *argv[]) {
	int i, j, N = atoi(argv[1]);
	d = atof(argv[2]);
	G = ceil(2/d);
	grid = malloc2d(G, G);
	for (i = 0; i < G; i++)
		for (j = 0; j < G; j++)
			grid[i][j] = 0;
	steady_clock::time_point t1 = steady_clock::now();
	for (i = 0; i < N; i++)
		gridinsert(randFloat(), randFloat());
	steady_clock::time_point t2 = steady_clock::now();
	cout << "N = " << N << " d = " << d << endl;
	cout << cnt << " pairs within " << d << endl;
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "duration " << time_span.count() << " seconds." << endl;
}

/*
N = 100000 d = 0.3
1073605203 pairs within 0.3
duration 28.1359 seconds.
*/
