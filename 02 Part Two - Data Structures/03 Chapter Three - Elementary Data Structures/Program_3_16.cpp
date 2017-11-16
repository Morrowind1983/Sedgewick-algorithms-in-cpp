/*
Program 3.16. Two-dimensional array allocation

This function dynamically allocates the memory for a two-dimensional array, as an
array of arrays. We first allocate an array of pointers, then allocate memory for
each row. With this function, the statement
int **a = malloc2d(M, N);
allocates an M-by-N array of integers.
*/

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

int main() {
	int **a = malloc2d(10, 10);
	release2d(a, 10);
	return 0;
}
