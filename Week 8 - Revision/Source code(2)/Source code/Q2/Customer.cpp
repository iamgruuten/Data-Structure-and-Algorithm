#include "Customer.h"

Customer::Customer()
{
	setQueueNumber(0);
	setName("");
}

Customer::Customer(int q, string n)
{
	setQueueNumber(q);
	setName(n);

}

int Customer::getQueueNumber()
{
	return queueNumber;
}

void Customer::setQueueNumber(int q)
{
	queueNumber = q;
}

string Customer::getName()
{
	return name;
}

void Customer::setName(string n)
{
	name = n;
}

void Customer::print()
{
	cout << "Queue no: " << getQueueNumber() << "\nCustomer name: " << getName() << endl;
}