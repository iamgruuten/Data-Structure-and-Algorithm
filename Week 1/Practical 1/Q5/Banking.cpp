#pragma once
//No Error checking has been implemented in the program
//Enter only 1 or 2 to the program only

#include <vector>
#include <iostream>
#include "CheckingAccount.h"
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main() {
	int choice, choice2;

	SavingsAccount sa1(1000, 1.5);
	CheckingAccount ca1(1000, 10);

	vector <Account*> accountVector;
	accountVector.push_back(&sa1);
	accountVector.push_back(&ca1);

	cout << "Please enter 1 for saving account or 2 for checking account: ";
	cin >> choice;

	cout << "Please enter 1 to deposit or 2 to withdraw: ";
	cin >> choice2;

	if (choice2 == 1) {
		Account* a = accountVector[choice - 1];
		cout << "Current Balance: " << a->getBalance() << endl;

		SavingsAccount* saPtr = dynamic_cast <SavingsAccount*>(a);
		if (saPtr != 0) {

			saPtr->credit();
			cout << "Total Interest: " << saPtr->calculateInterest() << endl;
			saPtr->credit(saPtr->calculateInterest());

		}
		else {
			CheckingAccount* caPtr = dynamic_cast <CheckingAccount*>(a);
			caPtr->credit();
		}
		cout << "Total Balance: " << a->getBalance();

	}
	else if (choice2 == 2) {
		Account* a = accountVector[choice - 1];
		cout << "Current Balance: " << a->getBalance() << endl;

		SavingsAccount* saPtr = dynamic_cast <SavingsAccount*>(a);
		if (saPtr != 0) {
			saPtr->debit();
			cout << "Total Interest: " << saPtr->calculateInterest() << endl;
			saPtr->credit(saPtr->calculateInterest());
		}
		else {
			CheckingAccount* caPtr = dynamic_cast <CheckingAccount*>(a);
			caPtr->debit();
		}
		cout << "Total Balance: "<< a->getBalance();

	}

}
