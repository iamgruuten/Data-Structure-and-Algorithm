// Test1SampleQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;

void registerCustomer(Queue& serviceQueue, int& queueNumber)
{
	//to be implemented
	string name;
	cout << "Please enter your name: ";
	cin >> name;
	Customer newCust;
	newCust.setName(name);
	newCust.setQueueNumber(queueNumber);

	serviceQueue.enqueue(newCust);
	queueNumber += 1;


}

void nextCustomer(Queue& serviceQueue)
{
	//to be implemented
	Customer cust;
	serviceQueue.getFront(cust);
	cout << endl << cust.getQueueNumber();

	serviceQueue.dequeue();

}

void displayCount(Queue& serviceQueue)
{

	//to be implemented
	Queue tempQueue;
	int count = 0;
	Customer cust;

	while (serviceQueue.dequeue(cust) != false) {
		count = count + 1;
		tempQueue.enqueue(cust);
	}

	cout << "Number in the Queue : " << count;
	serviceQueue = tempQueue;
}

int main()
{
	Queue serviceQueue;
	int queueNumber = 0;
	registerCustomer(serviceQueue, queueNumber);
	registerCustomer(serviceQueue, queueNumber);
	registerCustomer(serviceQueue, queueNumber);
	registerCustomer(serviceQueue, queueNumber);
	registerCustomer(serviceQueue, queueNumber);

	displayCount(serviceQueue);


	nextCustomer(serviceQueue);
	nextCustomer(serviceQueue);
	nextCustomer(serviceQueue);
	nextCustomer(serviceQueue);
	nextCustomer(serviceQueue);






}

