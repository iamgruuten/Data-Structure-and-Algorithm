#pragma once

#include<string>
#include<iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() : frontNode(NULL), backNode(NULL){}

Queue::~Queue() {
	//Deconstructor of Queue
}

bool Queue::enqueue(ItemType item) {
	Node* node = new Node;
	
	node->item = item;
	node->next = NULL;

	if (isEmpty()) {
		frontNode = node;
	}
	else {
		backNode->next = node;
	}

	backNode = node;
	return true;
}


bool Queue::dequeue() {
	if (frontNode == backNode) {
		frontNode = NULL;
		backNode = NULL;
	}
	else {
		Node* temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
	}
	return true;

}

bool Queue::dequeue(ItemType& item) {
	item = frontNode->item;
	dequeue();
	return true;
}

void Queue::getFront(ItemType& item) {
	item = frontNode->item;
}

bool Queue::isEmpty() {
	if (frontNode == NULL) {
		return true;
	}

	return false;
}