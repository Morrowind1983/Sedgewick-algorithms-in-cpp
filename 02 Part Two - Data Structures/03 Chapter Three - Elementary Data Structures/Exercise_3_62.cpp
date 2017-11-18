/*
3.62 Write a version of Program 3.16 that handles three-dimensional arrays.
*/

int*** malloc3d(int xvol, int yvol, int zvol) {
	int ***matrix = new int**[zvol];
	for (int z = 0; z < zvol; z++) {
		matrix[z] = new int*[yvol];
		for (int y = 0; y < yvol; y++) {
			matrix[z][y] = new int[xvol];
		}
	}
	return matrix;
}

void release3d(int*** matrix, int yvol, int zvol) {
	for (int z = 0; z < zvol; z++) {
		for (int y = 0; y < yvol; y++) {
			delete[] matrix[z][y];
		}
		delete[] matrix[z];
	}
	delete[] matrix;
}

int main() {
	int ***a = malloc3d(10, 10, 10);
	release3d(a, 10, 10);
	return 0;
}
