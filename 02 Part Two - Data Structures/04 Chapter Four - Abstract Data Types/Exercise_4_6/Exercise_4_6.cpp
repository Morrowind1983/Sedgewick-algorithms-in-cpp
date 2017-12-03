/*
4.6 Give a class definition for Item that overloads the == operator to support
equality testing among floating-point numbers. Consider two floating-point
numbers to be equal if the absolute value of their difference divided by the
larger (in absolute value) of the two numbers is less than 10–6
*/

#include <iostream>
#include "Item.h"
using namespace std;

int main() {
	float x = 23.432;
	float y = 23.4321;
	cout << (x==y) << endl;

	return 0;
}
