#pragma once
#include <iostream>
using namespace std;

#include "Person.h";

typedef Person ItemType;
const int max_size = 100;

class List {
private:
	ItemType items[max_size];
	int size;

public:
	List();

	//Add a new contact
	bool add(ItemType item);

	//Remove a contact
	bool remove(string number);

	//Search for a phone number
	ItemType search(string name);

	//List phone numbers
	void display();
};
