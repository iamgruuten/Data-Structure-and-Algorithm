#pragma once

#include<string>
#include<iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() : tail(MAX_SIZE - 1), rear(0), count(0) {}

Queue::~Queue() {
	//Deconstructor of Queue
}

bool Queue::enqueue(ItemType item) {
	if (count == MAX_SIZE) {
		cout << "The Queue is Full. Please wait" << endl;
		return false;
	}
	else {
		tail = (tail + 1) % MAX_SIZE;
		queue[tail] = item;
		count++;
	}
	return true;
}


bool Queue::dequeue() {
	if (isEmpty()) {
		cout << "There is no queue" << endl;
		return false;
	}
	else {
		queue[rear] = "0";
		rear = (rear + 1) % MAX_SIZE;
		count--;

		return true;
	}

}

bool Queue::dequeue(ItemType& item) {
	if (isEmpty()) {
		cout << "There is no queue" << endl;
		return false;
	}
	else {
		item = queue[rear];
		queue[rear] = "0";
		rear = (rear + 1) % MAX_SIZE;

		count--;
		return true;
	}
}

void Queue::getFront(ItemType& item) {
	if (!isEmpty()) {
		item = queue[rear];
	}
	else {
		item = "0";
	}
}

bool Queue::isEmpty() {
	return count == 0;
}

bool Queue::isFull() {
	return (tail + 1) % MAX_SIZE == rear;
}

void Queue::displayItems() {
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		cout << queue[i] << " ";
	}
	cout << endl;
}
