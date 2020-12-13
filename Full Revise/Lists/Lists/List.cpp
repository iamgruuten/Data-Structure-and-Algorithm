#include<iostream>
#include "List.h"


using namespace std;

List::List() :size(0) {}

bool List::add(ItemType item) {
	if (size < MAX_SIZE) {
		items[size] = item;
		size++;
		return true;
	}
	else {
		return false;
	}
}

bool List::add(int index, ItemType item) {
	if (index < size && index > 0) {
		for (int i = index; i < size - 1; i++)
		{
			items[i + 1] = items[i];
		}

		items[index] = item;
		size++;
		return true;
	}
	else {
		cout << "Index out of range" << endl;
		return false;
	}
}

void List::remove(int index) {
	if (index < size && index > 0) {
		for (int i = index; i < size - 1; i++)
		{
			items[i] = items[i + 1];
		}
		size--;
	}
	else {
		cout << "Index out of range" << endl;
	}
}

bool List::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int List::getLength() {
	return size;
}

void List::print() {
	for (int i = 0; i < size; i++)
	{
		cout << items[i].getName() << ", " << items[i].getTelNo() << endl;
	}
}

void List::replace(int index, ItemType item) {
	if (index < size && index > 0) {
		items[index] = item;
	}
	else {
		cout << "Index out of range" << endl;
	}
}

ItemType List::search(string name) {
	for (int i = 0; i < size; i++)
	{
		if (items[i].getName() == name) {
			return items[i];
		}
	}

	return ItemType("0", "0");
}