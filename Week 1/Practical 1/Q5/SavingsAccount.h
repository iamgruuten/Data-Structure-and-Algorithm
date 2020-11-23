#pragma once

#include <iostream>
#include "Account.h"
using namespace std;

class SavingsAccount : public Account {
private:
	double interestRate;

public:
	SavingsAccount(double, double);
	double calculateInterest();
};