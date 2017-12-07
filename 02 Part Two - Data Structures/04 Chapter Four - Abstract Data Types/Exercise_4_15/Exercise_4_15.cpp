/*
4.14 Extend Programs 4.5 and 4.6 to include the - (subtract) and / (divide)
operations. 

4.15 Extend your solution to Exercise 4.14 to include the unary operators -
(negation) and $ (square root). Also, modify the abstract stack machine in
Program 4.5 to use floating point.

For example, given the expression
(-(-1) + $((-1) * (-1)-(4 * (-1))))/2
your program should print the value 1.618034.

4.19 Combine Program 4.5 and Program 4.6 into a single module that uses two
different stack ADTs: a stack of integers and a stack of operators.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "Stack.cpp"
using namespace std;

template <class Type>  
Type stringToNum(const string& str) {  
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;      
}

typedef float Item;

Item value_of_postfix_expression(string str);
string infix_to_postfix_conversion(string str);

int main(int argc, char *argv[]) {
	string input = argv[1];
	string infix = infix_to_postfix_conversion(input);
	cout << infix << endl;
	cout << value_of_postfix_expression(infix) << endl;
}

Item value_of_postfix_expression(string str) {
	int len = str.length();
	Stack<Item> stack;
	for (int i = 0; i < len; i++) {
		if (str[i] == '+') {
			stack.push(stack.pop() + stack.pop());
		}
		else if (str[i] == '*') {
			stack.push(stack.pop() * stack.pop());
		}
		else if (str[i] == '-') {
			Item y = stack.pop();
			Item x = stack.pop();
			stack.push(x - y);
		}
		else if (str[i] == '/') {
			Item y = stack.pop();
			Item x = stack.pop();
			stack.push(x/y);
		}
		else if (str[i] == '$') {
			stack.push(sqrt(stack.pop()));
		}
		else if (str[i] == '_') {
			stack.push(-stack.pop());
		}
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
			string num = "";
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				num = num + str[i++];
			}
			i--;
			stack.push(stringToNum<Item>(num));
		}
	}
	return stack.pop();
}

string infix_to_postfix_conversion(string str) {
	string out = "";
	
	int len = str.length();
	Stack<char> stack;
	bool single = false;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			single = true;
		}
		else if (str[i] == ')') {
			out = out + stack.pop() + " ";
		}
		else if (str[i] == '+' || str[i] == '*' 
		|| str[i] == '/' || str[i] == '$') {
			stack.push(str[i]);
		}
		else if (str[i] == '-') {
			if (single) {
				stack.push('_');
			}
			else {
				stack.push(str[i]);
			}
		}
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				out = out + str[i++];
			}
			i--;
			out += " ";
			single = false;
		}
	}
	
	return out;
}
