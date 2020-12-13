#include <iostream>

#include "Stack.h"
//Last in, First out approach

Stack::Stack() :topNode(NULL) {};

Stack::~Stack() {
	Node* temp = topNode;
	while (temp != NULL) {
		topNode = topNode->next;
		delete temp;
		temp = topNode;
	}
}

bool Stack::isEmpty() {
	return topNode == NULL;
}

bool Stack::push(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (!isEmpty()) {
		Node* tempNode = topNode;
		newNode->next = tempNode;

		topNode = newNode;
	}
	else {
		topNode = newNode;
	}

	return true;
}

bool Stack::pop() {
	if (!isEmpty()) {
		Node* del = topNode;

		if (topNode->next != NULL) {
			topNode = topNode->next;
			delete del;
		}
		else {
			topNode = NULL;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::pop(ItemType& item) {

	if (!isEmpty()) {
		item = topNode->item;
		Node* del = topNode;
		
		if (topNode->next != NULL) {
			topNode = topNode->next;
			delete del;
		}
		else {
			topNode = NULL;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::getTop(ItemType& item) {
	if(!isEmpty())
		item = topNode->item;
}

void Stack::displayInOrder() {

	if (!isEmpty()) {
		Node* tempNode = topNode;

		while (tempNode->next != NULL)
		{
			cout << tempNode->item << " ";
			tempNode = tempNode->next;
		}
		cout << endl;
	}
}

void Stack::displayInOrderOfInsertion() {
	Stack reverseStack;
	Node* tempNode = topNode;
	while (tempNode->next != NULL)
	{
		reverseStack.push(tempNode->item);
		tempNode = tempNode->next;
	}

	reverseStack.displayInOrder();
}