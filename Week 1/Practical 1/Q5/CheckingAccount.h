#pragma once

#include <iostream>
#include <string>

#include "Account.h"

using namespace std;

class CheckingAccount : public Account {
private:
	double fee;

public:
	CheckingAccount(double, double);
	virtual void credit();
	virtual void debit();
};