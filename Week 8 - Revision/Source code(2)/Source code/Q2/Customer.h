#pragma once
#include <string>
#include <iostream>

using namespace std;
class Customer
{
private:
	int queueNumber;
	string name;

public:
	Customer();
	Customer(int q, string n);
	void setQueueNumber(int q);
	int getQueueNumber();
	void setName(string n);
	string getName();
	void print();
};
