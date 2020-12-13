#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() : frontNode(NULL), backNode(NULL) {}

Queue::~Queue() {

}

//First in, First Out
// 1 2 3 4 5 6 7 8
bool Queue::enqueue(ItemType item) {

	Node* node = new Node();
	node->item = item;
	node->next = NULL;
	if (!isEmpty()) {
		backNode->next = node;
		backNode = node;
	}
	else {
		frontNode = node;
		backNode = node;

	}
	return true;
}

bool Queue::dequeue() {
	Node* tempNode = frontNode;

	if (!isEmpty()) {
		if (frontNode != backNode) {
			frontNode = frontNode->next;
			delete tempNode;
		}
		else {
			delete tempNode;
			frontNode = NULL;
		}
		return true;
	}
	else {
		return false;
	}
}

bool Queue::dequeue(ItemType& item) {
	if (!isEmpty()) {
		getFront(item);
		dequeue();
		return true;
	}
	else {
		return false;
	}
}

void Queue::getFront(ItemType& item) {
	item = frontNode->item;
}

bool Queue::isEmpty() {
	return frontNode == NULL && backNode == NULL;
}