// Dictionary.cpp - Implementation of Dictonary ADT using Hash Table with separate chaining

#include "Dictionary.h"	// firstNodeer file

// constructor
Dictionary::Dictionary()
{
	for (int i = 0; i < MAX_SIZE; i++)
		items[i] = NULL;
	size = 0;
}

// get the hash value for the given search key
int Dictionary::hash(KeyType key)
{
	return key.size() % MAX_SIZE;
}

// prints the length of each chain
void Dictionary::printChainLength()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (items[i] == NULL) {
			cout << "Pos " << i << "Size : " << "0" << endl;
		}
		else {
			int count = 0;
			Node* firstNode = items[i];
			while (firstNode != NULL) {
				count++;
				firstNode = firstNode->next;
			}
			cout << "Pos " << i << "Size : " << count << endl;
		}
	}
}

// add a new item with a specified key in the Dictionary
bool Dictionary::add(KeyType newKey, ItemType newItem)
{
	int index = hash(newKey);

	if (items[index] == NULL) // space is empty - start new list
	{
		items[index] = new Node;
		items[index]->key = newKey;
		items[index]->item = newItem;
		items[index]->next = NULL;
	}
	else // collision
	{
		Node* current = items[index];

		if (current->key == newKey) // duplicate key
			return false;

		while (current->next != NULL)
		{
			cout << current->key << endl;
			current = current->next;
			if (current->item == newItem) // duplicate key
				return false;
		}

		// Add new node to end of list
		Node* newNode = new Node;
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = NULL;
		current->next = newNode;
	}
	size++;
	return true;
}

// check if the Dictionary is empty
bool Dictionary::isEmpty()
{
	return size == 0;
}

// check the size of the Dictionary
int Dictionary::getLength()
{
	return size;
}
