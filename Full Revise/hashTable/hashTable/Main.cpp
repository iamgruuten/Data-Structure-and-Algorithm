#include <iostream>
#include "Dictionary.h"

using namespace std;

void addEntry(KeyType, ItemType, Dictionary*);
void replaceEntry(KeyType name, ItemType phone, Dictionary* dic);

int main() {
	Dictionary dic;

	//Adding entries of people
	addEntry("bull", "64606722", &dic);
	addEntry("llub", "64608687", &dic);
	addEntry("lulb", "64607237", &dic);
	addEntry("WeeChong", "64606854", &dic);
	cout << endl;

	dic.print();

	cout << endl;

	addEntry("bull", "64608256", &dic);
	addEntry("llub", "64608206", &dic);
	cout << endl;
	dic.print();

	if (dic.contains("lulb")) {
		cout << "lulb is in your contact" << endl;
	}

	dic.remove("lulb");
	cout << endl << "Removed lulb" << endl;

	cout << endl;
	dic.print();

	dic.replace("lulb", "9992322");
	dic.replace("bull", "9992322");
	dic.replace("llub", "9992322");
	dic.print();

	dic.remove("lulb");
	dic.remove("bull");
	dic.remove("llub");
	dic.print();


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