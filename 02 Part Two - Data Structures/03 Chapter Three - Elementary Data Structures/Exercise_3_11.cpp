/*
3.11 Modify our implementation of the sieve of Eratosthenes (Program 3.5) to
use an array of (i) chars; and (ii) bits. Determine the effects of these changes
on the amount of space and time used by the program.
*/

#include <iostream>
#include <bitset>
#include <chrono>
using namespace std;
using namespace std::chrono;

static const int N = 10000;

void sieve_of_Eratosthenes_int();
void sieve_of_Eratosthenes_char();
void sieve_of_Eratosthenes_bits();

int main() {
	sieve_of_Eratosthenes_int();
	sieve_of_Eratosthenes_char();
	sieve_of_Eratosthenes_bits();
}

void sieve_of_Eratosthenes_int() {
	steady_clock::time_point t1 = steady_clock::now();
	int a[N];
	int i, j;
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
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "sieve of Eratosthenes int " 
		<< time_span.count() << " seconds." << endl;
}

void sieve_of_Eratosthenes_char() {
	steady_clock::time_point t1 = steady_clock::now();
	char a[N];
	int i, j;
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
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "sieve of Eratosthenes char " 
		<< time_span.count() << " seconds." << endl;
}

void sieve_of_Eratosthenes_bits() {
	steady_clock::time_point t1 = steady_clock::now();
	bitset<N> a;
	int i, j;
	for (i = 2; i < N; i++)
		if (!a[i])
			for (j = i; i*j < N; j++)
				a[i*j] = 1;
	steady_clock::time_point t2 = steady_clock::now();
	for (i = 2; i < N; i++)
		if (!a[i])
			cout << i << " ";
	cout << endl;
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "sieve of Eratosthenes bits " 
		<< time_span.count() << " seconds." << endl;
}

/*
N = 10000
sieve of Eratosthenes int 0.000131774 seconds.
sieve of Eratosthenes char 0.00011416 seconds.
sieve of Eratosthenes bits 0.000359006 seconds.

N = 40000
sieve of Eratosthenes int 0.000583843 seconds.
sieve of Eratosthenes char 0.00050612 seconds.
sieve of Eratosthenes bits 0.00159683 seconds.
*/
