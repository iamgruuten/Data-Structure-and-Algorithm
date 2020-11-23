#pragma once

#include <iostream>
#include "CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount(double balance, double fee) : Account(balance) {
	this->fee = fee;
}

void CheckingAccount::credit() {

	this-> getBalance() - this-> fee;
}

void CheckingAccount::debit() {

	this-> getBalance() - this-> fee;
}