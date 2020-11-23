#include<string>
#include<iostream>
#include "Queue.h"
#include <ctime>
#include <cstdlib>

#include "Customer.h"

#include <string.h>

using namespace std;


void addCustomer(Queue& r, int& Qnum);

int main() {

	Queue r; 
	r.~Queue();
	srand(time(0));
	int simuatlion = 0;
	//0 - No Customers
	//1 - 1 Customer
	//2 - 2 Customer
	int noOfCus = 0;

	//Simulation time 10 minutes

	while (simuatlion != 10)
	{
		//Simulation every 1
		simuatlion += 1;
		ItemType item;

		if (!r.isEmpty()) {
			r.dequeue(item);
			cout << "Customer " << item.getName() << " was served in " << to_string(simuatlion - item.getQueueNum()) << " Min(s)" << endl;
			
		} // Initialize random number generator.

		int k = (rand() % 3) + 1;
		if (k == 1) {
			noOfCus += 1;
			addCustomer(r, simuatlion);
		}
		else if (k == 2) {
			noOfCus += 2;

			//Add two customer
			addCustomer(r, simuatlion);

			addCustomer(r, simuatlion);
		}

	}

	cout << "In this 10-min period, the average time to be served = " << double(noOfCus) / 10.0 << " mins";
}


void addCustomer(Queue& r, int& Qnum) {
	//Add one customer
	cout << "Enter Customer name: ";
	ItemType customer;
	string name;
	getline(cin, name);
	customer.setName(name);
	customer.setQueueNum(Qnum);
	r.enqueue(customer);

}