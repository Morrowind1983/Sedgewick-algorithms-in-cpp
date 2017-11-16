/*
3.61 Write an efficient program that finds the length of the longest sequence of
blanks in a given string, examining as few characters in the string as possible.
Hint: Your program should become faster as the length of the sequence of blanks
increases.
*/

#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

static const int N = 5000000;

void create_random_string(char *s, int len);
int find_longest_blank_slow(char *s, int len);
int find_longest_blank_1(char *s, int len);
int find_longest_blank_2(char *s, int len);

int main() {
	char a[N];
	create_random_string(a, N);

	steady_clock::time_point t1 = steady_clock::now();
	int n = find_longest_blank_slow(a, N);
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "longest = " << n << " (slow)" << 
		time_span.count() << " seconds." << endl;
	
	t1 = steady_clock::now();
	n = find_longest_blank_1(a, N);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "longest = " << n << " (v1.0)" << 
		time_span.count() << " seconds." << endl;

	t1 = steady_clock::now();
	n = find_longest_blank_2(a, N);
	t2 = steady_clock::now();
	time_span = duration_cast< duration<double> >(t2 - t1);
	cout << "longest = " << n << " (v2.0)" <<
		time_span.count() << " seconds." << endl;
	
	return 0;
}

void create_random_string(char *s, int len) {
	random_device rd;
	mt19937 random_number_engine(rd());
	uniform_int_distribution<> dis(32, 90);
	
	int space = 0;
	for (int i = 0; i < len; i++) {
		if (space > 0) {
			s[i] = ' ';
			uniform_int_distribution<> space_dis(0, space++);
			if (space_dis(random_number_engine) == 0) {
				space = 0;
			}
		}
		else {
			s[i] = dis(random_number_engine);
			if (s[i] == ' ') {
				space = 3;
			}
		}
	}
}

int find_longest_blank_slow(char *s, int len) {
	int max = 0;
	int c = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			c++;
		}
		else {
			if (c > max) {
				max = c;
			}
			c = 0;
		}
	}
	if (c > max) {
		max = c;
	}
	return max;
}

int find_longest_blank_1(char *s, int len) {
	int max = 0;
	int i, j, k;
	for (i = 0; i < len; i++) {
		if (s[i] == ' ') {
			j = i + max;
			if (j < len && s[j] == ' ') {
				k = 1;
				while (i + k < len && s[i + k] == ' ') {
					k++;
				}
				if (k > max) {
					max = k;
				}
				else {
					i += k;
				}
			}
			else {
				i = j;
			}
		}
	}
	return max;
}

int find_longest_blank_2(char *s, int len) {
	int max = 0;
	int i, j, k;
	for (i = 0; i < len; i++) {
		if (s[i] == ' ') {
			j = i + max;
			if (j < len && s[j] == ' ') {
				k = j - 1;
				while (s[k] == ' ') {
					k--;
				}
				if (k < i) {
					k = j + 1;
					while (k < len && s[k] == ' ') {
						k++;
					}
					max = k - i;
				}
				i = k;
			}
			else {
				i = j;
			}
		}
	}
	return max;
}

/*
longest = 273824 (slow)0.0144673 seconds.
longest = 273824 (v1.0)0.00345227 seconds.
longest = 273824 (v2.0)0.0026825 seconds.
*/


