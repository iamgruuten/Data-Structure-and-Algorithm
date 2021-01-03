#include "List.h"
List::List() : size(0), firstNode(NULL) {}

List::~List() {
	Node* temp = firstNode;
	while (temp != NULL) {
		firstNode = firstNode->next;
		delete temp;
		temp = firstNode;
	}
	size = 0;
}

bool List::add(ItemType item) {
	Node* node = new Node;
	node->item = item;
	node->next = NULL;

	if (size != 0) {
		Node* current = firstNode;

		for (size_t i = 1; i < size; i++)
		{
			current = current->next;
		}

		current->next = node;
	}
	else {
		firstNode = node;
	}

	size += 1;

	return true;
}

bool List::add(int index, ItemType item) {
	Node* current = firstNode;

	Node* node = new Node;
	node->item = item;

	if (index == 0) {

		firstNode = node;
		node->next = current;

		size += 1;

	}
	else if (size > index) {

		for (int i = 1; i < index; i++)
		{
			current = current->next;
		}

		node->next = current->next;

		current->next = node;

		size += 1;
		return true;
	}
	else {
		return false;
	}
}

void List::remove(int index)
{
	if (index == 1) {
		firstNode = firstNode->next;
		size -= 1;

	}
	else if (size > index) {

		Node* current = new Node;

		current = firstNode;

		for (int i = 1; i < index; i++)
		{
			current = current->next;
		}

		current->next = current->next->next;

		size -= 1;

	}
}

ItemType List::get(int index) {
	Node* current = firstNode;

	for (size_t i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current->item;
}

bool List::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int List::getLength()
{
	return size;
}

void List::print() {
	Node* current = firstNode;
	for (size_t i = 0; i < size; i++)
	{
		cout << current->item << endl;
		current = current->next;
	}
}

void List::replace(int index, ItemType item)
{
	Node* node = new Node;
	node->item = item;

	if (size > index) {
		Node* current = firstNode;

		for (size_t i = 1; i < index; i++)
		{
			current = current->next;
		}

		node->next = current->next->next;
		current->next = node;

	}
}

int List::search(ItemType item) {
	Node* current = firstNode;
	int count = 0;

	while (current->item != item) {
		current = current->next;
		count += 1;
	}

	return count;
}

void List::reverseR() {
	reverseR2(firstNode);
}


List::Node* List::reverseR2(Node* current) {
	if (current == NULL) {
		return NULL;
	}
	if (current->next == NULL) {
		firstNode = current;
		return current;
	}

	Node* node = reverseR2(current->next);
	node->next = current;
	current->next = NULL;
	return current;
	
}
