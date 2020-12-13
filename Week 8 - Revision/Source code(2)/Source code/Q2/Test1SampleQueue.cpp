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

}

void nextCustomer(Queue& serviceQueue)
{
	//to be implemented
	

}

void displayCount(Queue& serviceQueue)
{

	//to be implemented
}

int main()
{
	Queue serviceQueue;
	int queueNumber = 0;
	registerCustomer(serviceQueue, queueNumber);
	
	nextCustomer(serviceQueue);
	

	displayCount(serviceQueue);



}

