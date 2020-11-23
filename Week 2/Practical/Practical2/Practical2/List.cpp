#include <iostream>

#include "List.h"

typedef Person ItemType;

List::List() { size = 0; }

// add an item to the back of the list
bool List::add(ItemType item) {
	
	bool success = size < max_size;
	if (success)
	{
		items[size] = item;    
		size++;                
	}
	return success;
}

// Remove a contact
bool List::remove(string number) {
	for (int i = 0; i < size; i++)
	{
		if (items[i].getTelNo() == number) {
			for (int pos = i; pos < size; pos++) {
				items[pos] = items[pos + 1];
			}
			size--;  // decrease the size by 1
			return true;
		}
	}

	return false;
}

//search a contact
ItemType List::search(string name) {
	for (int i = 0; i < size; i++)
	{
		if (items[i].getName() == name) {
			return items[i];
		}
	}

	return Person("0", "0");
}

//List of phone numbers
void List::display() {

	cout << "-------------List of Contacts-----------" << endl;
	cout << "Name, Contact" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << items[i].getName() << ", " << items[i].getTelNo() << endl;

	}
}