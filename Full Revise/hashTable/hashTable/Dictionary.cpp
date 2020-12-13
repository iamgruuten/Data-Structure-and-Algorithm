#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() : size(0), items() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		items[i] = NULL;
	}
}

Dictionary::~Dictionary() {

}

int charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int)'A';
		else
			return (int)c - (int)'a' + 26;
	}
	else
		return -1;
}

int Dictionary::hash(KeyType key) {
	int hashIndex = 0;
	for (int i = 0; i < key.size(); i++)
	{
		hashIndex = hashIndex + charvalue(key[i]);
	}

	hashIndex = hashIndex % MAX_SIZE;

	return hashIndex;
}

bool Dictionary::add(KeyType newKey, ItemType newItem) {
	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->key = newKey;
	newNode->next = NULL;
	int index = hash(newKey);

	if (items[index] == NULL) {
		items[index] = newNode;
		size++;
	}
	else {
		Node* tempNode = items[index];

		while (tempNode->next != NULL)
		{
			if (tempNode->key == newKey) {
				return false;
			}
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;

		return true;
	}
}

void Dictionary::remove(KeyType key) {
	int index = hash(key);

	if (items[index] == NULL) {
		cout << endl << "there is no such key" << endl;
	}
	else {
		Node* topNode = items[index];
		if (topNode->key == key) {
			//First index got removed
			Node* next = topNode->next;

			topNode->next = NULL;

			Node* temp = topNode;

			topNode = next;

			items[index] = topNode;

			delete temp;
		}
		else {

			// loop to the previous node of the target node which has the key
			while (topNode->next && topNode->next->key != key) {
				topNode = topNode->next;
			}

			// point the prev node to the next node of the target node
			// deallocate memory
			Node* temp = topNode->next;
			if (temp && temp->key == key) {
				topNode->next = topNode->next->next;
				temp->next = NULL;
				delete temp;
				
			}
			else {
				cout << endl << "there is no such key" << endl;
				return;
			}
		}

		size--;

	}

}

ItemType Dictionary::get(KeyType key) {
	int index = hash(key);

	if (items[index] == NULL) {
		cout << endl << "there is no such key" << endl;
	}
	else {
		Node* tempNode = items[index];
		while (tempNode != NULL) {
			if (tempNode->key == key) {
				return tempNode->item;
			}
			tempNode = tempNode->next;
		}

		cout << endl << "there is no such key" << endl;
	}
}

bool Dictionary::isEmpty() {
	return size == 0;
}

int Dictionary::getLength() {
	return size;
}

void Dictionary::print() {

	for (int i = 0; i < MAX_SIZE; i++)
	{

		if (items[i] != NULL) {
			Node* temp = new Node;
			temp = items[i];
			cout << temp->key << ", " << temp->item << endl;

			while (temp->next != NULL)
			{
				temp = temp->next;
				cout << temp->key << ", " << temp->item << endl;
			}
		}
	}
}

void Dictionary::replace(KeyType key, ItemType item) {
	int index = hash(key);

	if (items[index] == NULL) {
		cout << endl << "there is no such key" << endl;
	}
	else {

		Node* tempNode = items[index];
		while (tempNode != NULL) {
			if (tempNode->key == key) {
				//Replace if found
				tempNode->item = item;
				cout << "Replace Successfully" << endl;
				break;
			}

			tempNode = tempNode->next;
		}

		cout << endl << "there is no such key" << endl;
	}
}

bool Dictionary::contains(KeyType key) {
	int index = hash(key);

	if (items[index] == NULL) {
		return false;
	}
	else {
		Node* tempNode = items[index];
		while (tempNode != NULL) {
			if (tempNode->key == key) {
				//Replace if found
				return true;
				break;
			}

			tempNode = tempNode->next;
		}

		return false;
	}
}