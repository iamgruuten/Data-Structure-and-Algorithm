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

	if (size != 0) {
		Node* current = firstNode;

		for (size_t i = 1; i < size; i++)
		{
			current = current->next;
		}

		current->next = node;
		node->next = NULL;
	}
	else {
		firstNode = node;
		firstNode->next = NULL;
	}

	size += 1;

	return true;
}

bool List::add(int index, ItemType item) {
	Node* current = firstNode;

	if (index == 1) {
		Node* node = new Node;
		node->item = item;
		node->next = current;

		firstNode = node;

		size += 1;

	}
	else if (size >= index) {
		index -= 1;

		for (size_t i = 1; i < index; i++)
		{
			current = current->next;
		}

		Node* node = new Node;
		node->item = item;

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
	else if(size >= index) {
		index -= 1;

		Node* current = new Node;
		Node* current2 = new Node;

		current = firstNode;

		for (size_t i = 1; i < index; i++)
		{
			current = current->next;
		}
		current2 = current->next;

		current->next = current2->next;
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
	if (size > index) {
		Node* current = firstNode;
		Node* current2;

		for (size_t i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		current2 = current->next;

		Node* node = new Node;
		current->next = node;
		node->next = current2->next;
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