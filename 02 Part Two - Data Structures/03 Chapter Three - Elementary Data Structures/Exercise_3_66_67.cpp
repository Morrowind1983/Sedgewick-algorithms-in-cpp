/*
3.66 Write a program to convert a sparse matrix from a two-dimensional array
to a multilist with nodes for only nonzero values.

3.67 Implement matrix multiplication for matrices represented with
multi-lists.
*/

#include <iostream>
#include <iomanip>
using namespace std;

typedef int ELemType;  
typedef struct OLNode {
	ELemType e;
	int i, j;
	struct OLNode *right, *down;
} OLNode, *OLink;
typedef struct {
	OLink *rhead, *chead;
	int mu, nu, tu;
} CrossList;

CrossList crosslist_matrix_multiplication(CrossList A, CrossList B);
ELemType productAtPos(CrossList headA, CrossList headB, int row, int col);
CrossList malloc_crosslist_matrix(int **a, int row, int col);
void release_crosslist_matrix(CrossList head);
void print_crosslist_matrix(CrossList head);
void create_sparse_matrix(int **a, int row, int col);
void print_matrix(int **a, int row, int col);
int** malloc2d(int row, int col);
void release2d(int** matrix, int row);

int main() {
	int **matrixA = malloc2d(10, 20);
	create_sparse_matrix(matrixA, 10, 20);
	print_matrix(matrixA, 10, 20);
	cout << endl;
	CrossList headA = malloc_crosslist_matrix(matrixA, 10, 20);
	print_crosslist_matrix(headA);
	cout << endl;
	
	int **matrixB = malloc2d(20, 10);
	create_sparse_matrix(matrixB, 20, 10);
	print_matrix(matrixB, 20, 10);
	cout << endl;
	CrossList headB = malloc_crosslist_matrix(matrixB, 20, 10);
	print_crosslist_matrix(headB);
	cout << endl;
	
	CrossList headAB = crosslist_matrix_multiplication(headA, headB);
	print_crosslist_matrix(headAB);
	
	release_crosslist_matrix(headA);
	release_crosslist_matrix(headB);
	release_crosslist_matrix(headAB);
	release2d(matrixA, 10);
	release2d(matrixB, 20);

	return 0;
}

CrossList crosslist_matrix_multiplication(CrossList headA, CrossList headB) {
	CrossList head;
	if (headA.nu != headB.mu) {
		head.mu = 0;
		head.nu = 0;
		head.tu = 0;
		head.rhead = nullptr;
		head.chead = nullptr;
		return head;
	}
	head.mu = headA.mu;
	head.nu = headB.nu;
	head.tu = 0;
	head.rhead = new OLink[head.mu + 1];
	head.chead = new OLink[head.nu + 1];
	OLink* y = new OLink[head.nu + 1];
	for (int c = 1; c <= head.nu; c++) {
		head.chead[c] = nullptr;
		y[c] = head.chead[c];
	}
	OLink x = nullptr;
	for (int r = 1; r <= head.mu; r++) {
		head.rhead[r] = nullptr;
		x = head.rhead[r];
		for (int c = 1; c <= head.nu; c++) {
			ELemType e = productAtPos(headA, headB, r, c);
			if (e != 0) {
				OLink t = new OLNode;
				t->e = e;
				t->i = c;
				t->j = r;
				t->right = head.rhead[r];
				t->down = head.chead[c];
				if (head.rhead[r] == nullptr) {
					head.rhead[r] = t;
					head.rhead[r]->right = head.rhead[r];
					x = head.rhead[r];
				}
				else {
					x->right = t;
					x = t;
				}
				if (head.chead[c] == nullptr) {
					head.chead[c] = x;
					head.chead[c]->down = head.chead[c];
					y[c] = head.chead[c];
				}
				else {
					y[c]->down = x;
					y[c] = x;
				}
				head.tu++;
			}
		}
	}
	delete[] y;
	
	return head;
}

ELemType productAtPos(CrossList headA, CrossList headB, int row, int col) {
	ELemType e = 0;
	
	OLink x = headA.rhead[row];
	if (x == nullptr) {
		return e;
	}
	OLink y = headB.chead[col];
	if (y == nullptr) {
		return e;
	}
	
	while (true) {
		if (x->i > y->j) {
			y = y->down;
			if (y == headB.chead[col]) {
				break;
			}
		}
		else if (x->i < y->j) {
			x = x->right;
			if (x == headA.rhead[row]) {
				break;
			}
		}
		else {
			e += x->e*y->e;
			x = x->right;
			y = y->down;
			if (x == headA.rhead[row] || y == headB.chead[col]) {
				break;
			}
		}
	}
	
	return e;
}

CrossList malloc_crosslist_matrix(int **a, int row, int col) {
	CrossList head;
	head.mu = row;
	head.nu = col;
	head.tu = 0;
	head.rhead = new OLink[head.mu + 1];
	head.chead = new OLink[head.nu + 1];
	OLink* y = new OLink[head.nu + 1];
	for (int c = 1; c <= head.nu; c++) {
		head.chead[c] = nullptr;
		y[c] = head.chead[c];
	}
	OLink x = nullptr;
	for (int r = 1; r <= head.mu; r++) {
		head.rhead[r] = nullptr;
		x = head.rhead[r];
		for (int c = 1; c <= head.nu; c++) {
			if (a[r - 1][c - 1] != 0) {
				OLink t = new OLNode;
				t->e = a[r - 1][c - 1];
				t->i = c;
				t->j = r;
				t->right = head.rhead[r];
				t->down = head.chead[c];
				if (head.rhead[r] == nullptr) {
					head.rhead[r] = t;
					head.rhead[r]->right = head.rhead[r];
					x = head.rhead[r];
				}
				else {
					x->right = t;
					x = t;
				}
				if (head.chead[c] == nullptr) {
					head.chead[c] = x;
					head.chead[c]->down = head.chead[c];
					y[c] = head.chead[c];
				}
				else {
					y[c]->down = x;
					y[c] = x;
				}
				head.tu++;
			}
		}
	}
	delete[] y;
	
	return head;
}

void release_crosslist_matrix(CrossList head) {
	OLink p, q;
	for (int r = 1; r <= head.mu; r++) {
		p = head.rhead[r];
		while (p != nullptr && p != p->right) {
			q = p->right;
			p->right = q->right;
			delete q;
			q = nullptr;
		}
		delete p;
		p = nullptr;
	}
	delete[] head.rhead;
	delete[] head.chead;
	head.rhead = nullptr;
	head.chead = nullptr;
	head.mu = 0;
	head.nu = 0;
	head.tu = 0;
}

void print_crosslist_matrix(CrossList head) {
	for (int r = 1; r <= head.mu; r++) {
		int pre = 1;
		OLink x = head.rhead[r];
		if (x != nullptr) {
			do  {
				while (pre < x->i) {
					cout << "   0 ";
					pre++;
				}
				pre++;
				cout << setw(4) << x->e << " ";
				x = x->right;
			} while (x != head.rhead[r]);
		}
		while (pre <= head.nu) {
			cout << "   0 ";
			pre++;
		}
		cout << endl;
	}
	
	cout << endl;
	
	for (int c = 1; c <= head.nu; c++) {
		int pre = 1;
		OLink x = head.chead[c];
		if (x != nullptr) {
			do  {
				while (pre < x->j) {
					cout << "   0 ";
					pre++;
				}
				pre++;
				cout << setw(4) << x->e << " ";
				x = x->down;
			} while (x != head.chead[c]);
		}
		while (pre <= head.mu) {
			cout << "   0 ";
			pre++;
		}
		cout << endl;
	}
}

void create_sparse_matrix(int **a, int row, int col) {
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			if (rand()%10 == 0) {
				a[y][x] = rand()%100;
			}
			else {
				a[y][x] = 0;
			}
		}
	}
}

void print_matrix(int **a, int row, int col) {
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			cout << setw(4) << a[y][x] << " ";
		}
		cout << endl;
	}
}

int** malloc2d(int row, int col) {
	int **matrix = new int*[row];
	for (int y = 0; y < row; y++) {
		matrix[y] = new int[col];
	}
	return matrix;
}

void release2d(int** matrix, int row) {
	for (int y = 0; y < row; y++) {
		delete[] matrix[y];
	}
	delete[] matrix;
}

/*
   0    0    0    0   72    0    0    0    0   65    0    0    0    0    0    0   12    0    0    0 
   0   33    0    0    0    0    0    0    0    0   33    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0   24    0    3    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0   57    0    0    0    0    0    6 
   0    0    0    0    0    0    0    0    0    0    0   31    0    0    0   40    0    0    0    0 
   0    0    0    0    0    0    5    0    0    0    0   38    0   44    0    0    0    0    0    0 
   0   50    0    0    0    0    0    0    0    0    0    0    0    0   44    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0   62    0    0 

   0    0    0    0   72    0    0    0    0   65    0    0    0    0    0    0   12    0    0    0 
   0   33    0    0    0    0    0    0    0    0   33    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0   24    0    3    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0   57    0    0    0    0    0    6 
   0    0    0    0    0    0    0    0    0    0    0   31    0    0    0   40    0    0    0    0 
   0    0    0    0    0    0    5    0    0    0    0   38    0   44    0    0    0    0    0    0 
   0   50    0    0    0    0    0    0    0    0    0    0    0    0   44    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0   62    0    0 

   0    0    0    0    0    0    0    0    0    0 
   0   33    0    0    0    0    0    0   50    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
  72    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    5    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
  65    0    0    0    0    0    0    0    0    0 
   0   33   24    0    0    0    0    0    0    0 
   0    0    0    0    0    0   31   38    0    0 
   0    0    3    0    0    0    0    0    0    0 
   0    0    0    0    0   57    0   44    0    0 
   0    0    0    0    0    0    0    0   44    0 
   0    0    0    0    0    0   40    0    0    0 
  12    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0   62 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    6    0    0    0    0 

   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0   94    0    0    0    0    0 
   0    0   55    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0   29    0    0   37    0    0 
   0   56    0    0    0    0   50    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0   66 
  44   85    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0   62    0 
   0    0    0    0    0    0    0    0   54   15 
   0   30    0    0    0    0   26    0    0    0 
   0    0   54    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0   24    0    0    0    0 
  50    0    3   20    0    0    0    0   34   79 
   0    0    0    0    0    0   79    0   40    0 
  71    0    0    0    0   21    0    0    0    0 
   0    0    0   98    0    3    0    0    0   18 
   0    0    0   25    0    0    0    0    0   24 

   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0   94    0    0    0    0    0 
   0    0   55    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0   29    0    0   37    0    0 
   0   56    0    0    0    0   50    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0   66 
  44   85    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0   62    0 
   0    0    0    0    0    0    0    0   54   15 
   0   30    0    0    0    0   26    0    0    0 
   0    0   54    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0   24    0    0    0    0 
  50    0    3   20    0    0    0    0   34   79 
   0    0    0    0    0    0   79    0   40    0 
  71    0    0    0    0   21    0    0    0    0 
   0    0    0   98    0    3    0    0    0   18 
   0    0    0   25    0    0    0    0    0   24 

   0    0    0    0    0    0    0    0   44    0    0    0    0    0    0   50    0   71    0    0 
   0    0    0    0    0   56    0    0   85    0    0   30    0    0    0    0    0    0    0    0 
   0    0   55    0    0    0    0    0    0    0    0    0   54    0    0    3    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0   20    0    0   98   25 
   0   94    0    0   29    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0   24    0    0   21    3    0 
   0    0    0    0    0   50    0    0    0    0    0   26    0    0    0    0   79    0    0    0 
   0    0    0    0   37    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0   62   54    0    0    0    0   34   40    0    0    0 
   0    0    0    0    0    0    0   66    0    0   15    0    0    0    0   79    0    0   18   24 

   0    0    0    0 2088    0  948 2664 4510    0 
   0    0    0    0 3102    0    0    0 1782  495 
   0    0  162    0    0    0    0    0 1296  360 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0 
   0    0    0  150    0    0    0    0    0  144 
2000  930  120  800    0    0  806    0 1360 3160 
   0 1140    0    0    0    0  988    0    0    0 
   0    0    0    0 4700 1056    0    0    0    0 
4402    0    0    0    0 1302    0    0    0    0 

   0    0    0    0    0    0 2000    0    0 4402 
   0    0    0    0    0    0  930 1140    0    0 
   0    0  162    0    0    0  120    0    0    0 
   0    0    0    0    0  150  800    0    0    0 
2088 3102    0    0    0    0    0    0 4700    0 
   0    0    0    0    0    0    0    0 1056 1302 
 948    0    0    0    0    0  806  988    0    0 
2664    0    0    0    0    0    0    0    0    0 
4510 1782 1296    0    0    0 1360    0    0    0 
   0  495  360    0    0  144 3160    0    0    0 
*/
