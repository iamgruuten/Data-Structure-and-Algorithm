#pragma once

#include <iostream>
 
using namespace std;

class Account {
private: 
	double balance;


public:
	Account(double);

	virtual void credit();
	virtual void credit(double);

	virtual void debit();
	double getBalance();
};
