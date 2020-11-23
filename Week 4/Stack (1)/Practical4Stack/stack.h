// Stack.h – Specification of Stack (Pointer-based implementation)
#pragma once
#include <iostream>
using namespace std;

typedef int ItemType;


class Stack
{
private:
	struct Node
	{
		ItemType item;   // to store data
		Node*     next;  // to point to next node
	};

	Node *topNode;

public:
	Stack();		// constructor
	~Stack();		// destructor
	bool push(ItemType item);
	bool pop();
	bool pop(ItemType &item);
	void getTop(ItemType &item);
	bool isEmpty();
	void displayInOrder();
	void displayInOrderOfInsertion();
};


