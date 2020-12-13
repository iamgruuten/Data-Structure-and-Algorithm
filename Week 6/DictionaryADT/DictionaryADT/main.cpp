#include <iostream>
#include "Dictionary.h"

using namespace std;

void addEntry(KeyType, ItemType, Dictionary*);

int main() {
	Dictionary dic;

	//Adding entries of people
	addEntry("Pamela", "64606722", &dic);
	addEntry("PohSeng", "64608687", &dic);
	addEntry("Wesley", "64607237", &dic);
	addEntry("WeeChong", "64606854", &dic);
	cout << endl;

	dic.print();

	cout << endl;

	addEntry("Eugene", "64608256", &dic);
	addEntry("Saiful", "64608206", &dic);
	cout << endl;
	dic.print();

	dic.remove("Eugene");
	cout << endl << "Removed Eugene" << endl;

	cout << endl;
	dic.print();
}

void addEntry(KeyType name, ItemType phone, Dictionary* dic) {

	bool success = dic->add(name, phone);
	if (!success) {
		cout << "Failed to add " << name << endl;
	}
	else {
		cout << "Added " << name << endl;
	}
}