/*
3.15 Empirically determine the effect of removing the test of a[i] from the
inner loop of Program 3.5, for N = 10^3, 10^4, 10^5, and 10^6, and explain the
effect that you observe.
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void sieve_of_Eratosthenes(long long N);
void sieve_of_Eratosthenes_slow(long long N);

int main() {
	sieve_of_Eratosthenes(1000);
	sieve_of_Eratosthenes_slow(1000);
	
	sieve_of_Eratosthenes(10000);
	sieve_of_Eratosthenes_slow(10000);
	
	sieve_of_Eratosthenes(100000);
	sieve_of_Eratosthenes_slow(100000);
	
	sieve_of_Eratosthenes(1000000);
	sieve_of_Eratosthenes_slow(1000000);
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

void sieve_of_Eratosthenes_slow(long long N) {
	steady_clock::time_point t1 = steady_clock::now();
	int *a = new int[N];
	long long i, j;
	for (i = 2; i < N; i++)
		a[i] = 1;
	for (i = 2; i < N; i++)
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
		<< time_span.count() << " seconds.(slow)" << endl;
}

/*
N = 1000 cnt = 168 3.1332e-05 seconds.
N = 1000 cnt = 168 2.0444e-05 seconds.(slow)
N = 10000 cnt = 1229 0.000204638 seconds.
N = 10000 cnt = 1229 0.000267579 seconds.(slow)
N = 100000 cnt = 9592 0.0020864 seconds.
N = 100000 cnt = 9592 0.00335379 seconds.(slow)
N = 1000000 cnt = 78498 0.0242178 seconds.
N = 1000000 cnt = 78498 0.0610368 seconds.(slow)
*/
