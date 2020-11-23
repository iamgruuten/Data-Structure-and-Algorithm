#pragma once

#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(double balance) : balance(balance) {
	if (balance < 0) {
		cout << "Invalid initial balance" << endl;

		balance = 0;
	}

	this->balance = balance;
};

	void Account::credit() {
		cout << "Please enter the amount to deposit: ";

		double depositAmount;
		cin >> depositAmount;

		this->balance += depositAmount;
	}

	void Account::credit(double amt) {
		this->balance += amt;
	}

	void Account::debit() {
		cout << "Please enter the amount to withdraw: ";

		double withdrawAmount;
		cin >> withdrawAmount;

		if (withdrawAmount < this->balance) {
			this->balance -= withdrawAmount;
		}
		else {
			cout << "Debit Amount exceeded account balance";
		}
	}

	double Account::getBalance() {
		return this->balance;
	}