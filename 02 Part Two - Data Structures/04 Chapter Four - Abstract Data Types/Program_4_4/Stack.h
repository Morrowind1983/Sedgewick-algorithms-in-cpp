/*
Program 4.4. Pushdown-stack ADT interface

Using the same convention that we used in Program 4.3, we define a pushdown
stack ADT with public function declarations, assuming that the stack
representation and any other implementation-dependent code is kept private in
implementations, so that we can change implementations without changing client
code. Additionally, this interface uses a template to allow clients to use
stacks containing objects from any class (see Programs 4.5 and 4.6), and
implementations to use the keyword Item as the type of the objects on the stack
(see Programs 4.7 and 4.8). The argument to the STACK constructor specifies the
maximum number of elements expected on the stack.
*/

template <class Item>
class Stack {
private:
	Item* s;
	int N;
	int maxN;
public:
	Stack(int);
	bool empty() const;
	void push(Item item);
	Item pop();
};