#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void menu() {
	cout << "[1] List the phone numbers" << endl;
	cout << "[2] Add a new contact" << endl;
	cout << "[3] Remove a contact" << endl;
	cout << "[4] Search for a phone number" << endl;
	cout << "[0] Exit" << endl;
}
int main() {
	int opt = -1;
	List list;

	while (opt != 0) {
		menu();
		cout << "Enter your option:";
		cin >> opt;

		if (opt == 1) {
			list.print();
		}
		else if (opt == 2) {
			string name;
			string telNo;

			cout << "Enter name: ";
			cin.ignore();
			getline(cin, name);

			cout << endl << "Enter telNo: ";
			cin >> telNo;

			ItemType personItem(name, telNo);
			list.add(personItem);
		}
		else if (opt == 3) {
			list.print();

			int a;
			cout << "Remove name: ";
			cin >> a;
			list.remove(a);
		}
		else if (opt == 4) {
			string name;
			cout << "Enter name you want to search for: ";
			cin.ignore();
			getline(cin, name);

			ItemType person(list.search(name));

			if (person.getName() != "0") {
				cout << "Contact Number of " << person.getName() << " is " << person.getTelNo() << endl;
			}
			else {
				cout << "User not found" << endl;
			}
		}

	}
}