// List.cpp - Implementation of List ADT using Pointers
#include "List.h"	// List header

// constructor
List::List()
{
	firstNode = NULL;
	size = 0;
}  

// add an item to the back of the list (append)
bool List::add(ItemType item)
{
   // create a new node to store the item
   Node *newNode = new Node;
   newNode->item = item;
   newNode->next = NULL;

   if ( isEmpty() )
	   firstNode = newNode;
   else
   {
	Node *temp = firstNode;
        while (temp->next != NULL)
		temp = temp->next;		// move to last node
		temp->next = newNode;		// make last node point to the new node
   }
   size++;
   
   return true;  // no size constraint
}  

// add an item at a specified position in the list (insert)
bool List::add(int index, ItemType item)
{
   bool success = (index >= 0) && (index <= size+1);

   if (success)
   {
	// create a new node to store the item
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
		
	if (index == 0) // inserting in front
	{
		newNode->next = firstNode;
		firstNode = newNode;
	}
	else
	{
		Node *temp = firstNode;
		for (int i=0; i<index-1; i++)
			temp = temp->next;	// move to node at the position before the index

		newNode->next = temp->next;	// make new node point to the node pointed to by temp
			temp->next = newNode;		// make temp point to the new node
	}
	size++;
   }

   return success;
}  

ItemType List::getMiddle()
{

}

ItemType List::getMiddleR()
{  

}

// check if the list is empty
bool List::isEmpty() { return size == 0; }  

// check the size of the list
int List::getLength() { return size; }  

