#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> createStack() { //tested
	vector<int> the_stack;
	return the_stack;
}

bool stackEmpty(const vector<int>& stack) { //tested
	return stack.empty();
}

void addValue(vector<int>& stack, int value) { //tested
	stack.push_back(value);
}

void removeValue(vector<int>& stack) { //tested
	if (stack.empty())
		throw std::runtime_error("ERROR: empty stack-- cannot remove value");
	stack.pop_back();
}

int topOfStack(const vector<int>& stack) { //tested
	if (stack.empty())
		throw std::runtime_error("ERROR: empty stack-- cannot return top value");
	return stack.back();
}

float findAverage(const vector<int>& stack) { //tested
	if (stack.empty())
		return 0; //or should I just return a message / throw an exception?
	int total = 0;
	for (size_t i = 0; i < stack.size(); i++) {
		total += stack.at(i);
	}
	return static_cast<float>(total) / stack.size();
}

void printStack(const vector<int>& stack) { //tested
	cout << "Current Stack:" << endl;
	for (int i = 0; i < stack.size(); i++)
		cout << stack.at(i) << endl;
}