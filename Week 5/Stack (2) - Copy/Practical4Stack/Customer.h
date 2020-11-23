#pragma once
// Customer.h - Definition of Customer class

#include<string>
#include<iostream>
using namespace std;

class Customer
{
private:
	string name;
	int queueNum; // the i-th minute Customer joins queue.

public:
	Customer();
	Customer(string n, int q);
	void setName(string n);
	string getName();
	void setQueueNum(int q);
	int getQueueNum();
};
