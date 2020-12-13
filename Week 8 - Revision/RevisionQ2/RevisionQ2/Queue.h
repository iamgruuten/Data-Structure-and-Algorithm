#pragma once
// Queue.h - Specification of Queue ADT (Array-based)
// Circular Queue

#pragma once
#include <iostream>   	// for input/output
#include "Customer.h"
using namespace std;  	// for std C++ definitions

typedef Customer ItemType;

class Queue
{
private:
	struct Node
	{
		ItemType item;		// to store data
		Node* next;		// to point to next node
	};

	Node* frontNode;		// to point to the front node
	Node* backNode;			// to point to the back node

public:
	Queue();
	~Queue();

	// enqueue item at back of the queue
	bool enqueue(ItemType& item);

	// dequeue item from front of the queue
	bool dequeue();
	bool dequeue(ItemType& item);

	// retrieve item from front of queue
	//ItemType getFront();
	void getFront(ItemType& item);

	// check if the queue is empty
	bool isEmpty();

	// display the items in the queue
	void display();
};


