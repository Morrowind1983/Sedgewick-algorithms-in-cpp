/*
4.20 Implement a compiler and interpreter for a programming language where
each program consists of a single arithmetic expression preceded by a sequence
of assignment statements with arithmetic expressions involving integers and
variables named with single lower-case characters.

For example, given the input

(x = 1)
(y = (x + 1))
(((x + y) * 3) + (4 * x))

your program should print the value 13.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <map>
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

template<typename T>
string numToString(const T& t){
    ostringstream oss;
    oss << t;
    return oss.str();
}

typedef float Item;

string infix_to_postfix_conversion(string str, map<string, Item> &vars);
Item value_of_postfix_expression(string str);

int main() {
	map<string, Item> vars;
	while (true) {
		string expression;
		getline(cin, expression);
		if (expression.empty()) {
			break;
		}
		string infix = infix_to_postfix_conversion(expression, vars);
		if (!infix.empty()) {
			Item value = value_of_postfix_expression(infix);
			cout << value << endl;
		}
	}
	return 0;
}

string infix_to_postfix_conversion(string str, map<string, Item> &vars) {
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
	string name = "";
	Stack<char> ops;
	for (int i = 0; i < len; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') 
		|| (str[i] >= 'A' && str[i] <= 'Z')) {
			name = "";
			while ((str[i] >= 'a' && str[i] <= 'z') 
			|| (str[i] >= 'A' && str[i] <= 'Z') 
			|| (str[i] >= '0' && str[i] <= '9')) {
				name = name + str[i++];
			}
			i--;
			map<string, Item>::iterator iter = vars.find(name);
			if (iter != vars.end()) {
				out = out + numToString(iter->second) + " ";
			}
			flag = 0;
		}
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
			if (flag == 2) {
				out += ops.pop();
			}
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
				out = out + str[i++];
			}
			i--;
			out += " ";
			flag = 0;
		}
		else if (str[i] == '(') {
			ops.push(str[i]);
			flag = 1;
		}
		else if (str[i] == ')') {
			while (true) {
				char op = ops.pop();
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
				if (ops.empty()) {
					break;
				}
				char last_op = ops.top();
				if (last_op == '(' 
				|| precedence[str[i]] > precedence[last_op]) {
					break;
				}
				else {
					out = out + ops.pop() + " ";
				}
			}
			ops.push(str[i]);
			if (str[i] == '-' && flag == 1) {
				flag = 2;
			}
			else {
				flag = 0;
			}
		}
		else if (str[i] == '=') {
			if (!name.empty()) {
				str = str.substr(i + 1, str.length() - i - 2);
				string infix = infix_to_postfix_conversion(str, vars);
				if (!infix.empty()) {
					vars[name] = value_of_postfix_expression(infix);
				}
				return "";
			}
		}
	}
	
	return out;
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

/*
x=1
y=x+1
(x+y)*3+4*x
13
/*
