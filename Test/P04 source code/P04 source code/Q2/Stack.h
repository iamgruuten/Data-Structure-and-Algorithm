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
	Stack();	// constructor
	~Stack();    	// destructor
	bool push(ItemType item);
	void getTop(ItemType& item);
	bool isEmpty();
	void displayInOrder();
};

