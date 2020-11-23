#include <iostream>
#include <string>

#include "List.h"

typedef Person ItemType;

using namespace std;

void initPhoneList(List& phoneList);
void displayMenu();
void listPhoneNumbers(List phoneList);
void addPhoneNumber(List& phoneList);
void delPhoneNumber(List& phoneList);
void search(List phoneList);

int main() {
	List phoneList;
	ItemType person;
	initPhoneList(phoneList);

	int option = 1;

	while (option != 0) {
		displayMenu();

		cout << "Enter your option : " << endl;
		cin >> option;

		switch (option) {
		case 0:
			cout << "Exiting";
			break;
		case 1:
			listPhoneNumbers(phoneList);
			break;	

		case 2:
			addPhoneNumber(phoneList);
			break;

		case 3:
			delPhoneNumber(phoneList);
			break;

		case 4:
			search(phoneList);
			break;
		default:
			cout << "Invalid Option";

		}
	}
}

void displayMenu() {
	cout << "------------ Main Menu ------------" << endl;
	cout << "[1] List the phone numbers" << endl;
	cout << "[2] Add a new contact" << endl;
	cout << "[3] Remove a contact" << endl;
	cout << "[4] Search for a phone number" << endl;
	cout << "[0] Exit" << endl;
	cout << "--------------------------------" << endl;
}

void initPhoneList(List& phoneList) {
	//Initilize One contact
	ItemType itemPerson("Jason", "81234567");
	phoneList.add(itemPerson);
}

void listPhoneNumbers(List phoneList) {
	phoneList.display();
}
void addPhoneNumber(List& phoneList) {
	string phone, name;
	cout << "Contact Name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Phone Number: ";
	cin.ignore();
	getline(cin, phone);

	ItemType personItem(name, phone);
	phoneList.add(personItem);

}
void delPhoneNumber(List& phoneList) {
	string phone;
	cout << "Enter phone number you want to delete: ";
	cin.ignore();
	getline(cin, phone);

	bool success = phoneList.remove(phone);

	if (success) {
		cout << "Successfully removed" << endl;
	}
	else {
		cout << "Failed to remove, No such contact" << endl;
	}
	
}

void search(List phoneList) {
	string name;
	cout << "Enter name you want to search for: ";
	cin.ignore();
	getline(cin, name);

	ItemType person(phoneList.search(name));

	if (person.getName() != "0") {
		cout << "Contact Number of " << person.getName() << " is " << person.getTelNo() << endl;
	}
	else {
		cout << "User not found" << endl;
	}
}