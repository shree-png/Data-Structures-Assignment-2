#include "Stack.h"
#include <string>
#include <vector>
#include <iostream>
//the top of the stack is printed last; the stack is 
// printed bottom to top.

int main() {
	try {
		cout << "Creating a stack object." << endl;
		vector<int> mystack = createStack();

		cout << endl;
		cout << "Stack is empty?: " << stackEmpty(mystack) << endl;
		cout << endl;

		cout << "Adding 4 onto stack" << endl;
		addValue(mystack, 4);
		cout << "Adding 2 onto stack" << endl;
		addValue(mystack, 2); 
		cout << "Adding 1 onto stack" << endl;
		addValue(mystack, 1); 
		cout << "Adding 18 onto stack" << endl;
		addValue(mystack, 18);
		cout << "Adding 11 onto stack" << endl;
		addValue(mystack, 11);

		cout << endl;
		printStack(mystack);
		cout << endl;

		cout << "Removing an element from stack" << endl;
		removeValue(mystack);
		cout << endl;

		printStack(mystack);
		cout << endl;

		cout << "Stack is empty?: " << stackEmpty(mystack) << endl;

		cout << endl;
		cout << "Top of stack: " << topOfStack(mystack) << endl;

		cout << endl;
		cout << "Average value of stack elements: " << findAverage(mystack) << endl;
		
		return 0;
	}

	catch (const std::runtime_error& e) {
		cout << e.what() << endl;
	}
}