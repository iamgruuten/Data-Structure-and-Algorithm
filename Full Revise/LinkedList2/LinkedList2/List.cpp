#include <iostream>

#include "List.h"

using namespace std;

List::List() : firstNode(NULL), size(0) {}

List::~List(){

	if (!isEmpty()) {
		while (firstNode->next != NULL)
		{
			Node* tempNode = firstNode;
			firstNode = firstNode->next;
			delete tempNode;
		}
	}
}


bool List::add(ItemType item) {

	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	if (!isEmpty()) {

		Node* tempNode = firstNode;

		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
	}
	else {
		firstNode = newNode;
	}
	size++;
	return true;
}

bool List::add(int index, ItemType item) {

	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	if (index > 0 && index < size) {

		Node* tempNode = firstNode;
		//1 , 2 , 3 , 4, 5
		//
		for (int i = 0; i < index-1; i++)
		{
			tempNode = tempNode->next;
		}
		newNode->next = tempNode->next;
		tempNode->next = newNode;
		size++;
		return true;
	}
	else {
		return false;
	}


}

void List::remove(int index) {
	if (index > 0 && index < size) {

		Node* tempNode = firstNode;
		//1 , 2 , 3 , 4, 5
		//
		for (int i = 0; i < index-1; i++)
		{
			tempNode = tempNode->next;
		}
		Node* deleteNode = tempNode->next;

		if (tempNode->next->next != NULL) {
			tempNode->next = tempNode->next->next;
		}
		else {
			tempNode->next = NULL;
		}
		delete deleteNode;

		size--;
	}
}

ItemType List::get(int index) {
	Node* tempNode = firstNode;
	//1 , 2 , 3 , 4, 5
	for (int i = 0; i <= index; i++)
	{
		tempNode = tempNode->next;
	}
	return tempNode->item;
}

bool List::isEmpty() {
	return size == 0;
}

int List::getLength() {
	return size;
}

void List::print() {
	Node* tempNode = firstNode;
	for (int i = 0; i < size; i++)
	{
		cout << tempNode->item << " ";
		tempNode = tempNode->next;
	}

	cout << endl;
}

void List::replace(int index, ItemType item) {

	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (index > 0 && index < size) {

		Node* tempNode = firstNode;
		//1 , 2 , 3 , 4, 5
		
		for (int i = 0; i < index; i++)
		{
			tempNode = tempNode->next;
		}

		newNode->next = tempNode->next->next;
		tempNode->next = newNode;

	}
}

int List::search(ItemType item) {
	Node* tempNode = firstNode;
	int count= 0;

	while (tempNode->next != NULL)
	{
		count++;
		if (tempNode->item == item) {
			cout << "located at " << count;
		}
		tempNode = tempNode->next;
	}

	return count;
}