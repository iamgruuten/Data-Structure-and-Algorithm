#include "Dictionary.h"
#include <math.h>      

Dictionary::Dictionary() :size(0), items(){
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		items[i] = NULL;
	}
}

Dictionary::~Dictionary(){}


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
	int hash = 0;
	for (int i = 0; i < key.length(); i++) {
		hash += charvalue(key[i]);
	}

	return hash % MAX_SIZE;
}



bool Dictionary::add(KeyType newkey, ItemType newItem) {
	int index = hash(newkey);

	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->key = newkey;
	newNode->next = NULL;

	if (items[index] == NULL) {
		items[index] = newNode;
	}
	else {
		Node* currentNode = items[index];

		if (currentNode->key == newkey) {
			return false;
		}
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
			if (currentNode->key == newkey) {
				return false;
			}
		}
		currentNode->next = newNode;
	}
	size += 1;
	return true;
}

void Dictionary::remove(KeyType key) {
	int index = hash(key);

	if (items[index] != NULL) {
		Node* temp = items[index];

		while (temp->key != key) {
			temp = temp -> next;
		}
		
		if (temp->next == NULL) {
			items[index] = NULL;
		}
		delete temp;

		size -= 1;
	}
}

ItemType Dictionary::get(KeyType key) {
	int index = hash(key);

	if (items[index] != NULL) {
		Node* temp = items[index];
		while (temp->key != key) {
			temp = temp->next;
		}
		return temp->item;
	}
}

bool Dictionary::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}

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

	if (items[index] != NULL) {
		Node* temp = items[index];
		while (temp->key != key) {
			temp = temp->next;
		}
		
		temp->item = item;
	}
}


bool Dictionary::contains(KeyType key) {
	int index = hash(key);

	if (items[index] != NULL) {
		Node* temp = items[index];
		while (temp->next != NULL) {
			temp = temp -> next;
			if (temp->key == key) {
				return true;
			}
		}

		
	}
	return false;	
}





