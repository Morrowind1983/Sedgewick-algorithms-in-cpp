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
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' 
		|| str[i] == '-') {
			string num = "";
			if (str[i] == '-') {
				num = "-";
				i++;
			}
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				num = num + str[i++];
			}
			i--;
			if (num != "-") {
				stack.push(stringToNum<Item>(num));
			}
		}
		
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
		else if (str[i] == '^') {
			Item y = stack.pop();
			Item x = stack.pop();
			stack.push(pow(x, y));
		}
		else if (str[i] == '$') {
			stack.push(sqrt(stack.pop()));
		}
	}
	return stack.pop();
}

string infix_to_postfix_conversion(string str) {
	int precedence[256] = {};
	precedence['^'] = 4;
	precedence['$'] = 4;
	precedence['*'] = 3;
	precedence['/'] = 3;
	precedence['+'] = 2;
	precedence['-'] = 2;
	
	string out = "";
	string left = "(";
	string right = ")";
	str = left + str + right;
	int len = str.length();
	int flag = 0;
	Stack<char> stack;
	for (int i = 0; i < len; i++) {
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
			if (flag == 2) {
				out += stack.pop();
			}
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				out = out + str[i++];
			}
			i--;
			out += " ";
			flag = 0;
		}
		else if (str[i] == '(') {
			stack.push(str[i]);
			flag = 1;
		}
		else if (str[i] == ')') {
			while (true) {
				char op = stack.pop();
				if (op == '(') {
					break;
				}
				out = out + op + " ";
			}
			flag = 0;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' 
		|| str[i] == '/' || str[i] == '^' || str[i] == '$') {
			while (true) {
				if (stack.empty()) {
					break;
				}
				char last_op = stack.top();
				if (last_op == '(' 
				|| precedence[str[i]] > precedence[last_op]) {
					break;
				}
				else {
					out = out + stack.pop() + " ";
				}
			}
			stack.push(str[i]);
			if (str[i] == '-' && flag == 1) {
				flag = 2;
			}
			else {
				flag = 0;
			}
		}
	}
	
	return out;
}

/*
"(-(-1) + \$((-1) * (-1)-(4 * (-1))))/2"
-1 - -1 -1 * 4 -1 * - $ + 2 / 
1.61803
*/
