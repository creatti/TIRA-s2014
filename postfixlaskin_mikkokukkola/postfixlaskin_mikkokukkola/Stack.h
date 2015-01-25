#pragma once
#include <iostream>
#include "Utility.h"

using namespace std;

const int maxstack = 10; // small value for testing
typedef double Stack_entry;

class Stack {
public:
	Stack();
	bool empty() const;
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Error_code push(const Stack_entry &item);
	char get_command();
	bool do_command(char, Stack &numbers);

	void introduction();
	void instructions();

	void sum(Stack &numbers);			// kolmen pisteen työvaihe
	void average(Stack &numbers);		// neljän pisteen työvaihe
	void new_interface(Stack &numbers);
private:
	int count;
	Stack_entry entry[maxstack];
};