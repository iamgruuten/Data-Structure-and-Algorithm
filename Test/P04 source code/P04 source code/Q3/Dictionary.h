// Dictionary.h - - Specification of Dictionary ADT

#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE = 7;
typedef string KeyType;
typedef int ItemType;

struct Node
{
	KeyType	 key;   // search key
	ItemType item;  // data item
	Node* next;	// pointer pointing to next item with same search key
};
class Dictionary
{
private:

	Node *items[MAX_SIZE];
	int  size;			// number of items in the Dictionary

public:

	// constructor
	Dictionary();

	int hash(KeyType key);

	// add a new item with the specified key to the Dictionary
	// pre : none
	// post: new item is added to the Dictionary
	//       size of Dictionary is increased by 1
	bool add(KeyType newKey, ItemType newItem);

	// check if the Dictionary is empty
	// pre : none
	// post: none
	// return true if the Dictionary is empty; otherwise returns false
	bool isEmpty();

	// check the size of the Dictionary
	// pre : none
	// post: none
	// return the number of items in the Dictionary
	int getLength();

	// prints the length of each chain
	void printChainLength();

};
