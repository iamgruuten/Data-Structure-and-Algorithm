// Stack.h - Specification of Stack (Array-based)
#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
typedef int ItemType;

class Stack
{
private:
	ItemType items[MAX_SIZE];
	int top;

public:
	Stack();	      // constructor
	~Stack();    // destructor

	bool isEmpty();
	bool push(ItemType item);
	bool pop();
	bool pop(ItemType &item);
	void getTop(ItemType &item);
	void displayInOrder();
	void displayInOrderOfInsertion();
};


