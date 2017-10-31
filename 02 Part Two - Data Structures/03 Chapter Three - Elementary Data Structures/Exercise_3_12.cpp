/*
3.12 Use the sieve of Eratosthenes to determine the number of primes less
than N, for N = 10^3, 10^4, 10^5, and 10^6.
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void sieve_of_Eratosthenes(long long N);

int main() {
	sieve_of_Eratosthenes(1000);
	sieve_of_Eratosthenes(10000);
	sieve_of_Eratosthenes(100000);
	sieve_of_Eratosthenes(1000000);
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
	steady_clock::time_point t2 = steady_clock::now();
	for (i = 2; i < N; i++)
		if (a[i])
			cout << i << " ";
	cout << endl;
	delete [] a;
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "N = " << N << " " << time_span.count() << " seconds." << endl;
}

/*
N = 1000 1.8408e-05 seconds.
N = 10000 0.000168698 seconds.
N = 100000 0.00197903 seconds.
N = 1000000 0.0216504 seconds.
*/
