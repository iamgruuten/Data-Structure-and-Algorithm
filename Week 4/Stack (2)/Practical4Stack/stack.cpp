#include "stack.h"
Stack::Stack() : topNode(NULL) {}

Stack::~Stack(){
	Node* temp = topNode;
	while (temp != NULL) {
		topNode = topNode->next;
		delete temp;
		temp = topNode;
	}
}

bool Stack::push(ItemType item) {
	Node* node = new Node;

	node->item = item;

	if (!isEmpty()) {
		Node* pushNode = topNode;

		node->next = pushNode;
		topNode = node;
	}
	else {
		node->next = NULL;

		topNode = node;
	}

	return true;
}

bool Stack::pop() {
	if (!isEmpty()) {
		Node* tempNode = topNode;

		if (topNode->next != NULL)
		{
			topNode = topNode->next;

			tempNode->item = "";
		}
		else {
			topNode = NULL;
		}

		delete tempNode;

		return true;
	}
	else {
		return false;
	}
}

bool Stack::pop(ItemType& item) {

	if (!isEmpty()) {
		item = topNode->item;
		pop();

		return true;
	}

	return false;
}

void Stack::getTop(ItemType& item) {
	if (!isEmpty()) {
		item = topNode->item;
	}
}

bool Stack::isEmpty() {
	if (topNode == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void Stack::displayInOrder() {
	if (!isEmpty()) {
		Node* currentNode = topNode;

		while (currentNode != NULL)
		{
			cout << currentNode->item << " ";

			currentNode = currentNode->next;
		}

		cout << endl;
	}
}

void Stack::displayInOrderOfInsertion() {
	Stack reverse;

	if (!isEmpty()) {
		Node* currentNode = topNode;

		while (currentNode != NULL)
		{
			reverse.push(currentNode->item);

			currentNode = currentNode->next;
		}
	}

	if (!reverse.isEmpty()) {
		Node* currentNode = reverse.topNode;

		while (currentNode != NULL)
		{
			cout << currentNode->item << " ";

			currentNode = currentNode->next;
		}

		cout << endl;
	}
}