/*
3.14 The C++ standard library includes the Vector data type as an
alternative to arrays. Find out how to use this data type on your system, and
determine the effect on the runtime when you replace the array in Program 3.5
by a Vector.
*/

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void sieve_of_Eratosthenes(long long N);
void sieve_of_Eratosthenes_vector(long long N);

int main() {
	sieve_of_Eratosthenes(1000000);
	sieve_of_Eratosthenes_vector(1000000);
}

void sieve_of_Eratosthenes(long long N) {
	steady_clock::time_point t1 = steady_clock::now();
	int *a = new int[N];
	long long i, j;
	for (i = 2; i < N; i++)
		a[i] = 1;
	for (i = 2; i < N; i++)
		if (a[i])
			for (j = i; j*i < N; j++)
				a[i*j] = 0;
	int cnt = 0;
	for (i = 2; i < N; i++)
		if (a[i])
			cnt++;
	delete [] a;
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "N = " << N << " cnt = " << cnt << " " 
		<< time_span.count() << " seconds." << endl;
}

void sieve_of_Eratosthenes_vector(long long N) {
	steady_clock::time_point t1 = steady_clock::now();
	vector<int> a(N, 1);
	long long i, j;
	for (i = 2; i < N; i++)
		if (a[i])
			for (j = i; j*i < N; j++)
				a[i*j] = 0;
	int cnt = 0;
	for (i = 2; i < N; i++)
		if (a[i])
			cnt++;
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "N = " << N << " cnt = " << cnt << " " 
		<< time_span.count() << " seconds.(vector)" << endl;
}

/*
N = 1000000 cnt = 78498 0.0247628 seconds.
N = 1000000 cnt = 78498 0.0291029 seconds.(vector)
*/
