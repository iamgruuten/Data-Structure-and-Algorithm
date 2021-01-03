// List.h - Specification of List ADT
#pragma once
#include<string>
#include<iostream>
using namespace std;
typedef int ItemType;
struct Node
{
	ItemType item;	// data item
	Node* next;	// pointer pointing to next item
};
class List
{
private:
	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:

	// constructor
	List();

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(ItemType item);

	// add an item at a specified position in the list (insert)
	// pre : 1 <= index <= size+1
	// post: item is added to the specified position in the list
	//       items after the position are shifted back by 1 position
	//       size of list is increased by 1
	bool add(int index, ItemType item);

	ItemType getMiddle();

	ItemType getMiddleR();

	ItemType getMiddleR2(Node* tempNode, int count);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

};
